// Copyright 1998-2016 Epic Games, Inc. All Rights Reserved.

#include "SeaForest.h"
#include "SeaForestCharacter.h"
#include "SeedFruitBase.h"
#include "Animation/AnimInstance.h"
#include "GameFramework/InputSettings.h"

DEFINE_LOG_CATEGORY_STATIC(LogFPChar, Warning, All);

//////////////////////////////////////////////////////////////////////////
// ASeaForestCharacter

ASeaForestCharacter::ASeaForestCharacter()
{
	// Set size for collision capsule
	GetCapsuleComponent()->InitCapsuleSize(55.f, 96.0f);

	// set our turn rates for input
	BaseTurnRate = 45.f;
	BaseLookUpRate = 45.f;

	// Create a CameraComponent	
	FirstPersonCameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("FirstPersonCamera"));
	FirstPersonCameraComponent->SetupAttachment(GetCapsuleComponent());
	FirstPersonCameraComponent->RelativeLocation = FVector(-39.56f, 1.75f, 64.f); // Position the camera
	FirstPersonCameraComponent->bUsePawnControlRotation = true;

	// Create a mesh component that will be used when being viewed from a '1st person' view (when controlling this pawn)
	Mesh1P = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("CharacterMesh1P"));
	Mesh1P->SetOnlyOwnerSee(true);
	Mesh1P->SetupAttachment(FirstPersonCameraComponent);
	Mesh1P->bCastDynamicShadow = false;
	Mesh1P->CastShadow = false;
	Mesh1P->RelativeRotation = FRotator(1.9f, -19.19f, 5.2f);
	Mesh1P->RelativeLocation = FVector(-0.5f, -4.4f, -155.7f);

	// Trace Parameter stuff
	FCollisionQueryParams TraceParams(FName(TEXT("TraceParams")), false, GetOwner());
	TraceParams.bTraceComplex = false;
	TraceParams.bReturnPhysicalMaterial = false;
	TraceParams.AddIgnoredActor(this);

	FCollisionObjectQueryParams ObjTraceParams = FCollisionObjectQueryParams();

}

void ASeaForestCharacter::BeginPlay()
{
	Super::BeginPlay();
	
	ObjTraceParams.AddObjectTypesToQuery(ECollisionChannel::ECC_WorldStatic);
	ObjTraceParams.AddObjectTypesToQuery(ECollisionChannel::ECC_WorldDynamic);
}


void ASeaForestCharacter::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	if (bIsHoldingObject) {
		HeldObject->SetActorLocation((GetActorLocation() + FVector(0.f, 0.f, 50.f)) + (FirstPersonCameraComponent->GetComponentRotation().Vector() * 200.f));
	}
}

//////////////////////////////////////////////////////////////////////////
// Input

void ASeaForestCharacter::SetupPlayerInputComponent(class UInputComponent* InputComponent)
{
	// set up gameplay key bindings
	check(InputComponent);

	InputComponent->BindAction("Jump", IE_Pressed, this, &ACharacter::Jump);
	InputComponent->BindAction("Jump", IE_Released, this, &ACharacter::StopJumping);
	InputComponent->BindAction("Interact", IE_Pressed, this, &ASeaForestCharacter::Interact);
	InputComponent->BindAction("Plant", IE_Pressed, this, &ASeaForestCharacter::PlantHeldSeed);

	InputComponent->BindAxis("MoveForward", this, &ASeaForestCharacter::MoveForward);
	InputComponent->BindAxis("MoveRight", this, &ASeaForestCharacter::MoveRight);

	// We have 2 versions of the rotation bindings to handle different kinds of devices differently
	// "turn" handles devices that provide an absolute delta, such as a mouse.
	// "turnrate" is for devices that we choose to treat as a rate of change, such as an analog joystick
	InputComponent->BindAxis("Turn", this, &APawn::AddControllerYawInput);
	InputComponent->BindAxis("TurnRate", this, &ASeaForestCharacter::TurnAtRate);
	InputComponent->BindAxis("LookUp", this, &APawn::AddControllerPitchInput);
	InputComponent->BindAxis("LookUpRate", this, &ASeaForestCharacter::LookUpAtRate);

}

// Interact action for picking up objects, making seeds drop, etc
void ASeaForestCharacter::Interact_Implementation()
{
	if (bIsHoldingObject) {
		bIsHoldingObject = false;
		return;
	}

	FVector TraceStart = GetActorLocation() + FVector(0.f, 0.f, 50.f);
	FVector TraceEnd = TraceStart + (FirstPersonCameraComponent->GetComponentRotation().Vector() * 300.f);

	bool bTrace = GetWorld()->LineTraceSingleByObjectType(HitData, TraceStart, TraceEnd, ObjTraceParams, TraceParams);

	if (bTrace) {
		HeldObject = Cast<ASeedFruitBase>(HitData.GetActor());

		if (HeldObject) {
			bIsHoldingObject = true;
		}
	}
}

// Trys to plant the seed that is being held currently
void ASeaForestCharacter::PlantHeldSeed_Implementation()
{
	if (bIsHoldingObject) {
		Cast<ASeedFruitBase>(HeldObject)->PlantSeed();
		bIsHoldingObject = false;
	}
}

void ASeaForestCharacter::MoveForward(float Value)
{
	if (Value != 0.0f)
	{
		// add movement in that direction
		AddMovementInput(GetActorForwardVector(), Value);
	}
}

void ASeaForestCharacter::MoveRight(float Value)
{
	if (Value != 0.0f)
	{
		// add movement in that direction
		AddMovementInput(GetActorRightVector(), Value);
	}
}

void ASeaForestCharacter::TurnAtRate(float Rate)
{
	// calculate delta for this frame from the rate information
	AddControllerYawInput(Rate * BaseTurnRate * GetWorld()->GetDeltaSeconds());
}

void ASeaForestCharacter::LookUpAtRate(float Rate)
{
	// calculate delta for this frame from the rate information
	AddControllerPitchInput(Rate * BaseLookUpRate * GetWorld()->GetDeltaSeconds());
}