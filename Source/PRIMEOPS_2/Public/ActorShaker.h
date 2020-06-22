// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/SceneComponent.h"
#include "ActorShaker.generated.h"


UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class PRIMEOPS_2_API UActorShaker : public USceneComponent
{
	GENERATED_BODY()

	float trauma = 0.0f;
	float duration = 1.0f;

public:
	

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float m_traumaMax = 1.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float m_translationMax = 1000.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float m_decayLinear = 1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float m_decayNonLinear = 1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float m_smoothness = 0.5f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool m_constrainX = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool m_constrainY = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool m_constrainZ = false;
	
	// Sets default values for this component's properties
	UActorShaker();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION(BlueprintCallable)
	virtual void AddTrauma(float trauma, float a_duration = 1.0f);
};
