// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "LatentActions.h"
#include "CoreMinimal.h"

/**
 * 
 */
class PRIMEOPS_2_API SecondaryHealthAction : public FPendingLatentAction
{
public:
	~SecondaryHealthAction();

	float timer;

	FName ExecutionFunction;
	int32 OutputLink;
	FWeakObjectPtr CallbackTarget;

	SecondaryHealthAction(float Duration, const FLatentActionInfo& LatentInfo)
		:timer(Duration),
		ExecutionFunction(LatentInfo.ExecutionFunction),
		OutputLink(LatentInfo.Linkage),
		CallbackTarget(LatentInfo.CallbackTarget)
	{

	}

	virtual void UpdateOperation(FLatentResponse& Response) override
	{
		timer -= Response.ElapsedTime();

		Response.FinishAndTriggerIf(timer <= 0.0f, ExecutionFunction, OutputLink, CallbackTarget);
	}

};
