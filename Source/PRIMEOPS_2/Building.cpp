// Fill out your copyright notice in the Description page of Project Settings.

#include "Building.h"
#include "Math/UnrealMathUtility.h"
#include "Components/StaticMeshComponent.h"

// Sets default values
ABuilding::ABuilding()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void ABuilding::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void ABuilding::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);


	static float linearDecay(0.15f);
	static float nonlinearDecay(3.0f);

	m_trauma -= ((linearDecay * DeltaTime) + (nonlinearDecay * (m_trauma)*DeltaTime)); // trauma decreases nonlinearly
	m_trauma = FMath::Max(m_trauma, 0.0f);

	if (m_timer > 0)
	{
		m_timer -= DeltaTime;
		Shake(m_trauma);
	}
	else
	{
		VisualMesh->SetRelativeLocation(FVector(0.0f, 0.0f, 0.0f));
	}
}

float ABuilding::TakeDamage(float DamageAmount, FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser)
{
	m_hitPoints -= DamageAmount;
	m_timer = 1.0f;

	Shake(DamageAmount);
	
	if (m_hitPoints <= 0)
	{
		Destroy(false, true);
	}

	return DamageAmount;
}

void ABuilding::Shake(float intensity)
{
	float x = FMath::FRandRange(-intensity, intensity);
	float y = FMath::FRandRange(-intensity, intensity);
	float z = FMath::FRandRange(-intensity, intensity);

	SetActorRelativeLocation(FVector(x, y, z));
}