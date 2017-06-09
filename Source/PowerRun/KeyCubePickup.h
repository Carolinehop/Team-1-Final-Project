// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Pickup.h"
#include "KeyCubePickup.generated.h"

/**
 * This is the key cube variant of the pickup class
 */
UCLASS()
class POWERRUN_API AKeyCubePickup : public APickup
{
	GENERATED_BODY()
	
public:
	// constructor
	AKeyCubePickup();

private:
	
	

public:

	// changes bisheld status
	UFUNCTION(BlueprintCallable, Category = "KeyCubePickup")
	void Activate(AActor* OtherActor);

	// creates new object to drop in current location, destroys old one
	UFUNCTION(BlueprintCallable, Category = "KeyCubePickup")
	void DropHere();

	TSubclassOf<class AKeyCubePickup> NewKeyCube;
	
};
