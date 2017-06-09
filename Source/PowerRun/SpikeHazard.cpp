// Fill out your copyright notice in the Description page of Project Settings.

#include "PowerRun.h"
#include "SpikeHazard.h"

/** Spike variant of the Hazard class */

ASpikeHazard::ASpikeHazard() : AHazard()
{
	// spikes cause instant death
	HazardType = "Spike";
	DamageToPlayer = 100.0f;

}

void ASpikeHazard::BeginPlay()
{
	Super::BeginPlay();

	// spikes are always ready
	bIsReady = true;

}
