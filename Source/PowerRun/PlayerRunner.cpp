// Fill out your copyright notice in the Description page of Project Settings.

#include "PowerRun.h"
#include "PlayerRunner.h"
#include "PlayerInventory.h"
<<<<<<< HEAD
#include "PlayerInternalPower.h"
#include "BatteryPickup.h"
=======
<<<<<<< HEAD
#include "PlayerInternalPower.h"
#include "BatteryPickup.h"
=======
>>>>>>> origin/Eric
>>>>>>> origin/Eric
#include "Engine.h"


// Sets default values
APlayerRunner::APlayerRunner()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//Dont let pawn rotations be affected by controller. Must be above Camera Components
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	//Character movement settings
	GetCharacterMovement()->JumpZVelocity = 600.f;
	GetCharacterMovement()->AirControl = 0.0f;

	//Mouse Rates
	OrbitRate = 45.0f;
	PitchRate = 45.0f;

	//Create Camera Boom
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->TargetArmLength = 300.0f; // The camera follows at this distance behind the character	
	CameraBoom->bUsePawnControlRotation = true; // Rotate the arm based on the controller

	//Create Camera
	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	FollowCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName); // Attach the camera to the end of the boom and let the boom adjust to match the controller orientation
	FollowCamera->bUsePawnControlRotation = false; // Camera does not rotate relative to arm


	/*** Eric added these variables in */
	// weight variables
<<<<<<< HEAD
	TotalWeightCapacity = 25.0f;
=======
<<<<<<< HEAD
	TotalWeightCapacity = 25.0f;
	CurrentWeight = 0.0;

	// inventory and internal power component initialization
	Inventory = CreateDefaultSubobject<UPlayerInventory>(TEXT("Inventory"));
	InternalPower = CreateDefaultSubobject<UPlayerInternalPower>(TEXT("InternalPower"));

	
}

=======
	TotalWeightCapacity = 20.0f;
>>>>>>> origin/Eric
	CurrentWeight = 0.0;

	// inventory and internal power component initialization
	Inventory = CreateDefaultSubobject<UPlayerInventory>(TEXT("Inventory"));
	InternalPower = CreateDefaultSubobject<UPlayerInternalPower>(TEXT("InternalPower"));

	JumpCounter = 0;
	JumpBoostActivated = false;

	
}

// returns jump height to normal after jump boost pickup is used
void APlayerRunner::DeActivateJumpBoost()
{
	GetCharacterMovement()->JumpZVelocity = 600.0f;
	GetWorldTimerManager().ClearTimer(JumpBoostHandle);
}

>>>>>>> origin/Eric
// Called when the game starts or when spawned
void APlayerRunner::BeginPlay()
{
	Super::BeginPlay();

<<<<<<< HEAD
=======
<<<<<<< HEAD
=======
	MaxIntPower = 100.0f;
	IntPower = 100.0f;
>>>>>>> origin/Eric
>>>>>>> origin/Eric
	MaxSpeed = GetCharacterMovement()->GetMaxSpeed();

	/** Eric added this boolean */
	// second condition for item pickup
	bPickingUpItem = false;

<<<<<<< HEAD
=======
<<<<<<< HEAD
=======

>>>>>>> origin/Eric
>>>>>>> origin/Eric
}

// Called every frame
void APlayerRunner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
<<<<<<< HEAD
=======
<<<<<<< HEAD
	
	// find velocity for use in internalpower class
	Velocity = GetVelocity().Size();
	
	if (GEngine) {
		GEngine->AddOnScreenDebugMessage(-1, 0.01f, FColor::Yellow, TEXT("Weight: ") + FString::SanitizeFloat(CurrentWeight) + TEXT("/") + FString::SanitizeFloat(TotalWeightCapacity));

	}

=======
	if (GEngine) {
		GEngine->AddOnScreenDebugMessage(-1, 0.01f, FColor::Red, TEXT("Internal Power: ") + FString::SanitizeFloat(IntPower));
		GEngine->AddOnScreenDebugMessage(-1, 0.01f, FColor::Yellow, TEXT("Weight: ") + FString::SanitizeFloat(CurrentWeight) + TEXT("/") + FString::SanitizeFloat(TotalWeightCapacity));

	}
>>>>>>> origin/Eric
	
	// find velocity for use in internalpower class
	Velocity = GetVelocity().Size();

	if (JumpBoostActivated)
	{
		JumpBoostActivated = false;
		GetWorld()->GetTimerManager().SetTimer(JumpBoostHandle, this, &APlayerRunner::DeActivateJumpBoost, 5.0f);
	}

<<<<<<< HEAD
	// adjusting weight variables for ui
	CurrentWeightAdjusted = CurrentWeight / TotalWeightCapacity;

=======
	
>>>>>>> origin/Eric
>>>>>>> origin/Eric
}

// Called to bind functionality to input
void APlayerRunner::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	//Bind movement keys
	check(PlayerInputComponent);
	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ACharacter::Jump);
	PlayerInputComponent->BindAction("Jump", IE_Released, this, &ACharacter::StopJumping);
	PlayerInputComponent->BindAxis("MoveForward", this, &APlayerRunner::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &APlayerRunner::MoveRight);

	//Bind mouse inputs
	PlayerInputComponent->BindAxis("Turn", this, &APawn::AddControllerYawInput);
	PlayerInputComponent->BindAxis("Lookup", this, &APawn::AddControllerPitchInput);

<<<<<<< HEAD
=======
<<<<<<< HEAD
=======
	//Bind Power keys
	PlayerInputComponent->BindAction("AddPower", IE_Pressed, this, &APlayerRunner::AddPower);
	PlayerInputComponent->BindAction("SubPower", IE_Pressed, this, &APlayerRunner::SubPower);

>>>>>>> origin/Eric
>>>>>>> origin/Eric
	/**Eric added this in*/
	// Bind item pickup to input
	PlayerInputComponent->BindAction("PickupItem", IE_Pressed, this, &APlayerRunner::PickupItemBegin);
	PlayerInputComponent->BindAction("PickupItem", IE_Released, this, &APlayerRunner::PickupItemEnd);

	// Bind inventory display to input
	PlayerInputComponent->BindAction("DisplayInventory", IE_Pressed, this, &APlayerRunner::DisplayInventory);

	// Bind useitem keys to 1 - 6
	PlayerInputComponent->BindAction("Item1", IE_Pressed, this, &APlayerRunner::UseItem1);
	PlayerInputComponent->BindAction("DItem1", IE_Pressed, this, &APlayerRunner::DropItem1);
	PlayerInputComponent->BindAction("Item2", IE_Pressed, this, &APlayerRunner::UseItem2);
	PlayerInputComponent->BindAction("DItem2", IE_Pressed, this, &APlayerRunner::DropItem2);
	PlayerInputComponent->BindAction("Item3", IE_Pressed, this, &APlayerRunner::UseItem3);
	PlayerInputComponent->BindAction("DItem3", IE_Pressed, this, &APlayerRunner::DropItem3);
	PlayerInputComponent->BindAction("Item4", IE_Pressed, this, &APlayerRunner::UseItem4);
	PlayerInputComponent->BindAction("DItem4", IE_Pressed, this, &APlayerRunner::DropItem4);
	PlayerInputComponent->BindAction("Item5", IE_Pressed, this, &APlayerRunner::UseItem5);
	PlayerInputComponent->BindAction("DItem5", IE_Pressed, this, &APlayerRunner::DropItem5);
	PlayerInputComponent->BindAction("Item6", IE_Pressed, this, &APlayerRunner::UseItem6);
	PlayerInputComponent->BindAction("DItem6", IE_Pressed, this, &APlayerRunner::DropItem6);
<<<<<<< HEAD
=======
<<<<<<< HEAD
>>>>>>> origin/Eric

	// Bind test function to key alt
	PlayerInputComponent->BindAction("DBattery1", IE_Pressed, this, &APlayerRunner::DropBattery1);
	PlayerInputComponent->BindAction("DBattery2", IE_Pressed, this, &APlayerRunner::DropBattery2);
<<<<<<< HEAD
=======
=======
>>>>>>> origin/Eric
>>>>>>> origin/Eric
	
}

void APlayerRunner::MoveForward(float Value)
{
	if ((Controller != NULL) && (Value != 0.0f))
	{
		// find out which way is forward
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);

		// get forward vector
		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
		AddMovementInput(Direction, Value);
	}
}

void APlayerRunner::MoveRight(float Value)
{
	if ((Controller != NULL) && (Value != 0.0f))
	{
		// find out which way is right
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);

		// get right vector 
		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
		// add movement in that direction
		AddMovementInput(Direction, Value);
	}
}

void APlayerRunner::CameraOrbit(float Value)
{
	AddControllerYawInput(Value * OrbitRate * GetWorld()->GetDeltaSeconds());
}

void APlayerRunner::CameraPitch(float Value)
{
	AddControllerPitchInput(Value * PitchRate * GetWorld()->GetDeltaSeconds());
}

<<<<<<< HEAD
=======
<<<<<<< HEAD

// returns the rate at which power should be depleted
float APlayerRunner::CalculateDepleteRate()
{
	float DepleteRate;

	// if player is not moving, he loses no power
	if (Velocity == 0)
	{
		DepleteRate = 0.0f;
	}
	// if player is moving, he loses health depending on his velocity and current weight
	else
	{
		DepleteRate = (1 / MaxSpeed) * (1 + CurrentWeight / TotalWeightCapacity);
	}

	return DepleteRate;
=======
void APlayerRunner::AddPower()
{

	IntPower++;
}
>>>>>>> origin/Eric

// returns the rate at which power should be depleted
float APlayerRunner::CalculateDepleteRate()
{
	float DepleteRate;

	// if player is not moving, he loses no power
	if (Velocity == 0)
	{
		DepleteRate = 0.0f;
	}
	// if player is moving, he loses health depending on his velocity and current weight
	else
	{
		DepleteRate = (1 / MaxSpeed) * (1 + CurrentWeight / TotalWeightCapacity);
	}
<<<<<<< HEAD

	return DepleteRate;
=======
>>>>>>> origin/Eric
>>>>>>> origin/Eric
}


/*** Eric added these functions in */
// returns current weight
float APlayerRunner::GetCurrentWeight()
{
	return CurrentWeight;
}

float APlayerRunner::GetTotalWeight()
{
	return TotalWeightCapacity;
}

// adds item weight to current weight
void APlayerRunner::AddToCurrentWeight(float AddedWeight)
{
	CurrentWeight += AddedWeight;
		
}

void APlayerRunner::SubtractFromCurrentWeight(float SubtractedWeight)
{
	CurrentWeight -= SubtractedWeight;
}

<<<<<<< HEAD
=======
<<<<<<< HEAD
=======
// adds item powerlevel to current powerlevel
void APlayerRunner::AddToCurrentPower(float AddedPower)
{
	if (IntPower + AddedPower > MaxIntPower)
	{
		IntPower = MaxIntPower;
	}
	else
	{
		IntPower += AddedPower;
	}

}

>>>>>>> origin/Eric
>>>>>>> origin/Eric
// changes pickup condition to true
void APlayerRunner::PickupItemBegin()
{
	bPickingUpItem = true;

}

// changes pickup condition to false
void APlayerRunner::PickupItemEnd()
{
	bPickingUpItem = false;

}

// displays the inventory when pushing a key
void APlayerRunner::DisplayInventory()
{
<<<<<<< HEAD
	GEngine->AddOnScreenDebugMessage(-1, 0.5f, FColor::Blue, TEXT("Delete Item?"));
}

// goes through inventory and activates item in numbered slot
=======
<<<<<<< HEAD
	GEngine->AddOnScreenDebugMessage(-1, 0.5f, FColor::Blue, TEXT("Delete Item?"));
}

// goes through inventory and activates item in numbered slot
=======
	Inventory->ShowInventory();
}


>>>>>>> origin/Eric
>>>>>>> origin/Eric
void APlayerRunner::UseItem1()
{

	Inventory->UseItemFromInventory(0);
}

void APlayerRunner::UseItem2()
{

	Inventory->UseItemFromInventory(1);
}

void APlayerRunner::UseItem3()
{

	Inventory->UseItemFromInventory(2);
}

void APlayerRunner::UseItem4()
{

	Inventory->UseItemFromInventory(3);
}

void APlayerRunner::UseItem5()
{

	Inventory->UseItemFromInventory(4);
}

void APlayerRunner::UseItem6()
{

	Inventory->UseItemFromInventory(5);
}

<<<<<<< HEAD
// goes through inventory and removes item from numbered slot without use
=======
<<<<<<< HEAD
// goes through inventory and removes item from numbered slot without use
=======
>>>>>>> origin/Eric
>>>>>>> origin/Eric
void APlayerRunner::DropItem1()
{

	Inventory->DropFromInventory(0);
}

void APlayerRunner::DropItem2()
{

	Inventory->DropFromInventory(1);
}

void APlayerRunner::DropItem3()
{

	Inventory->DropFromInventory(2);
}

void APlayerRunner::DropItem4()
{

	Inventory->DropFromInventory(3);
}

void APlayerRunner::DropItem5()
{

	Inventory->DropFromInventory(4);
}

void APlayerRunner::DropItem6()
{

	Inventory->DropFromInventory(5);
<<<<<<< HEAD
=======
<<<<<<< HEAD
>>>>>>> origin/Eric
}

void APlayerRunner::DropBattery1()
{
	InternalPower->RemoveFromBatteryInventory(0);
}

void APlayerRunner::DropBattery2()
{
	InternalPower->RemoveFromBatteryInventory(1);
}

<<<<<<< HEAD
=======
=======
}
>>>>>>> origin/Eric
>>>>>>> origin/Eric
