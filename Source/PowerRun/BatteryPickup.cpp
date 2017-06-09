// Fill out your copyright notice in the Description page of Project Settings.

#include "PowerRun.h"
#include "Pickup.h"
#include "PlayerRunner.h"
#include "BatteryPickup.h"
<<<<<<< HEAD
#include "PlayerInternalPower.h"
=======
<<<<<<< HEAD
#include "PlayerInternalPower.h"
=======
>>>>>>> origin/Eric
>>>>>>> origin/Eric
#include "Engine.h"


// assigns unique weight and powerlevel to battery
ABatteryPickup::ABatteryPickup() : APickup()
{
	PickupName = "Battery";
<<<<<<< HEAD
=======
<<<<<<< HEAD
>>>>>>> origin/Eric
	PickupWeight = 3.0f;
	PowerLevel = 50.0f;
	
	// find battery image icon in content folder and set it to utexture2d type, initialize battery image
	static ConstructorHelpers::FObjectFinder<UTexture2D> TextureFinder(TEXT("Texture2D'/Game/Thumbnails/BatteryIcon.BatteryIcon'"));
	UTexture2D* Texture = TextureFinder.Object;

	PickupImage = Texture;
<<<<<<< HEAD
=======
=======
	PickupWeight = 5.0f;
	PowerLevel = 25.0f;
>>>>>>> origin/Eric
>>>>>>> origin/Eric

}

// adds power to player character, remove itself from existance
void ABatteryPickup::Activate(AActor* OtherActor)
{
	if (GEngine)
	{
		Player = Cast<APlayerRunner>(OtherActor);
		if (Player)
		{
<<<<<<< HEAD
			Player->InternalPower->AddToBatteryInventory(this);
			
			// attach mesh to socket in BOR skeletal mesh
=======
<<<<<<< HEAD
			Player->InternalPower->AddToBatteryInventory(this);
=======
			Player->AddToCurrentPower(PowerLevel);
			GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Purple, TEXT("Activating Battery: +") + FString::SanitizeFloat(PowerLevel) + TEXT(" Internal Power"));
>>>>>>> origin/Eric
>>>>>>> origin/Eric
		}
	}
	
}
<<<<<<< HEAD
=======
<<<<<<< HEAD
>>>>>>> origin/Eric

// allows call to each battery to deplete itself when taking damage
void ABatteryPickup::BatterySubPower(float PowerToLose)
{
	if (PowerLevel - PowerToLose > 0)
	{
		PowerLevel -= PowerToLose;
	}
	else
	{
		PowerLevel = 0;
	}
}
<<<<<<< HEAD
=======
=======
>>>>>>> origin/Eric
>>>>>>> origin/Eric
