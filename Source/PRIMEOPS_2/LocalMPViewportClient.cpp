// Fill out your copyright notice in the Description page of Project Settings.

#include "LocalMPViewportClient.h"

// Code taken from here, updated from the deprecated InputKey
// https://www.ue4community.wiki/Legacy/Local_Multiplayer_Tips#Player_0_.3D_Keyboard.2C_Player_1_.3D_Gamepad_.28C.2B.2B.29
bool ULocalMPViewportClient::InputKey(const FInputKeyEventArgs& EventArgs)
{
	if (EventArgs.IsGamepad())
	{
		// Map the gamepad to the next player index (so 1st controller is player index 1, etc.)
		FInputKeyEventArgs NewArgs = FInputKeyEventArgs(Viewport, EventArgs.ControllerId + 1, EventArgs.Key, EventArgs.Event, EventArgs.AmountDepressed, EventArgs.IsGamepad());
		return Super::InputKey(NewArgs);
	}
	else
	{
		return Super::InputKey(EventArgs);
	}
}

bool ULocalMPViewportClient::InputAxis(FViewport* _Viewport, int32 ControllerId, FKey Key, float Delta, float DeltaTime, int32 NumSamples /*= 1*/, bool bGamepad /*= false*/)
{
	if (bGamepad)
	{
		// Map the gamepad to the next player index (so 1st controller is player index 1, etc.)
		return Super::InputAxis(_Viewport, ControllerId + 1, Key, Delta, DeltaTime, NumSamples, bGamepad);
	}
	else
	{
		return Super::InputAxis(_Viewport, ControllerId, Key, Delta, DeltaTime, NumSamples, bGamepad);
	}
}