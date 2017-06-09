// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Pickup.h"
#include "JumpBoostPickup.generated.h"

/**
 * 
 */
UCLASS()
class POWERRUN_API AJumpBoostPickup : public APickup
{
	GENERATED_BODY()
	
public:
	// constructor
	AJumpBoostPickup();

private:
	UPROPERTY(EditAnywhere)
	float NewJumpHeight;


public:

	// changes bisheld status
	UFUNCTION(BlueprintCallable, Category = "JumpBoostPickup")
	void Activate(AActor* OtherActor);

	UFUNCTION(BlueprintCallable, Category = "JumpBoostPickup")
	float GetJumpHeightIncrease();
	
};
