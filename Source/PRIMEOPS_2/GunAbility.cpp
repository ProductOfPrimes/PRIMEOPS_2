// Fill out your copyright notice in the Description page of Project Settings.

#include "GunAbility.h"
#include <string>
#include "MechWeaponHandler.h"

UGunAbility::UGunAbility()
{
    PrimaryComponentTick.bCanEverTick = true;

    m_cooldownTimer = 0.0f;

    // setup
    m_burstCount = 1;
    m_burstShotCooldown = 1.0 / 1.0f;
    //m_burstTimer = GameTimer(m_burstTime);
    m_bulletsToFire = 0u;
    m_burstShotCooldownTimer = 0.0f;
}

void UGunAbility::ActivateAbility()
{
	if (m_cooldownTimer <= 0.0f && m_bulletsToFire == 0)
	{
        m_bulletsToFire = m_burstCount;
	}
}

void UGunAbility::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction * ThisTickFunction)
{
	if (m_bulletsToFire != 0) // if we are firing
	{
		m_burstShotCooldownTimer = m_burstShotCooldownTimer - DeltaTime;

        GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("%f"), m_burstShotCooldownTimer));

		while (m_burstShotCooldownTimer < 0.0f)
		{
            GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Toast"));

            m_burstShotCooldownTimer += m_burstShotCooldown;

			m_bulletsToFire -= 1;

			Fire();
			mechOwner->AddHeat(m_heatGeneration);
			//rumble();

			if (m_bulletsToFire == 0)
			{
				m_cooldownTimer = m_cooldown;
				m_burstShotCooldownTimer = 0.0f;
				break;
			}
		}

		///////// recoil animation

		//// update recoil animation so it reaches rest position right when the cooldown is over.
		//float tVal = util::clamp(util::invLerp(m_burstShotCooldownTimer, m_burstShotCooldown, 0.0f) * m_recoilAnimationRecoverySpeed, 0.0f, 1.0f);
		//glm::vec3 newPosition = util::ramp(m_recoilAnimationTranslation, glm::vec3(0.0f), tVal);
		//parent->accessComponent<Renderable>()->m_drawOffset.setPosition(newPosition);

	}
	else
	{
        Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

		//if (rumbleTimer.elapsed() >= m_rumbleTime)
		//{
		//	//rumbleTimer.lap();
		//	m_rumble = 0.0f;
		//}

		/////////// recoil animation
		//update recoil animation so it reaches rest position right when the cooldown is over.
		//float tVal = util::clamp(util::invLerp(m_cooldownTimer, m_cooldown, 0.0f) * m_recoilAnimationRecoverySpeed, 0.0f, 1.0f);
		//glm::vec3 newPosition = util::ramp(m_recoilAnimationTranslation, glm::vec3(0.0f), tVal);
		//parent->accessComponent<Renderable>()->m_drawOffset.setPosition(newPosition);
	}
}

void UGunAbility::Fire()
{
    GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Fire!"));

    FVector forward = mechOwner->GetOwner()->GetActorForwardVector();

    FActorSpawnParameters spawnParams;

    AActor* owner = GetOwner();

    FRotator rotator = owner->GetActorRotation();

    FVector spawnLocation = GetOwner()->GetActorLocation();
    char* ownerName = TCHAR_TO_ANSI(*owner->GetName());

    GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("%s"), ownerName));

    AActor* newBullet = GetWorld()->SpawnActor<AActor>(projectile, spawnLocation, rotator, spawnParams);

}

void UGunAbility::OnCooldownFinish()
{
}