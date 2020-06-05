// Fill out your copyright notice in the Description page of Project Settings.

#pragma once


#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include "Building.generated.h"

UCLASS()
class PRIMEOPS_2_API ABuilding : public AActor
{
	GENERATED_BODY()

public:


	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float m_hitPoints;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float m_hitPointsMax;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool m_isAlive;

	// Sets default values for this actor's properties
	ABuilding();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;

	//float TakeDamage(float DamageAmount, struct FDamageEvent const& DamageEvent, class AController* EventInstigator, class AActor* DamageCauser) override;
};
