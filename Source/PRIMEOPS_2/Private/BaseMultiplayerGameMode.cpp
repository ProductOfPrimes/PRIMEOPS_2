// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseMultiplayerGameMode.h"

void ABaseMultiplayerGameMode::InitGame(const FString& MapName, const FString& Options, FString& ErrorMessage)
{
	Super::InitGame(MapName, Options, ErrorMessage);
}

void ABaseMultiplayerGameMode::InitGameState()
{
	Super::InitGameState();
}
