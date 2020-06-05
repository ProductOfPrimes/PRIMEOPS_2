// Fill out your copyright notice in the Description page of Project Settings.

#include "MechWeaponHandler.h"
#include "Ability_Base.h"
#include "SniperRifle.h"

// Sets default values for this component's properties
UMechWeaponHandler::UMechWeaponHandler()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UMechWeaponHandler::BeginPlay()
{
	Super::BeginPlay();

	//
	m_loadout[GearSlot::R_SHD] = NewObject<USniperRifle>();
	m_loadout[GearSlot::R_SHD]->SetOwner(this);
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
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("This is an on screen message!"));
	m_loadout[GearSlot::R_SHD]->Activate();
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