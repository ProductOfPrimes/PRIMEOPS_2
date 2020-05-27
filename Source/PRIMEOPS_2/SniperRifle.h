// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GunAbility.h"
#include "SniperRifle.generated.h"

/**
 * 
 */
UCLASS()
class PRIMEOPS_2_API USniperRifle : public UGunAbility
{
	GENERATED_BODY()
	
public:
	USniperRifle();

	void Fire() override;
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon Properties")
	float m_laserSightLength = 500.0f;

};
