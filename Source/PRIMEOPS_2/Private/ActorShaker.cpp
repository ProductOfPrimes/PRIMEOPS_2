// Fill out your copyright notice in the Description page of Project Settings.
#include "ActorShaker.h"

// Sets default values for this component's properties
UActorShaker::UActorShaker()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UActorShaker::BeginPlay()
{
	Super::BeginPlay();
	SetRelativeLocation(FVector::ZeroVector);
	// ...
	
}


// Called every frame
void UActorShaker::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	static float nonlinearDecay(2.0f);

	if (trauma > 0.0001)
	{

		trauma -= ((m_decay * DeltaTime) + (nonlinearDecay * m_decay * (trauma)*DeltaTime)); // trauma decreases nonlinearly
		trauma = FMath::Max(trauma, 0.0f);

		float x = FMath::FRandRange(-m_translationMax, m_translationMax) * trauma;
		float y = FMath::FRandRange(-m_translationMax, m_translationMax) * trauma;
		float z = FMath::FRandRange(-m_translationMax, m_translationMax) * trauma;

		FVector offset(x, y, z);
		SetRelativeLocation(offset);
	}
	else
	{
		SetRelativeLocation(FVector::ZeroVector);
	}
}

void UActorShaker::AddTrauma(float a_trauma)
{
	trauma += a_trauma;
	
}

