// Fill out your copyright notice in the Description page of Project Settings.

#include "SeaForest.h"
#include "GrowingPlantBase.h"



AGrowingPlantBase::AGrowingPlantBase()
{
	PrimaryActorTick.bCanEverTick = true;
}


void AGrowingPlantBase::BeginPlay()
{
	Super::BeginPlay();
	
}


void AGrowingPlantBase::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

	CurrentTime += DeltaTime;

	if (EventTimesArray.Num() > 0 && EventTimesArray.Num() > GrowEventCounter + 1) {
		if (EventTimesArray[GrowEventCounter + 1] <= CurrentTime) {
			GrowEvent();
		}
	}
}

void AGrowingPlantBase::ResetPlant()
{
	GrowEventCounter = -1;
	CurrentTime = 0.f;
}

void AGrowingPlantBase::GrowEvent_Implementation()
{
	GrowEventCounter += 1;
}

void AGrowingPlantBase::DropFruitSeed_Implementation()
{

}

