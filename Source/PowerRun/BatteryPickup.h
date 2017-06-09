// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Pickup.h"
#include "BatteryPickup.generated.h"

/**
 * This is the Battery variant of the Pickup class
 */
UCLASS()
class POWERRUN_API ABatteryPickup : public APickup
{
	GENERATED_BODY()

public:
	// constructor
	ABatteryPickup();


<<<<<<< HEAD
public:
	// amount of power in the battery
	float PowerLevel;

=======
<<<<<<< HEAD
public:
	// amount of power in the battery
	float PowerLevel;

=======
private:
	// the amount of power the batter can provide the player
	float PowerLevel;


public:
>>>>>>> origin/Eric
>>>>>>> origin/Eric
	// adds powerlevel to the player
	UFUNCTION(BlueprintCallable, Category = "BatteryPickup")
	virtual void Activate(AActor* OtherActor);

<<<<<<< HEAD
	UFUNCTION(BlueprintCallable, Category = "BatteryPickup")
	void BatterySubPower(float PowerToLose);

=======
<<<<<<< HEAD
	UFUNCTION(BlueprintCallable, Category = "BatteryPickup")
	void BatterySubPower(float PowerToLose);

=======
>>>>>>> origin/Eric
>>>>>>> origin/Eric
	//TSubclassOf<class ABatteryPickup> BatteryPickupBlueprint;
	
	
};
