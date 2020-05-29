// Fill out your copyright notice in the Description page of Project Settings.

#include "MechScriptController.h"
#include "Ability_Base.h"
#include "SniperRifle.h"

void AMechScriptController::Tick(float DeltaSeconds)
{
	PollControllers();

	if (IsValid(GetPawn()))
	{
		DoLocomotion(DeltaSeconds);

		GetAimDirection(DeltaSeconds);
	}
}

void AMechScriptController::BeginPlay()
{
	PrimaryActorTick.bCanEverTick = true;

	USniperRifle newRifle = USniperRifle();
	m_loadout[GearSlot::R_SHD] = &newRifle;

	newRifle.SetOwner(this);
}

void AMechScriptController::PollControllers()
{
	GetInputAnalogStickState(EControllerAnalogStick::Type::CAS_LeftStick, m_leftStickInput.Y, m_leftStickInput.X);
	GetInputAnalogStickState(EControllerAnalogStick::Type::CAS_RightStick, m_rightStickInput.X, m_rightStickInput.Y);
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

	if (desiredVelocity.Size() > 0.0f)
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

		if (velocityDotProduct < 0.0f)
			m_isTurning = true;
	}
}

void AMechScriptController::GetWalkDirection(float DeltaSeconds)
{
	if (!m_isTurning)
	{
		//This is here so that when the player's velocity reaches 0, they will not snap to face up
		if (velocity.Size() > 0.0f)
			walkDirection = velocity.GetSafeNormal();

		else
			walkDirection = m_lastDirInput.GetSafeNormal();
	}

	else
	{		
		m_turnAngle = FMath::RadiansToDegrees(acosf(walkDirection.CosineAngle2D(m_lastDirInput)));

		walkDirection = walkDirection.RotateAngleAxis(m_turnAngle * DeltaSeconds * m_pivotSpeed, FVector(0.0f, 0.0f, 1.0f));

		walkDirection.Normalize();

		if (m_turnAngle < 10.0f)
			m_isTurning = false;
	}
}

void AMechScriptController::DecaySpeed(float DeltaSeconds)
{

	velocity /= (1 + (DeltaSeconds * m_exponentialDrag));

	if (speed > m_linearDrag)
	{
		velocity.X = (FMath::Abs(velocity.X) - (m_linearDrag * DeltaSeconds)) * FMath::Sign(velocity.X);
		velocity.Y = (FMath::Abs(velocity.Y) - (m_linearDrag * DeltaSeconds)) * FMath::Sign(velocity.Y);
	}

	//GEngine->AddOnScreenDebugMessage(
	//	-1,        // don't over wrire previous message, add a new one
	//	0.35f,   // Duration of message - limits distance messages scroll onto screen
	//	FColor::Cyan.WithAlpha(64),   // Color and transparancy!
	//	FString::Printf(TEXT("%f : %f"), velocity.X, velocity.Y)// Our usual text message format
	//);
}

void AMechScriptController::GetAimTarget()
{
	//GEngine->AddOnScreenDebugMessage(
	//	-1,        // don't over wrire previous message, add a new one
	//	0.35f,   // Duration of message - limits distance messages scroll onto screen
	//	FColor::Cyan.WithAlpha(64),   // Color and transparancy!
	//	FString::Printf(TEXT("%f"), m_rightStickInput.Size())// Our usual text message format
	//);

	if (m_rightStickInput.Size() > 0.0f)
	{
		aimTarget = m_rightStickInput.GetSafeNormal();
	}
}

void AMechScriptController::GetAimDirection(float DeltaSeconds)
{
	GetAimTarget();

	float angle = aimTarget.CosineAngle2D(aimDirection);

	if (FMath::Abs(angle) > 0.1f)
	{
		aimDirection = aimDirection.RotateAngleAxis(FMath::Sign(angle) * DeltaSeconds * turnSpeed, FVector(0.0f, 0.0f, -1.0f)).GetSafeNormal();
	}
}


void AMechScriptController::AddHeat(float _heat)
{
	//float previousHeatPercentage = getHeatPercentage();

	//m_heat = max(m_heat + val, 0.0f);

	//float heatPercentage = getHeatPercentage();

	//// trigger an overheat
	//if (m_heat >= m_heatMax && !m_isOverheated)
	//{
	//	m_isOverheated = true;
	//	SoundSystem::getInstance()->PlaySoundOnce(Overheat, false, Alert);
	//} // issue an overheat warning when heat rises over the percentage-based warning threshold
	//else if (heatPercentage > m_heatWarningThreshold && previousHeatPercentage <= m_heatWarningThreshold)
	//{
	//	SoundSystem::getInstance()->PlaySoundOnce(Overheat_Warning, false, Alert);
	//}

	//// delay heat dissipation
	//m_heatDelayTimer.restart();
}

void AMechScriptController::FireRightShoulder()
{
	m_loadout[GearSlot::R_SHD]->Activate();
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("This is an on screen message!"));
}

void AMechScriptController::SetupInputComponent()
{
	InputComponent->BindAction("RightShoulder", IE_Pressed, this, &AMechScriptController::FireRightShoulder);
}