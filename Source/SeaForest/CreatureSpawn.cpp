// Fill out your copyright notice in the Description page of Project Settings.

#include "SeaForest.h"
#include "CreatureSpawn.h"


ACreatureSpawn::ACreatureSpawn()
{
	PrimaryActorTick.bCanEverTick = true;

	SpawnParams.Owner = this;
	SpawnParams.Instigator = Instigator;
}

void ACreatureSpawn::BeginPlay()
{
	Super::BeginPlay();
	
}

void ACreatureSpawn::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

void ACreatureSpawn::SpawnCreature(TSubclassOf<ACreatureBase> CreatureToSpawn)
{
	// Checks a second spawn/end has been set
	if (!SpawnPoint2) {
		return;
	}

	// Create vectors for spawn and end
	FVector SpawnLoc;
	FVector EndLoc;
	int bSpawn2 = FMath::RoundToInt((FMath::FRandRange(0, 1)));
	
	if (bSpawn2 == 0) {
		SpawnLoc = GetActorLocation();
		EndLoc = SpawnPoint2->GetActorLocation();
	}
	else {
		EndLoc = GetActorLocation();
		SpawnLoc = SpawnPoint2->GetActorLocation();
	}

	// Spawn creature and give end destination
	ACreatureBase* SpawnedCreature = GetWorld()->SpawnActor<ACreatureBase>(CreatureToSpawn, SpawnLoc, FRotator(0.f, 0.f, 0.f), SpawnParams);
	SpawnedCreature->EndDestination = EndLoc;
}

