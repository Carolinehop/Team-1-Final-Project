// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Hazard.h"
#include "SpikeHazard.generated.h"

/**
 * 
 */
UCLASS()
class POWERRUN_API ASpikeHazard : public AHazard
{
	GENERATED_BODY()
	
public:
	// constructor
	ASpikeHazard();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	
	
};
