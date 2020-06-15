// Fill out your copyright notice in the Description page of Project Settings.

#include "MechWeaponHandler.h"
#include "AbilitySystemComponent.h"
#include "Ability_Base.h"
#include "SniperRifle.h"

// Sets default values for this component's properties
UMechWeaponHandler::UMechWeaponHandler()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

    abilitySystem = CreateDefaultSubobject<UAbilitySystemComponent>(TEXT("AbilitySystem"));

	// ...
}


// Called when the game starts
void UMechWeaponHandler::BeginPlay()
{
	Super::BeginPlay();

    GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Hi"));

    if (abilitySystem)
    {
        if (GetOwner()->HasAuthority() && ability)
        {
            GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Ability ready!"));
            abilitySystem->GiveAbility(FGameplayAbilitySpec(ability.GetDefaultObject(), 1, 0));
        }
        abilitySystem->InitAbilityActorInfo(GetOwner(), GetOwner());
    }

	//
    if (sniper) 
    {
        GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Yes, prefab exists"));

        FActorSpawnParameters spawnParams;
        spawnParams.Owner = GetOwner();

        FRotator rotator;

        FVector spawnLocation = GetOwner()->GetActorLocation();

        sniperObj = GetWorld()->SpawnActor<AActor>(sniper, spawnLocation, rotator, spawnParams);
        if (sniperObj)
        {
            GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Yes, object spawned"));
            //m_loadout[GearSlot::R_SHD] = newSniper->FindComponentByClass<UAbility_Base>();
            m_loadout[GearSlot::R_SHD] = (UAbility_Base*)sniperObj->GetComponentByClass(UAbility_Base::StaticClass());
            if (m_loadout[GearSlot::R_SHD])
            {
                m_loadout[GearSlot::R_SHD]->SetMechOwner(this);
                GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Debug Sniper!"));
            }
            else
            {
                GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Fr*ck"));
            }
        }
        else
        {
            GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Fr*ck"));
        }
    }
    else
    {
        GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Nothing worked lmao"));
    }
//
}


// Called every frame
void UMechWeaponHandler::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UMechWeaponHandler::FireRightShoulder()
{
    if (m_loadout[GearSlot::R_SHD])
    {
        m_loadout[GearSlot::R_SHD]->ActivateAbility();
    }
    else
    {
        GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Misfire"));
    }
}	

void UMechWeaponHandler::AddHeat(float _heat)
{
	float previousHeatPercentage = GetHeatPercentage();

	m_heat = FMath::Max(m_heat + _heat, 0.0f);

	float heatPercentage = GetHeatPercentage();

	//// trigger an overheat
	//if (m_heat >= m_heatMax && !m_isOverheated)
	//{
	//	m_isOverheated = true;
	//	SoundSystem::getInstance()->PlaySoundOnce(Overheat, false, Alert);
	//} // issue an overheat warning when heat rises over the percentage-based warning threshold
	//else if (heatPercentage > m_heatWarningThreshold && previousHeatPercentage <= m_heatWarningThreshold)
	//{
	//	SoundSystem::getInstance()->PlaySoundOnce(Overheat_Warning, false, Alert);
	//}

	//// delay heat dissipation
	//m_heatDelayTimer.restart();
}

void UMechWeaponHandler::Equip(UAbility_Base* _ability, GearSlot slot)
{
	m_loadout[slot] = _ability;
}
