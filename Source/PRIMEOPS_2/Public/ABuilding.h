// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ABuilding.generated.h"

class UStaticMeshComponent;

UCLASS()
class PRIMEOPS_2_API ABuilding : public AActor
{
	GENERATED_BODY()

	UPROPERTY(EDITANYWHERE)
	float m_hitPoints = 1;

	UPROPERTY(EDITANYWHERE)
	float m_hitPointsMax = 1000;

	UPROPERTY(EDITANYWHERE)
	float m_translationMax = 3000.0f;

	float m_traumaMax = 1.0f;
	//float m_duration;
	//float timer;

	float m_decay = 0.15;
	float trauma = 0.0f;

	UStaticMeshComponent* mesh;

public:
	// Sets default values for this actor's properties
	ABuilding();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;

	float TakeDamage(float DamageAmount, struct FDamageEvent const& DamageEvent, class AController* EventInstigator, class AActor* DamageCauser) override;
};
