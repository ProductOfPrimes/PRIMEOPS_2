// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "MechWeaponHandler.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class PRIMEOPS_2_API UMechWeaponHandler : public UActorComponent
{
	GENERATED_BODY()

public:
	enum GearSlot 
	{
		L_ARM,
		L_SHD,
		R_SHD,
		R_ARM,
		NUM_GEAR_SLOTS
	};

	// Sets default values for this component's properties
	UMechWeaponHandler();
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UPROPERTY(EditAnywhere, Category = GameplayProperties)
	float m_heat = 0;
	UPROPERTY(EditAnywhere, Category = GameplayProperties)
	float m_maxHeat = 1.0;
	UPROPERTY(EditAnywhere, Category = GameplayProperties)
	float heatDrain = 0.0; // Reduce heat per second
	bool m_isOverHeated = false;
	float m_overheatThreshold = 0.5f; // After overheating, heat must dissipate below this before they can fire again
	const float m_heatWarningThreshold = 0.7f; // When heat over this value, warnings appear

	void AddHeat(float heat);
	float GetHeatPercentage() { return m_heat / m_maxHeat; }

	class UAbility_Base* m_loadout[4];

protected:
	// Called when the game starts
	virtual void BeginPlay() override;
		
	UFUNCTION(BlueprintCallable)
	void FireRightShoulder();
};
