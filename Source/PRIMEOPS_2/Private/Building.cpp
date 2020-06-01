// Fill out your copyright notice in the Description page of Project Settings.


#include "Building.h"
#include "Engine.h"
#include "ActorShaker.h"
#include "Console.generated.h"

// Sets default values
ABuilding::ABuilding()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	//printf("test");
	// Standard way to log to console.
	UE_LOG(LogTemp, Warning, TEXT("Building just started running"));
}

// Called when the game starts or when spawned
void ABuilding::BeginPlay()
{
	Super::BeginPlay();
	m_hitPoints = m_hitPointsMax;
}

// Called every frame
void ABuilding::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);


}

float ABuilding::TakeDamage(float DamageAmount, FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser)
{
	float intensityScale = DamageAmount / m_hitPointsMax + 0.2f;

	//timer = m_duration * intensityScale;
	//m_duration = 2.0f;

	//trauma = m_traumaMax * intensityScale;
	//m_decay = 1.0f;

	shaker->AddTrauma(intensityScale);

	GEngine->AddOnScreenDebugMessage(
		1,
		170.35f,   // Duration of message - limits distance messages scroll onto screen
		FColor::Magenta.WithAlpha(128),   // Color and transparancy!
		FString::Printf(TEXT("%s %f"), "Took damage: ", DamageAmount)  // Our usual text message format
	);

	UE_LOG(LogTemp, Warning, TEXT("Took damage %f"), DamageAmount);

	m_hitPoints -= DamageAmount;

	return DamageAmount;
}

