// Fill out your copyright notice in the Description page of Project Settings.

#include "SeaForest.h"
#include "PlantBase.h"


// Sets default values
APlantBase::APlantBase()
{
	PrimaryActorTick.bCanEverTick = true;

}


void APlantBase::BeginPlay()
{
	Super::BeginPlay();
	
}

void APlantBase::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

