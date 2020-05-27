// Fill out your copyright notice in the Description page of Project Settings.


#include "MechScriptController.h"

void AMechScriptController::Tick(float DeltaSeconds)
{
	DoLocomotion(DeltaSeconds);
}

void AMechScriptController::BeginPlay()
{

}

void AMechScriptController::DoLocomotion(float DeltaSeconds)
{
	
}

void AMechScriptController::AddHeat(float _heat)
{
	//float previousHeatPercentage = getHeatPercentage();

	//m_heat = max(m_heat + val, 0.0f);

	//float heatPercentage = getHeatPercentage();

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