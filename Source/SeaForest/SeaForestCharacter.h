// Copyright 1998-2016 Epic Games, Inc. All Rights Reserved.
#pragma once
#include "GameFramework/Character.h"
#include "SeedFruitBase.h"
#include "SeaForestCharacter.generated.h"

class UInputComponent;

UCLASS(config=Game)
class ASeaForestCharacter : public ACharacter
{
	GENERATED_BODY()

	/** Pawn mesh: 1st person view (arms; seen only by self) */
	UPROPERTY(VisibleDefaultsOnly, Category=Mesh)
	class USkeletalMeshComponent* Mesh1P;

	/** First person camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* FirstPersonCameraComponent;
public:
	ASeaForestCharacter();

	virtual void BeginPlay();

	virtual void Tick(float DeltaSeconds);

	/** Base turn rate, in deg/sec. Other scaling may affect final turn rate. */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Camera)
	float BaseTurnRate;

	/** Base look up/down rate, in deg/sec. Other scaling may affect final rate. */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Camera)
	float BaseLookUpRate;

	UFUNCTION(BlueprintNativeEvent, Category = Actions)
	void Interact();
	void Interact_Implementation();

	UFUNCTION(BlueprintNativeEvent, Category = Actions)
	void PlantHeldSeed();
	void PlantHeldSeed_Implementation();

	FCollisionObjectQueryParams ObjTraceParams;
	FCollisionQueryParams TraceParams;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera)
	FHitResult HitData;

	bool bIsHoldingObject;

	ASeedFruitBase *HeldObject;

protected:
	

	void MoveForward(float Val);

	void MoveRight(float Val);

	void TurnAtRate(float Rate);

	void LookUpAtRate(float Rate);
	
protected:
	// APawn interface
	virtual void SetupPlayerInputComponent(UInputComponent* InputComponent) override;

public:
	/** Returns Mesh1P subobject **/
	FORCEINLINE class USkeletalMeshComponent* GetMesh1P() const { return Mesh1P; }
	/** Returns FirstPersonCameraComponent subobject **/
	FORCEINLINE class UCameraComponent* GetFirstPersonCameraComponent() const { return FirstPersonCameraComponent; }

};

