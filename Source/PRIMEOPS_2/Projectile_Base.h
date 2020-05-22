// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Projectile_Base.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class PRIMEOPS_2_API UProjectile_Base : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UProjectile_Base();
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	virtual void OnDeath();

	//bool HeadshotCheck();

	float m_speed = 1000.0f; // muzzle velocity
	float m_attack = 10.f; // damage
	float m_critMultiplier = 2.0f;
	float m_range = 1000.f; // bullets die after they have gone this far
	float m_knockback = 0.0f;

	// ETeam team;
	// MechOwner owner;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	float m_distanceTravelled = 0.0f;
};