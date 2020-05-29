// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine.h"
#include "GameFramework/PlayerController.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/Pawn.h"
#include "MechScriptController.generated.h"

/**
 * 
 */
UCLASS()
class PRIMEOPS_2_API AMechScriptController : public APlayerController
{
	GENERATED_BODY()
	
public:
	// Called every frame
	virtual void Tick(float DeltaSeconds) override;

	void AddHeat(float heat);

protected:

	FVector m_leftStickInput = FVector();
	FVector m_rightStickInput = FVector();

	//Torso Rotation Variables
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Aiming)
	FVector aimDirection = FVector(0.0f, 0.0f, 0.0f);

	UPROPERTY(EditAnywhere, Category = Aiming)
	FVector aimTarget = FVector(0.0f, 0.0f, 0.0f);

	UPROPERTY(EditAnywhere, Category = Aiming)
	FRotator aimRotation;

	UPROPERTY(EditAnywhere, Category = Aiming)
	float turnSpeed = 145.0f;

	//Locomotion Variables 
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Movement)
	float speed = 0.0f;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Movement)
	float speedMax = 7500.0f;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Movement)
	float velocityDotProduct = 0.0f;

	float m_pivotSpeed = 2.0f;
	float m_accelerationMax = 140.0f;
	float m_linearDrag = 20.0f;
	float m_exponentialDrag = 0.9f;
	float m_turnAngle = 0.0f;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Movement)
	FVector velocity = FVector(0.0f, 0.0f, 0.0f);

	UPROPERTY(EditAnywhere, Category = Movement)
	FVector desiredVelocity = FVector(0.0f, 0.0f, 0.0f);

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Movement)
	FVector walkDirection = FVector(0.0f, 0.0f, 0.0f);

	FVector m_lastDirInput = FVector(0.0f, 0.0f, 0.0f);
	FVector m_desiredDeltaVelocity = FVector(0.0f, 0.0f, 0.0f);

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Movement)
	FRotator walkRotation = FRotator(0.0f, 0.0f, 0.0f);

	bool m_isTurning = false;

	//Gameplay Property Variables
	UPROPERTY(EditAnywhere, Category = GameplayProperties)
	float health = 100.0f;
	UPROPERTY(EditAnywhere, Category = GameplayProperties)
	float maxHealth = 100.0f;

	UPROPERTY(EditAnywhere, Category = GameplayProperties)
	float heat = 0;
	UPROPERTY(EditAnywhere, Category = GameplayProperties)
	float maxHeat = 1.0;
	UPROPERTY(EditAnywhere, Category = GameplayProperties)
	float heatDrain = 0.0; // Reduce heat per second
	bool m_isOverHeated = false;
	float m_overheatThreshold = 0.5f; // After overheating, heat must dissipate below this before they can fire again
	const float m_heatWarningThreshold = 0.7f; // When heat over this value, warnings appear

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	void DoLocomotion(float DeltaSeconds);
	void PollControllers();
	void InputToVelocity(float DeltaSeconds);
	void GetWalkDirection(float DeltaSeconds);
	void DecaySpeed(float DeltaSeconds);

	void GetAimTarget();
	void GetAimDirection();
};