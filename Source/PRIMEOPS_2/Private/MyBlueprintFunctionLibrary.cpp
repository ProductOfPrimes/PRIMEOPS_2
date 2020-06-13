// Fill out your copyright notice in the Description page of Project Settings.


#include "MyBlueprintFunctionLibrary.h"

void UMyBlueprintFunctionLibrary::GetReqest(UObject* WorldContextObject, struct FLatentActionInfo LatentInfo)
{
    if (UWorld* World = GEngine->GetWorldFromContextObject(WorldContextObject))

    {

        FLatentActionManager& LatentActionManager = World->GetLatentActionManager();

        if (LatentActionManager.FindExistingAction<SecondaryHealthAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL)

        {
            //LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID, new SecondaryHealthAction(Duration, LatentInfo));
        }

    }
}