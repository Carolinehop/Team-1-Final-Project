// Fill out your copyright notice in the Description page of Project Settings.

#include "PowerRun.h"
#include "PlayerRunner.h"
#include "PlayerInternalPower.h"
#include "BatteryPickup.h"
#include "Hazard.h"
#include "Engine.h"


// Sets default values
AHazard::AHazard()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// initialize variables for default no-type hazard
	HazardType = "";
	AttackCoolDown = 0.0f;
	DamageToPlayer = 0.0f;
	//HazardRange = 60.0f;

	// creates a component to be the root of the hazard Actor, sets it to rootcomponent
	HazardRoot = CreateDefaultSubobject<USceneComponent>(TEXT("HazardRoot"));
	RootComponent = HazardRoot;

	// creates a mesh for the Actor and attaches it to the rootcomponent
	HazardMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("HazardMesh"));
	HazardMesh->AttachToComponent(HazardRoot, FAttachmentTransformRules::SnapToTargetNotIncludingScale);

	// create sphere that surrounds actor
	HazardBox = CreateDefaultSubobject<USphereComponent>(TEXT("HazardBox"));

	// create overlap trigger and call trigger function on enter
	HazardBox->bGenerateOverlapEvents = true;
	HazardBox->OnComponentBeginOverlap.AddDynamic(this, &AHazard::OnEnterHazardRange);
	HazardBox->OnComponentEndOverlap.AddDynamic(this, &AHazard::OnExitHazardRange);
	HazardBox->AttachToComponent(HazardRoot, FAttachmentTransformRules::SnapToTargetNotIncludingScale);
	//HazardBox->SetSphereRadius(HazardRange, true);


}

// Called when the game starts or when spawned
void AHazard::BeginPlay()
{
	Super::BeginPlay();

	bIsInRange = false;
	bIsReady = false;

	
}

// Called every frame
void AHazard::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (GEngine)
	{
		// checks that the hazard is ready to attack and that player is in range
		if (bIsInRange && bIsReady)
		{
			// damages player and begins cooldown
			DamagePlayer(DamageToPlayer);
			bIsReady = false;
			GetWorld()->GetTimerManager().SetTimer(AttackCoolDownHandle, this, &AHazard::CoolDown, AttackCoolDown);

		}
	}
}

// gets player that enters trigger box
void AHazard::GetPlayer(AActor * OtherActor)
{
	Player = Cast<APlayerRunner>(OtherActor);

}

// calls function from internal power class to deal damage to equipped batteries
void AHazard::DamagePlayer(float DamageDealt)
{

	if (GEngine)
	{
		if (Player)
		{
			// if player has two batteries, damage is divided between both
			if (Player->InternalPower->GetNumberOfBatteries() == 2)
			{
				DamageDealt /= 2;
			}
			Player->InternalPower->DamageBatteries(DamageDealt);
		}
	}
}

// uses a timer to change ready status of hazard, so damage loss is not constant
void AHazard::CoolDown()
{
	// if player enters trigger box, timer begins
	if (bIsInRange)
	{
		bIsReady = true;
		GetWorldTimerManager().ClearTimer(AttackCoolDownHandle);
	}
	// timer shuts off if player leaves trigger box
	else
	{
		bIsReady = false;
	}

}

// player enters trigger box
void AHazard::OnEnterHazardRange(UPrimitiveComponent * HitComp, AActor * OtherActor, UPrimitiveComponent * OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
{
	// locate invading object (player) and change range status, begin timer for initial hit
	GetPlayer(OtherActor);
	bIsInRange = true;
	GetWorld()->GetTimerManager().SetTimer(AttackCoolDownHandle, this, &AHazard::CoolDown, AttackCoolDown);

}

// player exits the trigger box
void AHazard::OnExitHazardRange(UPrimitiveComponent * HitComp, AActor * OtherActor, UPrimitiveComponent * OtherComp, int32 OtherBodyIndex)
{
	// player is no longer in range
	bIsInRange = false;

}

