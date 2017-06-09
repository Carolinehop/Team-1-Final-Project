// Fill out your copyright notice in the Description page of Project Settings.

#include "PowerRun.h"
#include "PlayerRunner.h"
#include "Pickup.h"
#include "Engine.h"
#include "JumpBoostPickup.h"


AJumpBoostPickup::AJumpBoostPickup() : APickup()
{
	PickupName = "Jump Boost";
	PickupWeight = 2.0f;

	NewJumpHeight = 1200.0f;

}

void AJumpBoostPickup::Activate(AActor * OtherActor)
{
	if (GEngine)
	{
		Player = Cast<APlayerRunner>(OtherActor);
		if (Player)
		{
			Player->JumpBoostActivated = true;
			Player->GetCharacterMovement()->JumpZVelocity = 1200.0f;

		}
	}
}

float AJumpBoostPickup::GetJumpHeightIncrease()
{
	return NewJumpHeight;
}
