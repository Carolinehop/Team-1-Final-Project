// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Character.h"
#include "PlayerRunner.generated.h"

UCLASS()
class POWERRUN_API APlayerRunner : public ACharacter
{
	GENERATED_BODY()

	/** Camera boom positioning the camera behind the character */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class USpringArmComponent* CameraBoom;

	/** Follow camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* FollowCamera;

public:
	// Sets default values for this character's properties
	APlayerRunner();

	//Mouse Rates
	float OrbitRate;
	float PitchRate;

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

<<<<<<< HEAD
=======
<<<<<<< HEAD
=======
	UFUNCTION(BlueprintCallable, Category = "Power")
	void AddPower();
>>>>>>> origin/Eric

	/** Eric added this */

<<<<<<< HEAD
	// current weight the player is carrying, used for ui
	UPROPERTY(BlueprintReadWrite, Category = "Inventory")
	float CurrentWeightAdjusted;
=======
>>>>>>> origin/Eric
>>>>>>> origin/Eric

	// returns weight the player is currently holding
	UFUNCTION(BlueprintCallable, Category = "Weight")
	float GetCurrentWeight();

	// returns total weight capacity
	UFUNCTION(BlueprintCallable, Category = "Weight")
	float GetTotalWeight();

	// adds a value to the weight variable
	UFUNCTION(BlueprintCallable, Category = "Weight")
	void AddToCurrentWeight(float AddedWeight);

	// subtracts a value from weight variable
	UFUNCTION(BlueprintCallable, Category = "Weight")
	void SubtractFromCurrentWeight(float SubtractedWeight);

<<<<<<< HEAD
=======
<<<<<<< HEAD
=======
	// adds more power to the current powerlevel
	UFUNCTION(BlueprintCallable, Category = "Power")
	void AddToCurrentPower(float AddedPower);

>>>>>>> origin/Eric
>>>>>>> origin/Eric
	// turns pickup condition true
	UFUNCTION(BlueprintCallable, Category = "Pickup")
	void PickupItemBegin();

	// turns pickup condition false
	UFUNCTION(BlueprintCallable, Category = "Pickup")
	void PickupItemEnd();

	// second pickup condition
	bool bPickingUpItem;

<<<<<<< HEAD
	/** Inventory Functions **/
=======
<<<<<<< HEAD
	/** Inventory Functions **/
=======
>>>>>>> origin/Eric
>>>>>>> origin/Eric
	// creates inventory for PlayerRunner
	UPROPERTY(EditAnywhere)
	class UPlayerInventory* Inventory;

	// displays inventory through debug message
	UFUNCTION(BlueprintCallable, Category = "Inventory")
	void DisplayInventory();

	// functions to use specific items stored in inventory
	UFUNCTION(BlueprintCallable, Category = "Inventory")
	void UseItem1();

	UFUNCTION(BlueprintCallable, Category = "Inventory")
	void UseItem2();

	UFUNCTION(BlueprintCallable, Category = "Inventory")
	void UseItem3();

	UFUNCTION(BlueprintCallable, Category = "Inventory")
	void UseItem4();

	UFUNCTION(BlueprintCallable, Category = "Inventory")
	void UseItem5();

	UFUNCTION(BlueprintCallable, Category = "Inventory")
	void UseItem6();

	// functions to drop specific items in inventory
	UFUNCTION(BlueprintCallable, Category = "Inventory")
	void DropItem1();

	UFUNCTION(BlueprintCallable, Category = "Inventory")
	void DropItem2();

	UFUNCTION(BlueprintCallable, Category = "Inventory")
	void DropItem3();

	UFUNCTION(BlueprintCallable, Category = "Inventory")
	void DropItem4();

	UFUNCTION(BlueprintCallable, Category = "Inventory")
	void DropItem5();

	UFUNCTION(BlueprintCallable, Category = "Inventory")
	void DropItem6();

<<<<<<< HEAD
	UFUNCTION(BlueprintCallable, Category = "BatteryInventory")
	void DropBattery1();

	UFUNCTION(BlueprintCallable, Category = "BatteryInventory")
	void DropBattery2();

	/** BatteryInventory Functions **/
	// creates internal power for player
	UPROPERTY(EditAnywhere)
	class UPlayerInternalPower* InternalPower;

	// needed for deplete power function in internalpower class
	UFUNCTION(BlueprintCallable, Category = "IntenalPower")
	float CalculateDepleteRate();
=======
<<<<<<< HEAD
	UFUNCTION(BlueprintCallable, Category = "BatteryInventory")
	void DropBattery1();

	UFUNCTION(BlueprintCallable, Category = "BatteryInventory")
	void DropBattery2();

	/** BatteryInventory Functions **/
	// creates internal power for player
	UPROPERTY(EditAnywhere)
	class UPlayerInternalPower* InternalPower;

	// needed for deplete power function in internalpower class
	UFUNCTION(BlueprintCallable, Category = "IntenalPower")
	float CalculateDepleteRate();
	
=======
>>>>>>> origin/Eric

	// Jump boost variables
	int JumpCounter;
	bool JumpBoostActivated;

	// Handles the jump boost time limit
	FTimerHandle JumpBoostHandle;

	// returns the jump height to normal, sets jump bool back to false
	void DeActivateJumpBoost();
	

>>>>>>> origin/Eric

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	//Movement functions
	void MoveForward(float Value);
	void MoveRight(float Value);

	//Mouse Controls
	void CameraOrbit(float Value);
	void CameraPitch(float Value);

private:
<<<<<<< HEAD
=======
<<<<<<< HEAD

	float MaxSpeed;
	float Velocity;
=======
	//Internal Power
	float IntPower;
	float MaxIntPower;
>>>>>>> origin/Eric

	float MaxSpeed;
	float Velocity;

<<<<<<< HEAD
=======
>>>>>>> origin/Eric

	/** Eric added these variables */
	// total weight the player can carry
	float TotalWeightCapacity;

	// current weight the player is carrying
>>>>>>> origin/Eric
	float CurrentWeight;
	float TotalWeightCapacity;
	
};
