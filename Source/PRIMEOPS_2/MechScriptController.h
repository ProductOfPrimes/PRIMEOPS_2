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

	UFUNCTION(BlueprintCallable)
	float GetSpeed() { return speed; }

protected:

	FVector m_leftStickInput = FVector();
	FVector m_rightStickInput = FVector();

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Aiming)
	FVector aimDirection = FVector(0.0f, 0.0f, 0.0f);

	UPROPERTY(EditAnywhere, Category = Aiming)
	FVector aimTarget = FVector(0.0f, 0.0f, 0.0f);

	UPROPERTY(EditAnywhere, Category = Aiming)
	FRotator aimRotation;

	UPROPERTY(EditAnywhere, Category = Aiming)
	float turnSpeed = 145.0f;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Movement)
	float speed = 0.0f;

	UPROPERTY(EditAnywhere, Category = Movement)
	float speedMax = 7500.0f;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Movement)
	float velocityDotProduct = 0.0f;

	float m_pivotSpeed = 2.0f;
	float m_accelerationMax = 140.0f;
	float m_linearDrag = 50.0f;
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

	UPROPERTY(EditAnywhere, Category = Properties)
	float health = 100.0f;

	UPROPERTY(EditAnywhere, Category = Properties)
	float heat = 100.0f;

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	void PollControllers();
	void InputToVelocity(float DeltaSeconds);
	void GetWalkDirection(float DeltaSeconds);
	void DecaySpeed(float DeltaSeconds);

};
