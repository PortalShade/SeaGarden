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
	ACreatureSpawn();

	virtual void BeginPlay() override;
	
	virtual void Tick( float DeltaSeconds ) override;

	FActorSpawnParameters SpawnParams;

	UFUNCTION(BlueprintCallable, Category = Spawning)
	void SpawnCreature(TSubclassOf<ACreatureBase> CreatureToSpawn);
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Spawning)
	class AActor* SpawnPoint2;

};
