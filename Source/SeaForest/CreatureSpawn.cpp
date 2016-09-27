// Fill out your copyright notice in the Description page of Project Settings.

#include "SeaForest.h"
#include "CreatureSpawn.h"


// Sets default values
ACreatureSpawn::ACreatureSpawn()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ACreatureSpawn::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACreatureSpawn::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

void ACreatureSpawn::SpawnCreature(TSubclassOf<ACreatureBase> CreatureToSpawn)
{

}

