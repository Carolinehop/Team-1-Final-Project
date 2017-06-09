// Fill out your copyright notice in the Description page of Project Settings.

#include "PowerRun.h"
#include "PlayerRunner.h"
#include "Pickup.h"
#include "BatteryPickup.h"
#include "Engine.h"
#include "PlayerInventory.h"


// Sets default values for this component's properties
UPlayerInventory::UPlayerInventory()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

<<<<<<< HEAD
	// number of items currently held
	NumberOfItems = 0;

	// initializes tarray with nullptr, size is 6
	InventoryArray.Init(nullptr, 6);
=======
<<<<<<< HEAD
	// number of items currently held
	NumberOfItems = 0;

	// initializes tarray with nullptr, size is 6
	InventoryArray.Init(nullptr, 6);
=======
	InventorySize = 6;
	NumberOfItems = 0;

	// creates array of nullptr
	for (int i = 0; i < InventorySize; i++)
	{
		InventoryArray[i] = nullptr;
	}
>>>>>>> origin/Eric
>>>>>>> origin/Eric

	// initializes player to access PlayerRunner functions
	Player = (APlayerRunner*)this->GetOwner();

<<<<<<< HEAD
=======
<<<<<<< HEAD
=======
	
>>>>>>> origin/Eric

>>>>>>> origin/Eric
} //end constructor


// Called when the game starts
void UPlayerInventory::BeginPlay()
{
	Super::BeginPlay();

<<<<<<< HEAD
}


=======
<<<<<<< HEAD
}


=======

}



>>>>>>> origin/Eric
>>>>>>> origin/Eric
// Called every frame
void UPlayerInventory::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

}

// adds item to the inventory
void UPlayerInventory::AddToInventory(APickup * PickupItem)
{
	if (GEngine)
	{
//		if (Player)
//		{
			if (PickupItem)
			{
				int NewItemIndex;

				// if the inventory is not full
<<<<<<< HEAD
				if (NumberOfItems < InventoryArray.Num())
=======
<<<<<<< HEAD
				if (NumberOfItems < InventoryArray.Num())
=======
				if (NumberOfItems < InventorySize)
>>>>>>> origin/Eric
>>>>>>> origin/Eric
				{
					// if new item weight will not exceed weight capacity
					if (Player->GetCurrentWeight() + PickupItem->PickupWeight <= Player->GetTotalWeight())
					{
						// locates first nullptr
						NewItemIndex = FirstEmptySlot();

<<<<<<< HEAD
						if (NewItemIndex != -1)
=======
<<<<<<< HEAD
						if (NewItemIndex != -1)
						{
							// assigns first nullptr position a pointer to the found item, adds weight to player, increments numberofitems, updates inventory ui
							InventoryArray[NewItemIndex] = PickupItem;
							Player->AddToCurrentWeight(PickupItem->PickupWeight);
							NumberOfItems++;
							UpdateInventory();
						}
						// make mesh invisble to player, need to still exist to avoid garbage collection
						PickupItem->PickupMesh->SetVisibility(false);
						PickupItem->PickupMesh->SetSimulatePhysics(false);
						PickupItem->PickupMesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);
						PickupItem->PickupBox->bGenerateOverlapEvents = false;
=======
						if (PickupItem)
>>>>>>> origin/Eric
						{
							// assigns first nullptr position a pointer to the found item, adds weight to player, increments numberofitems, updates inventory ui
							InventoryArray[NewItemIndex] = PickupItem;
							Player->AddToCurrentWeight(PickupItem->PickupWeight);
							NumberOfItems++;
							UpdateInventory();
						}
<<<<<<< HEAD
						// make mesh invisble to player, need to still exist to avoid garbage collection
						PickupItem->PickupMesh->SetVisibility(false);
						PickupItem->PickupMesh->SetSimulatePhysics(false);
						PickupItem->PickupMesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);
						PickupItem->PickupBox->bGenerateOverlapEvents = false;
=======
>>>>>>> origin/Eric
>>>>>>> origin/Eric
					}
					else
					{
						GEngine->AddOnScreenDebugMessage(-1, 0.01f, FColor::Blue, TEXT("Weight Cannot Exceed ") + FString::SanitizeFloat(Player->GetTotalWeight()));
					}
				}
				else
				{
					GEngine->AddOnScreenDebugMessage(-1, 0.01f, FColor::Blue, TEXT("Inventory is full"));
				}
			}
//		}
	}

} //end AddItem

// uses itemname to find object of type in inventory, changes location to nullptr, decrements numberofitems, returns item from inventory
APickup * UPlayerInventory::GetItemInInventory(int index)
{
	// checks if pointer at index is not nullptr
	if (InventoryArray[index])
	{
		// establishes copy of that item to return
		APickup* DesiredItem = InventoryArray[index];

		// makes location of found item nullptr
		InventoryArray[index] = nullptr;

		if (DesiredItem)
		{
<<<<<<< HEAD
			// decrements current number of items, removes weight of found item, updates inventory ui
=======
<<<<<<< HEAD
			// decrements current number of items, removes weight of found item, updates inventory ui
=======
			// decrements current number of items, removes weight of found item
>>>>>>> origin/Eric
>>>>>>> origin/Eric
			if (NumberOfItems > 0)
			{
				NumberOfItems--;
				Player->SubtractFromCurrentWeight(DesiredItem->PickupWeight);
<<<<<<< HEAD
				UpdateInventory();
=======
<<<<<<< HEAD
				UpdateInventory();
=======
>>>>>>> origin/Eric
>>>>>>> origin/Eric
			}
			return DesiredItem;
		}
	}
	return nullptr;

} //end GetItem

// iterates through array and finds first nullptr, returns index
int UPlayerInventory::FirstEmptySlot()
{
	int i;
<<<<<<< HEAD
	for (i = 0; i < InventoryArray.Num(); i++)
=======
<<<<<<< HEAD
	for (i = 0; i < InventoryArray.Num(); i++)
=======
	for (i = 0; i < InventorySize; i++)
>>>>>>> origin/Eric
>>>>>>> origin/Eric
	{
		if (InventoryArray[i] == nullptr)
		{
			return i;
		}
	}
	return -1;
}

<<<<<<< HEAD
// updates inventory UI, mostly done in blueprints
void UPlayerInventory::UpdateInventory()
{
	OnUpdateInventory.Broadcast(InventoryArray);
=======
<<<<<<< HEAD
// updates inventory UI, mostly done in blueprints
void UPlayerInventory::UpdateInventory()
{
	OnUpdateInventory.Broadcast(InventoryArray);
=======
// displays current player inventory
void UPlayerInventory::ShowInventory()
{
	if (GEngine)
	{
		// stores name of object in array
		FString ListObject;

		// iterates through inventory and checks if an object exists, then it prints its itemname
		for (int i = 0; i < InventorySize; i++)
		{
			if (InventoryArray[i])
			{
				ListObject = InventoryArray[i]->PickupName;
				GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Cyan, TEXT("[") + FString::FromInt(i + 1) + TEXT("] ") + FString(ListObject));
			}

		}
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Cyan, TEXT("Current Inventory:"));
	}
>>>>>>> origin/Eric
>>>>>>> origin/Eric

}

// retrieves desired item, and calls its specific activate function
void UPlayerInventory::UseItemFromInventory(int index)
{
	if (GEngine)
	{
		if (Player)
		{
			if (InventoryArray[index])
			{
				// retrieves pickup from inventory, assigns to usableitem
				APickup* UsableItem = GetItemInInventory(index);

				if (UsableItem)
				{
					// activates item, destroy item from existence
<<<<<<< HEAD
=======
<<<<<<< HEAD
>>>>>>> origin/Eric
					if (UsableItem->PickupName == "Battery")
					{
						UsableItem->Activate(Player);
					}
					// batteries do not get destroyed on activation, they get placed in another array, all other pickups do
					else
					{
						UsableItem->Activate(Player);
						UsableItem->Destroy();
					}
					
<<<<<<< HEAD
=======
=======
					UsableItem->Activate(Player);
					UsableItem->Destroy();
					GEngine->AddOnScreenDebugMessage(-1, 3.0f, FColor::Magenta, UsableItem->PickupName + TEXT(" used."));
>>>>>>> origin/Eric
>>>>>>> origin/Eric
				}
			}
		}
	}
}

// drops items from inventory but does not use them
void UPlayerInventory::DropFromInventory(int index)
{
	if (GEngine)
	{
		if (Player)
		{
			if (InventoryArray[index])
			{
				// assigns the found item to be used, removes it from inventory
				APickup* UsableItem = GetItemInInventory(index);

				if (UsableItem)
				{
					// create an instance of pickup on map in current player location
					//SpawnPickup(UsableItem, Player->GetActorLocation(), Player->GetActorRotation());
					GEngine->AddOnScreenDebugMessage(-1, 1.0f, FColor::Blue, UsableItem->PickupName + TEXT(" dropped."));

				}
				else
				{
					GEngine->AddOnScreenDebugMessage(-1, 1.0f, FColor::Blue, TEXT("No item to drop."));
				}
			}
		}
	}
}

<<<<<<< HEAD

// spaws an instance of the item into the world at PlayerRunner location
// try creating a new BP_pickup item at player current location
=======
<<<<<<< HEAD

// spaws an instance of the item into the world at PlayerRunner location
// try creating a new BP_pickup item at player current location
=======
// spaws an instance of the item into the world at PlayerRunner location
>>>>>>> origin/Eric
>>>>>>> origin/Eric
// INCOMPLETE STILL NEEDS WORK!!!
void UPlayerInventory::SpawnPickup(APickup * PickupItem, FVector SpawnLocation, FRotator SpawnRotation)
{
	if (GEngine)
	{
		if (PickupItem)
		{

			/*
			PickupItem->SetActorLocationAndRotation(SpawnLocation, SpawnRotation);

			PickupItem->PickupMesh->SetVisibility(true);
			PickupItem->PickupMesh->SetSimulatePhysics(true);
			PickupItem->PickupMesh->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
			PickupItem->PickupBox->bGenerateOverlapEvents = true;
			*/
		}
	}
}

