// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
//#include "GrowingPlantBase.h"
#include "SeedFruitBase.generated.h"

UCLASS()
class SEAFOREST_API ASeedFruitBase : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASeedFruitBase();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	bool bCanBePlanted = true;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Stats)
	bool bIsBeingHeld = false;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = Actions)
	void PlantSeed();
	void PlantSeed_Implementation();
	
	/*UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = Actions)
	void SpawnPlant();
	void SpawnPlant_Implementation();*/

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = Actions)
	TSubclassOf<class AActor> PlantToSpawn;
	
};
