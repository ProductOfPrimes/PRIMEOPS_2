// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/PlayerController.h"
#include "CoreMinimal.h"
#include "Engine.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/Pawn.h"
#include "MechScriptController.generated.h"

/**
 * 
 */

//enum LocomotionState { walking, stopping, turning};

UCLASS()
class PRIMEOPS_2_API AMechScriptController : public APlayerController
{
	GENERATED_BODY()
	
public:
	// Called every frame
	virtual void Tick(float DeltaSeconds) override;

	void SetupPlayerInputComponent();
	//UFUNCTION(BlueprintCallable)
	///float GetSpeed(){return speed;}

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input)
	FVector moveInput = FVector();
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input)
	FVector lastNonZeroMoveInput = FVector();

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input)
	FVector aimInput = FVector();
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input)
	FVector lastNonZeroAimInput = FVector();

	//Torso Rotation Variables
	///UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Aiming)
	///FVector aimDirection = FVector(0.0f, 1.0f, 0.0f);
	///
	///UPROPERTY(EditAnywhere, Category = Aiming)
	///FVector aimTarget = FVector(0.0f, 0.0f, 0.0f);
	///
	///UPROPERTY(EditAnywhere, Category = Aiming)
	///FRotator aimRotation;
	///
	///UPROPERTY(EditAnywhere, Category = Aiming)
	///float turnSpeed = 120.0f;
	///
	///float m_turnAngle = 0.0f;
	///
	/////Locomotion Variables 
	///UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Movement)
	///float speed = 0.0f;
	///
	///UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Movement)
	///float speedMax = 8000.0f;
	///
	///UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Movement)
	///float velocityDotProduct = 0.0f;
	///
	///UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Movement)
	///float m_pivotSpeed = 3.5f;
	///
	///UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Movement)
	///float m_accelerationMax = 65.0f;
	///
	///UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Movement)
	///float m_linearDrag = 10.0f;
	///
	///UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Movement)
	///float m_stopDrag = 30.0f;
	///
	///UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Movement)
	///float m_exponentialDrag = 0.8f;
	///
	/////UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Movement)
	/////FVector velocity = FVector(0.0f, 0.0f, 0.0f);
	///
	///UPROPERTY(EditAnywhere, Category = Movement)
	///FVector desiredVelocity = FVector(0.0f, 0.0f, 0.0f);
	///
	/////UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Movement)
	///FVector walkDirection = FVector(0.0f, 0.0f, 0.0f);
	///
	///FVector m_lastDirInput = FVector(0.0f, 0.0f, 0.0f);
	///
	/////UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Movement)
	///FVector m_desiredDeltaVelocity = FVector(0.0f, 0.0f, 0.0f);
	///
	/////UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Movement)
	///FRotator walkRotation = FRotator(0.0f, 0.0f, 0.0f);
	///
	///LocomotionState m_state = walking;
	///
	///// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	///void DoLocomotion(float DeltaSeconds);
	void PollControllers();
	///svoid InputToVelocity(float DeltaSeconds);
	///void GetWalkDirection(float DeltaSeconds);
	///void DecaySpeed(float DeltaSeconds);
	///
	///void GetAimDirection(float DeltaSeconds);
};