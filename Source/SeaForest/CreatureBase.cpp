// Fill out your copyright notice in the Description page of Project Settings.

#include "SeaForest.h"
#include "CreatureBase.h"


// Sets default values
ACreatureBase::ACreatureBase()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ACreatureBase::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACreatureBase::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

// Called to bind functionality to input
void ACreatureBase::SetupPlayerInputComponent(class UInputComponent* InputComponent)
{
	Super::SetupPlayerInputComponent(InputComponent);

}

