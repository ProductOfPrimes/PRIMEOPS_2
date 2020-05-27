// Fill out your copyright notice in the Description page of Project Settings.


#include "SniperRifle.h"

USniperRifle::USniperRifle()
{
	m_heatGeneration = 0.1f;
	m_cooldown = 1.0f;
	m_recoil = 650.f;

	//m_rumbleStrength = 0.8f;
	//m_rumbleTime = 0.15f;

	m_knockback = 80.0f;

	//m_recoilAnimationTranslation = glm::vec3(0.0f, -2.5f, 0.0f);

	// projectile properties
	m_attack = 40.f;
	m_range = 2200.f;
	m_speed = 3000.f;
	m_critMultiplier = 2.0f;
}

void USniperRifle::Fire()
{
	// Spawn projectile
	//GameObject* projectile = makeProjectile();
	//
	//glm::vec3 forward = parent->transformable->getWorldTransform()[1];
	//
	//glm::vec3 offset = forward * 5.f;
	//glm::vec3 spawnPosition = parent->transformable->getWorldPosition();
	//
	//projectile->transformable->setPosition(spawnPosition + offset);
	//projectile->transformable->setDirection(forward);
	// Play sound
	//SoundSystem::getInstance()->PlaySoundOnceToChannel(&m_sndChannel, Fire, true, High);

	//recoil
	//m_owner->m_velocity -= forward * m_recoil * GameClock::getInstance()->getFrameTime();

	//StateManager::getInstance()->getCurrentScene()->m_entityMgr.add(projectile);
	//entityMgr->add(projectile);

	// spawn muzzle flash
	//glm::vec3 particleSpawnPosition = spawnPosition + forward * 20.0f;
	//auto effect = ParticleEffect::create("muzzleFlash_generic");
	//effect->m_gameObject->transformable->setPosition(particleSpawnPosition);
	//
	//getComponent<Renderable>()->setEmissive(glm::vec3(-0.4f));
}

void USniperRifle::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction * ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}