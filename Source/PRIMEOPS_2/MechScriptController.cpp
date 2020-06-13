// Fill out your copyright notice in the Description page of Project Settings.

#include "MechScriptController.h"
#include "SniperRifle.h"

void AMechScriptController::Tick(float DeltaSeconds)
{
	//PollControllers();

	if (IsValid(GetPawn()))
	{
		DoLocomotion(DeltaSeconds);

		GetAimDirection(DeltaSeconds);
	}
}

void AMechScriptController::BeginPlay()
{
	PrimaryActorTick.bCanEverTick = true;
}

//void AMechScriptController::PollControllers()
//{
// 	GetInputAnalogStickState(EControllerAnalogStick::Type::CAS_LeftStick, m_leftStickInput.Y, m_leftStickInput.X);
//	GetInputAnalogStickState(EControllerAnalogStick::Type::CAS_RightStick, m_rightStickInput.X, m_rightStickInput.Y);
//}

void AMechScriptController::SetLeftStickInput(FVector vec)
{
	m_leftStickInput = vec;
}

void AMechScriptController::SetRightStickInput(FVector vec)
{
	m_rightStickInput = vec;
}

void AMechScriptController::DoLocomotion(float DeltaSeconds)
{	
	InputToVelocity(DeltaSeconds);
	GetWalkDirection(DeltaSeconds);
	DecaySpeed(DeltaSeconds);

	GetPawn()->AddActorWorldOffset(walkDirection * speed * DeltaSeconds);

	walkRotation = walkDirection.Rotation();
}

void AMechScriptController::InputToVelocity(float DeltaSeconds)
{
	//The desired velocity is the direction the player is inputting 
	desiredVelocity = m_leftStickInput.GetClampedToSize(0.0f, 1.0f) * speedMax * DeltaSeconds;

	if ((desiredVelocity.Size() > 0.0f) && (m_state != LocomotionState::stopping))
	{
		//Save the last direction the player input for animation purposes 
		m_lastDirInput = desiredVelocity;

		//Desired delta velocity is the difference between where they are inputting to go and where they're currently moving
		m_desiredDeltaVelocity = desiredVelocity - velocity;

		//Add velocity in the input direction no greater than the max acceleration value
		velocity += m_desiredDeltaVelocity.GetClampedToMaxSize(m_accelerationMax * DeltaSeconds);
	}

	//Set Speed in real terms, not relative to time. 
	speed = velocity.Size() / DeltaSeconds;

	if (speed > 0)
	{
		//This dot product will be <0 if the vectors are opposite, which means the player wants to turn
		velocityDotProduct = FVector().DotProduct(velocity, desiredVelocity);

		if (velocityDotProduct < -1.0f)
			m_state = LocomotionState::stopping;

		if ((m_state == LocomotionState::stopping) && (speed <= (speedMax / 16.0f)))
			m_state = LocomotionState::turning;
	}
}

void AMechScriptController::GetWalkDirection(float DeltaSeconds)
{
	if (m_state == LocomotionState::walking)
	{
		if (velocity.Size() > 0.0f)
			walkDirection = velocity.GetSafeNormal();

		//This is here so that when the player's velocity reaches 0, they will not snap to face up
		else
			walkDirection = m_lastDirInput.GetSafeNormal();
	}

	else if (m_state == LocomotionState::turning)
	{	
		m_turnAngle = FMath::RadiansToDegrees(acosf(walkDirection.CosineAngle2D(m_lastDirInput)));

		if (m_turnAngle > 180.0f)
		{
			m_turnAngle = ((int)m_turnAngle % 180) * -1;
		}
		//GEngine->AddOnScreenDebugMessage(
		//	-1,        // don't over wrire previous message, add a new one
		//	0.35f,   // Duration of message - limits distance messages scroll onto screen
		//	FColor::Cyan.WithAlpha(64),   // Color and transparancy!
		//	FString::Printf(TEXT("%f"), m_turnAngle)// Our usual text message format
		//);

		walkDirection = walkDirection.RotateAngleAxis(m_turnAngle * DeltaSeconds * m_pivotSpeed, FVector(0.0f, 0.0f, 1.0f));

		//walkDirection.Normalize();

		if (m_turnAngle < 5.0f)
			m_state = LocomotionState::walking;
	}
}

void AMechScriptController::DecaySpeed(float DeltaSeconds)
{

	velocity /= (1 + (DeltaSeconds * m_exponentialDrag));

	if (speed > m_linearDrag)
	{
		velocity.X = (FMath::Abs(velocity.X) - (m_linearDrag * DeltaSeconds)) * FMath::Sign(velocity.X);
		velocity.Y = (FMath::Abs(velocity.Y) - (m_linearDrag * DeltaSeconds)) * FMath::Sign(velocity.Y);

		if (m_state == LocomotionState::stopping)
		{
			velocity.X = (FMath::Abs(velocity.X) - (m_stopDrag * DeltaSeconds)) * FMath::Sign(velocity.X);
			velocity.Y = (FMath::Abs(velocity.Y) - (m_stopDrag * DeltaSeconds)) * FMath::Sign(velocity.Y);
		}
	}

	//GEngine->AddOnScreenDebugMessage(
	//	-1,        // don't over wrire previous message, add a new one
	//	0.35f,   // Duration of message - limits distance messages scroll onto screen
	//	FColor::Cyan.WithAlpha(64),   // Color and transparancy!
	//	FString::Printf(TEXT("%f : %f"), velocity.X, velocity.Y)// Our usual text message format
	//);
}

void AMechScriptController::GetAimDirection(float DeltaSeconds)
{
	if (m_rightStickInput.Size() > 0.0f)
	{
		aimTarget = m_rightStickInput.GetSafeNormal();
	}	

	float angle = aimTarget.CosineAngle2D(aimDirection);
	
	if (m_rightStickInput.Size() > 0.0f)
	{
		if (angle < 0.1f)
			angle -= 1.0f;
	}

	//GEngine->AddOnScreenDebugMessage(
	//	-1,        // don't over wrire previous message, add a new one
	//	0.35f,   // Duration of message - limits distance messages scroll onto screen
	//	FColor::Cyan.WithAlpha(64),   // Color and transparancy!
	//	FString::Printf(TEXT("%f"), angle)// Our usual text message format
	//);

	if (FMath::Abs(angle) > 0.1f)
	{
		aimDirection = aimDirection.RotateAngleAxis(FMath::Sign(angle) * DeltaSeconds * turnSpeed, FVector(0.0f, 0.0f, -1.0f)).GetSafeNormal();
	}
}

void AMechScriptController::SetupPlayerInputComponent()
{
	AActor theActor;
}