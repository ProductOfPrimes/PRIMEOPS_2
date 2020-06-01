// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/SceneComponent.h"
#include "ActorShaker.generated.h"


UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class PRIMEOPS_2_API UActorShaker : public USceneComponent
{
	GENERATED_BODY()

	UPROPERTY(EDITANYWHERE)
		float m_traumaMax = 1.0f;

	UPROPERTY(EDITANYWHERE)
		float m_translationMax = 3000.0f;

	UPROPERTY(EDITANYWHERE)
		float m_decay = 0.15;

	UPROPERTY(EDITANYWHERE)
		float m_duration = 60.0f;

	float trauma = 0.0f;


public:
	// Sets default values for this component's properties
	UActorShaker();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION(BlueprintCallable)
	virtual void AddTrauma(float trauma);
};
