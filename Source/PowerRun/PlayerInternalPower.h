// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Pickup.h"
#include "BatteryPickup.h"
#include "Components/ActorComponent.h"
#include "PlayerInternalPower.generated.h"

/** This is a new component of the Actor class. It is called in the PlayerRunner.h as a component type. */

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FUpdateInternalPowerDelegate, const TArray<ABatteryPickup*>&, BatteryArray);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class POWERRUN_API UPlayerInternalPower : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UPlayerInternalPower();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;	

	// sum of the battery powerlevels
	UPROPERTY(EditAnywhere)
	float TotalInternalPower;
	
	// Adds a battery from the inventory into the battery array
	UFUNCTION(BlueprintCallable, Category = "BatteryInventory")
	void AddToBatteryInventory(ABatteryPickup* NewBattery);

	// Retrieves battery from certain position
	ABatteryPickup* GetBattery(int index);

	// drop from battery inventory if empty
	UFUNCTION(BlueprintCallable, Category = "BatteryInventory")
	void RemoveFromBatteryInventory(int index);

	// find first empty position in battery array
	int FirstEmptyBatteryContainer();

	// check if internal power has no power left
	UFUNCTION(BlueprintCallable, Category = "BatteryInventory")
	bool CheckEmpty();

	// returns the total internal power
	UFUNCTION(BlueprintCallable, Category = "BatteryInventory")
	float GetInternalPower();

	UFUNCTION(BlueprintCallable, Category = "BatteryInventory")
	void UpdateInternalPower();

	UPROPERTY(BlueprintAssignable, Category = "BatteryInventory")
	FUpdateInternalPowerDelegate OnUpdateInternalPower;

<<<<<<< HEAD
	// accessible versions of the current battery power
	UPROPERTY(BlueprintReadWrite, Category = "InternalPower")
	float BatteryPower1;

	UPROPERTY(BlueprintReadWrite, Category = "InternalPower")
	float BatteryPower2;

	// accessors to the array and number of batteries
	UFUNCTION(BlueprintCallable, Category = "InternalPower")
	int GetNumberOfBatteries();

	UFUNCTION(BlueprintCallable, Category = "InternalPower")
	void DamageBatteries(float DamageDealt);

=======
>>>>>>> origin/Eric

private:
	// amount of batteries are equipped
	int NumberOfBatteries;

	// array that holds two batteries
	UPROPERTY(EditAnywhere)
	TArray<ABatteryPickup*> BatteryArray;

	// pointer to player to access its functions
	APlayerRunner* Player;

	// two batteries to start
	ABatteryPickup* StarterBattery1;
	ABatteryPickup* StarterBattery2;

	// depletion calculation variables
	float Velocity;
	float DeltaSeconds;
	float BatteryDivide;

	// returns a depletion calculation variable
	UFUNCTION(BlueprintCallable, Category = "InternalPower")
	float GetBatteryDivide();

	// called every frame to deplete the battery power
	UFUNCTION(BlueprintCallable, Category = "InternalPower")
	void DepleteInternalPower();

	bool bUpdatedAtStart;
	
};
