// Fill out your copyright notice in the Description page of Project Settings.

#include "PowerRun.h"
#include "PlayerInventory.h"
#include "PlayerRunner.h"
#include "PlayerInternalPower.h"
#include "Engine.h"


// Sets default values for this component's properties
UPlayerInternalPower::UPlayerInternalPower()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// current number in the array
	NumberOfBatteries = 0;

	// initialize tarray with nullptr
	BatteryArray.Init(nullptr, 2);

	// initialize player
	Player = (APlayerRunner*)this->GetOwner();

	bUpdatedAtStart = false;

}


// Called when the game starts
void UPlayerInternalPower::BeginPlay()
{
	Super::BeginPlay();

	// creates two new batteries so the player begins with full charge
	StarterBattery1 = NewObject<ABatteryPickup>();
	//StarterBattery2 = NewObject<ABatteryPickup>();

	// places the new batteries into the battery array and increases number of batteries
	BatteryArray[0] = StarterBattery1;
	//BatteryArray[1] = StarterBattery2;
	NumberOfBatteries = 1;

}


// Called every frame
void UPlayerInternalPower::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	
	if (!bUpdatedAtStart)
	{
		UpdateInternalPower();
		bUpdatedAtStart = true;
	}

	// depletes the equipped batteries as player moves
	if (GEngine)
	{
		// battery depletion variables
		Velocity = Player->GetVelocity().Size();
		DeltaSeconds = GetWorld()->DeltaTimeSeconds;
		BatteryDivide = GetBatteryDivide();

		// finds total internal power between the battery slots
		TotalInternalPower = GetInternalPower();
<<<<<<< HEAD
=======
		GEngine->AddOnScreenDebugMessage(-1, 0.01f, FColor::Red, TEXT("InternalPower: ") + FString::SanitizeFloat(TotalInternalPower));
>>>>>>> origin/Eric
		DepleteInternalPower();

	}

<<<<<<< HEAD
	// update float variables for ui accessibility, divide float by 50 to match it to the health bar bind
	if (BatteryArray[0])
	{
		BatteryPower1 = BatteryArray[0]->PowerLevel / 50.0f;
	}
	else
	{
		BatteryPower1 = 0.0f;
	}

	if (BatteryArray[1])
	{
		BatteryPower2 = BatteryArray[1]->PowerLevel / 50.0f;
	}
	else
	{
		BatteryPower2 = 0.0f;
	}
=======
>>>>>>> origin/Eric

}

// adds battery from inventory into battery array
void UPlayerInternalPower::AddToBatteryInventory(ABatteryPickup * NewBattery)
{
	if (GEngine)
	{
<<<<<<< HEAD
//		if (Player)
//		{
=======
		if (Player)
		{
>>>>>>> origin/Eric
			if (NewBattery)
			{
				int NewItemIndex;

				// if there is an open slot in the battery array
				if (NumberOfBatteries < BatteryArray.Num())
				{
					// it locates whethere the open slot is [0] or [1]
					NewItemIndex = FirstEmptyBatteryContainer();

					if (NewItemIndex != -1)
					{
						// places battery pickup pointer into battery array, increments number of batteries, updates the ui
						BatteryArray[NewItemIndex] = NewBattery;
						NumberOfBatteries++;
<<<<<<< HEAD
=======
						GEngine->AddOnScreenDebugMessage(-1, 1.0f, FColor::Red, TEXT("Battery Equipped."));
>>>>>>> origin/Eric
						UpdateInternalPower();
					}

				}
				else
				{
					GEngine->AddOnScreenDebugMessage(-1, 1.0f, FColor::Red, TEXT("Battery packs are full."));

					// if battery inventory is full, return the item back to the regular inventory
					Player->Inventory->AddToInventory(NewBattery);
				}
			}
<<<<<<< HEAD
//		}
=======
		}
>>>>>>> origin/Eric
	}
}

// used to replace the battery and automatically drop it when it is empty, returns a battery
ABatteryPickup * UPlayerInternalPower::GetBattery(int index)
{
	if (BatteryArray[index])
	{
		// makes a copy of the replacable battery
		ABatteryPickup* OldBattery = BatteryArray[index];

		// turns battery location into a nullptr
		BatteryArray[index] = nullptr;

		// decrements the number of batteries, updates the battery inventory ui
		if (OldBattery)
		{
			if (NumberOfBatteries > 0)
			{
				NumberOfBatteries--;
				UpdateInternalPower();
			}
			return OldBattery;
		}
		
	}
	return nullptr;
}

// remove a battery in a particular index, destroys the object
void UPlayerInternalPower::RemoveFromBatteryInventory(int index)
{
	if (GEngine)
	{
		if (Player)
		{
			if (BatteryArray[index])
			{
				// decrements the number of batteries, replaces the array location with a nullptr
				ABatteryPickup* RemovedBattery = GetBattery(index);
				
				// destroys pickup
				if (RemovedBattery)
				{
					RemovedBattery->Destroy();
				}
				
			}
		}
	}
}


// iterates the battery array and returns the index of the first nullptr
int UPlayerInternalPower::FirstEmptyBatteryContainer()
{
	int i;
	for (i = 0; i < BatteryArray.Num(); i++)
	{
		if (BatteryArray[i] == nullptr)
		{
			return i;
		}
	}
	return -1;
}


// checks battery array and returns true if it is empty, false otherwise
bool UPlayerInternalPower::CheckEmpty()
{
	for (int i = 0; i < BatteryArray.Num(); i++)
	{
		if (BatteryArray[i])
		{
			return false;
		}
	}
	return true;
}

// returns total internal power among equipped batteries
float UPlayerInternalPower::GetInternalPower()
{
	// if there are two batteries used
	if (NumberOfBatteries == 2)
	{
		return BatteryArray[0]->PowerLevel + BatteryArray[1]->PowerLevel;
	}

	// if there is one battery used
	if (NumberOfBatteries == 1)
	{
		if (BatteryArray[0])
		{
			return BatteryArray[0]->PowerLevel;
		}
		else
		{
			return BatteryArray[1]->PowerLevel;
		}
		
	}
	// if there are no batteries	
	return 0.0f;
	
}

<<<<<<< HEAD
// updates the internal power ui
=======
>>>>>>> origin/Eric
void UPlayerInternalPower::UpdateInternalPower()
{
	OnUpdateInternalPower.Broadcast(BatteryArray);
}

<<<<<<< HEAD
// returns number of batteries currently owned
int UPlayerInternalPower::GetNumberOfBatteries()
{
	return NumberOfBatteries;
}

// removes an immediate amount of power from a batterie if it exists
void UPlayerInternalPower::DamageBatteries(float DamageDealt)
{
	for (int i = 0; i < NumberOfBatteries; i++)
	{
		if (BatteryArray[i])
		{
			BatteryArray[i]->BatterySubPower(DamageDealt);

		}

	}
}

=======
>>>>>>> origin/Eric

float UPlayerInternalPower::GetBatteryDivide()
{
	// if there are two batteries, battery loss is split between both batteries
	if (NumberOfBatteries > 1)
	{
		return 0.5f;
	}
	// one battery drains like normal
	else
	{
		return 1.0f;
	}
}

// depletes the equipped batteries, called every tick
void UPlayerInternalPower::DepleteInternalPower()
{
	// depletes the equipped batteries as player moves
	if (GEngine)
	{
		// battery depletion variables
		Velocity = Player->GetVelocity().Size();
		DeltaSeconds = GetWorld()->DeltaTimeSeconds;
		BatteryDivide = GetBatteryDivide();

		// if batteries exist in the battery array
		if (BatteryArray[0])
		{
			// battery powerlevel for slot 1, if powerlevel is 0 it is removed from battery inventory automatically
			if (BatteryArray[0]->PowerLevel > 0)
			{
				BatteryArray[0]->PowerLevel -= BatteryDivide * Velocity * Player->CalculateDepleteRate() * DeltaSeconds;
<<<<<<< HEAD
=======
				GEngine->AddOnScreenDebugMessage(-1, 0.01f, FColor::Red, TEXT("[0] PowerLevel ") + FString::SanitizeFloat(BatteryArray[0]->PowerLevel));
>>>>>>> origin/Eric
			}
			else
			{
				BatteryArray[0]->PowerLevel = 0;
				RemoveFromBatteryInventory(0);

			}
		}
		if (BatteryArray[1])
		{
			// battery powerlevel for slot 2, if powerlevel is 0 it is removed from battery inventory automatically
			if (BatteryArray[1]->PowerLevel > 0)
			{
				BatteryArray[1]->PowerLevel -= BatteryDivide * Velocity * Player->CalculateDepleteRate() * DeltaSeconds;
<<<<<<< HEAD
=======
				GEngine->AddOnScreenDebugMessage(-1, 0.01f, FColor::Red, TEXT("[1] PowerLevel ") + FString::SanitizeFloat(BatteryArray[1]->PowerLevel));
>>>>>>> origin/Eric
			}
			else
			{
				BatteryArray[1]->PowerLevel = 0;
				RemoveFromBatteryInventory(1);

			}
		}
	}
}

		

