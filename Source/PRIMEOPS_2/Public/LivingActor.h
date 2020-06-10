// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "LivingActor.generated.h"

enum Team {Red, Blue, FreeForAll};

UCLASS()
class PRIMEOPS_2_API ALivingActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ALivingActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	float hitpointsCurrent = 0.0f;
	float hitpointsMax = 0.0f;

	Team team;

	bool isAlive = true;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void OnDeath();


};
