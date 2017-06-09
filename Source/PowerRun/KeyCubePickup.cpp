// Fill out your copyright notice in the Description page of Project Settings.

#include "PowerRun.h"
#include "Engine.h"
#include "PlayerRunner.h"
#include "KeyCubePickup.h"


AKeyCubePickup::AKeyCubePickup() : APickup()
{
	PickupName = "Key Cube";
	PickupWeight = 8.0f;


}


void AKeyCubePickup::Activate(AActor* OtherActor)
{
	Player = Cast<APlayerRunner>(OtherActor);
	if (Player)
	{
		DropHere();
	}
}

void AKeyCubePickup::DropHere()
{
	GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Green, TEXT("Dropping..."));

}
