// Fill out your copyright notice in the Description page of Project Settings.

#include "MechScriptController.h"


void AMechScriptController::Tick(float DeltaSeconds)
{
	PollControllers();

	//if (IsValid(GetPawn()))
	//{
	//	DoLocomotion(DeltaSeconds);
	//	GetAimDirection(DeltaSeconds);
	//}
}

void AMechScriptController::BeginPlay()
{
	PrimaryActorTick.bCanEverTick = true;
}

void AMechScriptController::PollControllers()
{
 	GetInputAnalogStickState(EControllerAnalogStick::Type::CAS_LeftStick, moveInput.Y, moveInput.X);
	GetInputAnalogStickState(EControllerAnalogStick::Type::CAS_RightStick, aimInput.X, aimInput.Y);
}
//
//void AMechScriptController::DoLocomotion(float DeltaSeconds)
//{	
//	InputToVelocity(DeltaSeconds);
//	//GetWalkDirection(DeltaSeconds);
//	//DecaySpeed(DeltaSeconds);
//	
//	//GetPawn()->AddMovementInput(walkDirection * speed * DeltaSeconds, true);
//	//GetPawn()->AddActorWorldOffset(GetPawn()->ConsumeMovementInputVector(), true);
//
//	//FVector velocityThisFrame = walkDirection * speed;
//	//
//	//GetPawn()->AddActorWorldOffset(velocityThisFrame * DeltaSeconds, true);
//	//UCapsuleComponent* cap = (UCapsuleComponent*)GetPawn()->GetComponentByClass(TSubclassOf<UCapsuleComponent>());
//	//
//	//GEngine->AddOnScreenDebugMessage(
//	//	22,
//	//	1.0f,   // Duration of message - limits distance messages scroll onto screen
//	//	FColor::Magenta.WithAlpha(128),   // Color and transparancy!
//	//	FString::Printf(TEXT("offset with velocity %s"), *velocityThisFrame.ToString())  // Our usual text message format
//	//);
//	//if(cap != nullptr)
//	//{
//	//	GEngine->AddOnScreenDebugMessage(
//	//		23,
//	//		1.0f,   // Duration of message - limits distance messages scroll onto screen
//	//		FColor::Magenta.WithAlpha(128),   // Color and transparancy!
//	//		FString::Printf(TEXT("moving physics!"))  // Our usual text message format
//	//	);
//	//	cap->AddForce(walkDirection * speed * 100000);
//	//}
//
//	//walkRotation = walkDirection.Rotation();
//}
//
//void AMechScriptController::InputToVelocity(float DeltaSeconds)
//{
//	//The desired velocity is the direction the player is inputting 
//	desiredVelocity = m_leftStickInput.GetClampedToSize(0.0f, 1.0f);
//
//	//FVector currentVelocity = GetPawn()->GetVelocity();
//	//
//	//if ((desiredVelocity.Size() > 0.0f) && (m_state != LocomotionState::stopping))
//	//{
//	//	//Save the last direction the player input for animation purposes 
//	//	m_lastDirInput = desiredVelocity;
//	//
//	//	//Desired delta velocity is the difference between where they are inputting to go and where they're currently moving
//	//	m_desiredDeltaVelocity = (desiredVelocity - currentVelocity);
//	//}
//	//else
//	//{
//	//	m_desiredDeltaVelocity = (-currentVelocity);
//	//}
//	//
//	//GEngine->AddOnScreenDebugMessage(
//	//	22,
//	//	1.0f,   // Duration of message - limits distance messages scroll onto screen
//	//	FColor::Magenta.WithAlpha(128),   // Color and transparancy!
//	//	FString::Printf(TEXT("Vel: %s"), *currentVelocity.ToString())  // Our usual text message format
//	//);
//	//
//	//speed = currentVelocity.Size();
//	//
//	//if (speed > 0)
//	//{
//	//	//This dot product will be <0 if the vectors are opposite, which means the player wants to turn
//	//	velocityDotProduct = FVector().DotProduct(currentVelocity, desiredVelocity);
//	//
//	//	if (velocityDotProduct < -0.5f)
//	//		m_state = LocomotionState::stopping;
//	//
//	//	if ((m_state == LocomotionState::stopping) && (speed <= (speedMax / 20.0f)))
//	//		m_state = LocomotionState::turning;
//	//}
//}
//
//void AMechScriptController::GetWalkDirection(float DeltaSeconds)
//{
//	if (m_state == LocomotionState::walking)
//	{
//		FVector vel = GetPawn()->GetVelocity();
//
//		if(!vel.IsNearlyZero(0.1))
//		{
//			walkDirection = vel.GetSafeNormal();
//		} else
//		{
//		//This is here so that when the player's velocity reaches 0, they will not snap to face up
//			walkDirection = m_lastDirInput.GetSafeNormal();
//		}
//	}
//
//	else if (m_state == LocomotionState::turning)
//	{	
//		m_turnAngle = FMath::RadiansToDegrees(acosf(walkDirection.CosineAngle2D(m_lastDirInput)));
//
//		if (m_turnAngle > 180.0f)
//		{
//			m_turnAngle = m_turnAngle;
//		}
//		//GEngine->AddOnScreenDebugMessage(
//		//	-1,        // don't over wrire previous message, add a new one
//		//	0.35f,   // Duration of message - limits distance messages scroll onto screen
//		//	FColor::Cyan.WithAlpha(64),   // Color and transparancy!
//		//	FString::Printf(TEXT("%f"), m_turnAngle)// Our usual text message format
//		//);
//
//		walkDirection = walkDirection.RotateAngleAxis(m_turnAngle * DeltaSeconds * m_pivotSpeed, FVector(0.0f, 0.0f, 1.0f));
//
//		//walkDirection.Normalize();
//
//		if (m_turnAngle < 5.0f)
//			m_state = LocomotionState::walking;
//	}
//}

//void AMechScriptController::DecaySpeed(float DeltaSeconds)
//{
//
//	//velocity /= (1 + (DeltaSeconds * m_exponentialDrag));
//	//
//	//if (speed > m_linearDrag)
//	//{
//	//	velocity.X = (FMath::Abs(velocity.X) - (m_linearDrag * DeltaSeconds)) * FMath::Sign(velocity.X);
//	//	velocity.Y = (FMath::Abs(velocity.Y) - (m_linearDrag * DeltaSeconds)) * FMath::Sign(velocity.Y);
//	//
//	//	if (m_state == LocomotionState::stopping)
//	//	{
//	//		velocity.X = (FMath::Abs(velocity.X) - (m_stopDrag * DeltaSeconds)) * FMath::Sign(velocity.X);
//	//		velocity.Y = (FMath::Abs(velocity.Y) - (m_stopDrag * DeltaSeconds)) * FMath::Sign(velocity.Y);
//	//	}
//	//}
//
//	//GEngine->AddOnScreenDebugMessage(
//	//	-1,        // don't over wrire previous message, add a new one
//	//	0.35f,   // Duration of message - limits distance messages scroll onto screen
//	//	FColor::Cyan.WithAlpha(64),   // Color and transparancy!
//	//	FString::Printf(TEXT("%f : %f"), velocity.X, velocity.Y)// Our usual text message format
//	//);
//}

//void AMechScriptController::GetAimDirection(float DeltaSeconds)
//{
//	if (aimInput.Size() > 0.0f)
//	{
//		aimTarget = aimInput.GetSafeNormal();
//	}	
//
//	float angle = aimTarget.CosineAngle2D(aimDirection);
//	
//	if (aimInput.Size() > 0.0f)
//	{
//		if (angle < 0.1f)
//			angle -= 1.0f;
//	}
//
//	//GEngine->AddOnScreenDebugMessage(
//	//	-1,        // don't over wrire previous message, add a new one
//	//	0.35f,   // Duration of message - limits distance messages scroll onto screen
//	//	FColor::Cyan.WithAlpha(64),   // Color and transparancy!
//	//	FString::Printf(TEXT("%f"), angle)// Our usual text message format
//	//);
//
//	if (FMath::Abs(angle) > 0.1f)
//	{
//		aimDirection = aimDirection.RotateAngleAxis(FMath::Sign(angle) * DeltaSeconds * turnSpeed, FVector(0.0f, 0.0f, -1.0f)).GetSafeNormal();
//	}
//}

//void AMechScriptController::SetupPlayerInputComponent()
//{
//	AActor theActor;
//}
