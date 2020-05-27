// Fill out your copyright notice in the Description page of Project Settings.

#include "GunAbility.h"

void UGunAbility::ActivateAbility()
{
	if (m_cooldownTimer <= 0.0f && m_bulletsToFire == 0)
	{
		m_bulletsToFire = m_burstCount;
	}
}

void UGunAbility::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction * ThisTickFunction)
{
	if (m_bulletsToFire > 0) // if we are firing
	{
		m_burstShotCooldownTimer = m_burstShotCooldownTimer - DeltaTime;

		while (m_burstShotCooldownTimer < 0.0f)
		{
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
		m_cooldownTimer = m_cooldownTimer - DeltaTime;

		if (m_cooldownTimer < 0.0f)
		{
			if (m_onCooldown)
			{
				m_cooldownTimer = 0.0f;
				m_onCooldown = false;
				OnCooldownFinish();
			}
		}
		else if (m_cooldownTimer > 0.0f)
		{
			m_onCooldown = true;
		}

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
}

void UGunAbility::OnCooldownFinish()
{
}