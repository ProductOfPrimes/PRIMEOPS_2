// Fill out your copyright notice in the Description page of Project Settings.

#include "Ability_Base.h"

// Sets default values for this component's properties
UAbility_Base::UAbility_Base()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UAbility_Base::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UAbility_Base::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// Code ripped straight from the MadMechs repository
	m_cooldownTimer -= DeltaTime;

	if (m_cooldownTimer < 0) {
		if (m_onCooldown) {
			m_cooldownTimer = 0;
			m_onCooldown = false;
			OnCooldownFinish();
		}
	}
	else if (m_cooldownTimer > 0) {
		m_onCooldown = true;
	}
}

void UAbility_Base::SetOwner(UMechWeaponHandler* owner) {
	mechOwner = owner;
}

void UAbility_Base::ActivateAbility()
{
}

void UAbility_Base::OnEquip()
{
}

void UAbility_Base::OnUnequip()
{
}

void UAbility_Base::OnCooldownFinish()
{
}

