// Fill out your copyright notice in the Description page of Project Settings.

#include "SeaForest.h"
#include "CreatureBase.h"


ACreatureBase::ACreatureBase()
{
	PrimaryActorTick.bCanEverTick = true;

}

void ACreatureBase::BeginPlay()
{
	Super::BeginPlay();
	
}

void ACreatureBase::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

void ACreatureBase::SetupPlayerInputComponent(class UInputComponent* InputComponent)
{
	Super::SetupPlayerInputComponent(InputComponent);

}

