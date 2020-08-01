// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine.h"

//// https://unreal.gg-labs.com/wiki-archives/macros-and-data-types/enums-for-both-c++-and-bp
UENUM(BlueprintType)
enum GearSlot
{
	L_ARM          UMETA(DisplayName="Left Arm"),
	L_SHD          UMETA(DisplayName="Left Shoulder"),
	R_SHD          UMETA(DisplayName="Right Shoulder"),
	R_ARM          UMETA(DisplayName="Right Arm"),
	NUM_GEAR_SLOTS UMETA(DisplayName="Total")
};