// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AbilitySystemInterface.h"
#include "MechWeaponHandler.generated.h"

class UAbilityBase;
class UAbilitySystem;

// https://unreal.gg-labs.com/wiki-archives/macros-and-data-types/enums-for-both-c++-and-bp
UENUM(BlueprintType)
enum GearSlot
{
	L_ARM          UMETA(DisplayName="Left Arm"),
	L_SHD          UMETA(DisplayName="Left Shoulder"),
	R_SHD          UMETA(DisplayName="Right Shoulder"),
	R_ARM          UMETA(DisplayName="Right Arm"),
	NUM_GEAR_SLOTS UMETA(DisplayName="Total")
};

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class PRIMEOPS_2_API UMechWeaponHandler : public UActorComponent, public IAbilitySystemInterface
{
	GENERATED_BODY()

public:

	// Sets default values for this component's properties
	UMechWeaponHandler();
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = GameplayProperties)
	float m_heat = 0;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = GameplayProperties)
	float m_maxHeat = 1.0;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = GameplayProperties)
	float heatDrain = 0.0; // Reduce heat per second
	bool m_isOverHeated = false;
	float m_overheatThreshold = 0.5f; // After overheating, heat must dissipate below this before they can fire again
	const float m_heatWarningThreshold = 0.7f; // When heat over this value, warnings appear

	UFUNCTION(BlueprintCallable)
	void AddHeat(float heat);
	UFUNCTION(BlueprintCallable)
	float GetHeatPercentage() { return m_heat / m_maxHeat; }

	UFUNCTION(BlueprintCallable)
	void Equip(UAbility_Base* ability, GearSlot slot);

    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    TSubclassOf<AActor> sniper;

    UFUNCTION(BlueprintCallable)
    void FireRightShoulder();

    AActor* sniperObj;

    UAbility_Base* m_loadout[4];

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Abilities)
    TSubclassOf<class UGameplayAbility> ability;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Abilities, meta = (AllowPrivateAccess = "true"))
    UAbilitySystemComponent* abilitySystem;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

    virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override
    {
        return abilitySystem;
    }
};
