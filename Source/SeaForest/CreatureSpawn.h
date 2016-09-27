// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "CreatureBase.h"
#include "CreatureSpawn.generated.h"

UCLASS()
class SEAFOREST_API ACreatureSpawn : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACreatureSpawn();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	UFUNCTION(BlueprintCallable, Category = Spawning)
	void SpawnCreature(TSubclassOf<ACreatureBase> CreatureToSpawn);
	
};
