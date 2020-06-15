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


	if (trauma > 0.00001 && duration > 0)
	{
		trauma -= ((m_decayLinear * DeltaTime) + (m_decayNonLinear * (trauma)*DeltaTime)); // trauma decreases nonlinearly
		trauma = FMath::Max(trauma, 0.0f);

		duration -= DeltaTime;
		duration = FMath::Max(duration, 0.0f);
		
		float x = 0, y = 0, z = 0;

		if (!m_constrainX)
		x = FMath::FRandRange(-m_translationMax, m_translationMax) * trauma;
		if (!m_constrainY)
		y = FMath::FRandRange(-m_translationMax, m_translationMax) * trauma;
		if (!m_constrainZ)
		z = FMath::FRandRange(-m_translationMax, m_translationMax) * trauma;

		FVector offset(x, y, z);

		offset = FMath::Lerp(offset, GetRelativeLocation(), m_smoothness * DeltaTime);

	
		GEngine->AddOnScreenDebugMessage(
			1,
			5.35f,   // Duration of message - limits distance messages scroll onto screen
			FColor::Magenta.WithAlpha(128),   // Color and transparancy!
			offset.ToString()  // Our usual text message format
		);


		UE_LOG(LogTemp, Warning, TEXT("shaking!"));

		SetRelativeLocation(offset);
	}
	else
	{
		SetRelativeLocation(FVector::ZeroVector);
	}
}

void UActorShaker::AddTrauma(float a_trauma, float a_duration)
{
	trauma += a_trauma;
	duration = a_duration;
}

