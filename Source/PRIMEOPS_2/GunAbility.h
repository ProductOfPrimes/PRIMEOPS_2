// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Ability_Base.h"
#include "GunAbility.generated.h"

/**
 * 
 */
UCLASS()
class PRIMEOPS_2_API UGunAbility : public UAbility_Base
{
	GENERATED_BODY()
	
public:
	virtual void Activate();
	virtual void Fire();
	virtual void OnCooldownFinish();
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon Properties")
	float m_recoil = 0;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon Properties")
	float m_spread = 0.0f; // Angle in degrees
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon Properties")
	float m_cooldown = 1.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon Properties")
	float m_attack = 10.f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon Properties")
	float m_range = 1000.f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon Properties")
	float m_speed = 1000.f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon Properties")
	float m_critMultiplier = 2.0f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon Properties")
	float m_knockback = 0.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon Properties")
	int m_burstCount; // Times to fire in burst
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon Properties")
	float m_burstShotCooldown;

protected:

private:
	float m_burstShotCooldownTimer;
	unsigned int m_bulletsToFire;

};
