// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Character.h"
#include "GardenAreaManager.h"
#include "CreatureBase.generated.h"

UCLASS()
class SEAFOREST_API ACreatureBase : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ACreatureBase(const FObjectInitializer& ObjectInitializer);

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = GardenArea)
	class USphereComponent* SearchSphere;

	UFUNCTION(BlueprintNativeEvent)
	void OnSphereOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	void OnSphereOverlapBegin_Implementation(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION(BlueprintNativeEvent)
	void OnSphereOverlapEnd(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);
	void OnSphereOverlapEnd_Implementation(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Spawning)
	FVector EndDestination;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = GardenArea)
	class AGardenAreaManager* MainGardenArea;

	UFUNCTION(BlueprintNativeEvent, Category = Spawning)
	void StartAI();
	void StartAI_Implementation();
	
};
