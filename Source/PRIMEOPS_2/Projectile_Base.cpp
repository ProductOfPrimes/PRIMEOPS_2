// Fill out your copyright notice in the Description page of Project Settings.


#include "Projectile_Base.h"

// Sets default values for this component's properties
UProjectile_Base::UProjectile_Base()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// Receive at team variable, MechOwner
	m_distanceTravelled = 0;

	// ...
}


// Called when the game starts
void UProjectile_Base::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UProjectile_Base::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UProjectile_Base::OnDeath()
{
	// Kill you are self
}

