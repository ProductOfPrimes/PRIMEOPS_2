// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "Blueprint/UserWidget.h"
#include "Runtime/UMG/Public/UMG.h"
#include "Slate.h"
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

#if WITH_EDITOR
	// Returns a human readable description of the latent operation's current state
	virtual FString GetDescription() const override
	{
		static const FNumberFormattingOptions DelayTimeFormatOptions = FNumberFormattingOptions()
			.SetMinimumFractionalDigits(3)
			.SetMaximumFractionalDigits(3);
		return FText::Format(NSLOCTEXT("SecondaryHealthAction", "SecondaryHealthTimeFmt", "Delay ({0} seconds left)"), FText::AsNumber(timer, &DelayTimeFormatOptions)).ToString();
	}
#endif
};
