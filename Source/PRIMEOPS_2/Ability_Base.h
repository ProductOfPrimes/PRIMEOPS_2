// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Engine/World.h"
#include "MechWeaponHandler.h"
#include "Ability_Base.generated.h"

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class PRIMEOPS_2_API UAbility_Base : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UAbility_Base();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	//void SetOwner()

	virtual void ActivateAbility();

	virtual void OnEquip();
	virtual void OnUnequip();

	virtual void OnCooldownFinish();

	void SetOwner(UMechWeaponHandler* owner);

	class UMechWeaponHandler* mechOwner;
	float m_cooldown = 0.1f;
	float m_heatGeneration = 0.25f;

protected:
	UPROPERTY(EditAnywhere, Category="Gameplay")
	float m_cooldownTimer = 0.0f;
	bool m_onCooldown = false;
};
