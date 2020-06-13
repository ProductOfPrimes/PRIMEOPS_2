// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Engine/World.h"
#include "Ability_Base.generated.h"

class UMechWeaponHandler;

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

	UFUNCTION(BlueprintCallable)
	virtual void ActivateAbility();

	UFUNCTION(BlueprintCallable)
	virtual void OnEquip();
	UFUNCTION(BlueprintCallable)
	virtual void OnUnequip();

	UFUNCTION(BlueprintCallable)
	virtual void OnCooldownFinish();

	UFUNCTION(BlueprintCallable)
	void SetMechOwner(UMechWeaponHandler* owner);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Gameplay")
	UMechWeaponHandler* mechOwner;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Gameplay")
	float m_cooldown = 0.1f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Gameplay")
	float m_heatGeneration = 0.25f;

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Gameplay")
	float m_cooldownTimer = 0.0f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Gameplay")
	bool m_onCooldown = false;
};
