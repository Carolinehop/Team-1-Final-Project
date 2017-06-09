// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Pickup.h"
#include "BatteryPickup.h"
#include "Components/ActorComponent.h"
#include "PlayerInventory.generated.h"

/** This is a new component of the Actor class. It is called in the PlayerRunner.h as a component type. */

<<<<<<< HEAD
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FUpdateInventoryDelegate, const TArray<APickup*>&, InventoryArray);

=======
<<<<<<< HEAD
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FUpdateInventoryDelegate, const TArray<APickup*>&, InventoryArray);

=======
>>>>>>> origin/Eric
>>>>>>> origin/Eric
UCLASS( Blueprintable, BlueprintType, ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class POWERRUN_API UPlayerInventory : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UPlayerInventory();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;


private:
<<<<<<< HEAD
=======
<<<<<<< HEAD
	// amount of objects in inventory
	int NumberOfItems;

	UPROPERTY(EditAnywhere)
	TArray<APickup*> InventoryArray;
=======
	// size of the inventory array (6)
	int InventorySize;

>>>>>>> origin/Eric
	// amount of objects in inventory
	int NumberOfItems;

	UPROPERTY(EditAnywhere)
<<<<<<< HEAD
	TArray<APickup*> InventoryArray;
=======
	APickup* InventoryArray[6];
>>>>>>> origin/Eric
>>>>>>> origin/Eric

	// Pointer to PlayerRunner to access its functions
	APlayerRunner* Player;

	//APickup* SpawnedItem;

	UFUNCTION(BlueprintCallable, Category = "Inventory")
	void SpawnPickup(APickup* PickupItem, FVector SpawnLocation, FRotator SpawnRotation);
<<<<<<< HEAD
=======
<<<<<<< HEAD
=======
	
	//TSubclassOf<class ABatteryPickup> BatteryPickupBlueprint;

>>>>>>> origin/Eric
>>>>>>> origin/Eric



public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	// adds new pickup to inventory
	UFUNCTION(BlueprintCallable, Category = "Inventory")
	void AddToInventory(APickup* PickupItem);

	// search inventory array by string itemname, return object with name if in inventory
	APickup* GetItemInInventory(int index);

	int FirstEmptySlot();

	// print out inventory, will eventually be moved to PlayerRunner so it can be bound to an input
	UFUNCTION(BlueprintCallable, Category = "Inventory")
<<<<<<< HEAD
=======
<<<<<<< HEAD
>>>>>>> origin/Eric
	void UpdateInventory();

	UPROPERTY(BlueprintAssignable, Category = "Inventory")
	FUpdateInventoryDelegate OnUpdateInventory;
<<<<<<< HEAD
=======
=======
	void ShowInventory();
>>>>>>> origin/Eric
>>>>>>> origin/Eric

	// Use item, calls check, get and APickup::Activate()
	UFUNCTION(BlueprintCallable, Category = "Inventory")
	void UseItemFromInventory(int index);

	// removes used or dropped items
	UFUNCTION(BlueprintCallable, Category = "Inventory")
	void DropFromInventory(int index);

<<<<<<< HEAD
=======
<<<<<<< HEAD
=======

>>>>>>> origin/Eric
>>>>>>> origin/Eric
};
