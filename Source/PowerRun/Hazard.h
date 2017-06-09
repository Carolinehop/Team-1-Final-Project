// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "PlayerRunner.h"
#include "Hazard.generated.h"

UCLASS()
class POWERRUN_API AHazard : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AHazard();


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// specified name of hazard
	UPROPERTY(EditAnywhere, Category = "Hazard")
	FString HazardType;

	// damage dealt to the player at a given moment
	UPROPERTY(EditAnywhere, Category = "Hazard")
	float DamageToPlayer;

	// time it takes to cool down from attack before next attack
	UPROPERTY(EditAnywhere, Category = "Hazard")
	float AttackCoolDown;

	// keeps track of cool down status
	bool bIsReady;


private:
	// handles attack cooldown timer
	FTimerHandle AttackCoolDownHandle;

	// keeps track of attack range
	bool bIsInRange;

	// radius that sets off the hazard activation upon player enter
	//UPROPERTY(EditAnywhere, Category = "Hazard")
	//float HazardRange;


public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// root component for Pickup
	UPROPERTY(EditAnywhere)
	USceneComponent* HazardRoot;

	// mesh component for Pickup
	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* HazardMesh;

	// box component for Pickup
	UPROPERTY(EditAnywhere)
	USphereComponent* HazardBox;

	// player that entered the trigger box
	UPROPERTY(EditAnywhere)
	APlayerRunner* Player;

	
	
	// gets the overlapping player character to access his internal power
	UFUNCTION(BlueprintCallable, Category = "Hazard")
	void GetPlayer(AActor* OtherActor);

	// removes damage from player batteries
	UFUNCTION(BlueprintCallable, Category = "Hazard")
	void DamagePlayer(float DamageDealt);

	// sets bisactive to false
	void CoolDown();

	// called on player overlap enter
	UFUNCTION()
	void OnEnterHazardRange(class UPrimitiveComponent* HitComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult);
	
	// called on player overlap exit
	UFUNCTION()
	void OnExitHazardRange(class UPrimitiveComponent* HitComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

	
	
};
