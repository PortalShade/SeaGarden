// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "GrowingPlantBase.generated.h"

UCLASS()
class SEAFOREST_API AGrowingPlantBase : public AActor
{
	GENERATED_BODY()
	
public:	
	AGrowingPlantBase();

	virtual void BeginPlay() override;
	
	virtual void Tick( float DeltaSeconds ) override;

	float CurrentTime;

	UFUNCTION(BlueprintCallable, Category = Functions)
	void ResetPlant();

	UFUNCTION(BlueprintNativeEvent, Category = Functions)
	void GrowEvent();
	void GrowEvent_Implementation();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = Functions)
	void DropFruitSeed();
	void DropFruitSeed_Implementation();

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = GrowEvents)
	int32 GrowEventCounter = -1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = GrowEvents)
	TArray<float> EventTimesArray;
	
	
};
