// Fill out your copyright notice in the Description page of Project Settings.

#include "SeaForest.h"
#include "SeedFruitBase.h"


// Sets default values
ASeedFruitBase::ASeedFruitBase()
{
	PrimaryActorTick.bCanEverTick = false;

}

void ASeedFruitBase::BeginPlay()
{
	Super::BeginPlay();
	
}

void ASeedFruitBase::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

void ASeedFruitBase::PlantSeed_Implementation()
{
	if (!bCanBePlanted) { return; }

	FVector ActorLoc = GetActorLocation();
	FVector TraceEnd = GetActorLocation() - FVector(0.f, 0.f, 300.f);

	FCollisionQueryParams TraceParams(FName(TEXT("FireSphereTrace")), false, GetOwner());
	TraceParams.bTraceComplex = false;
	TraceParams.bReturnPhysicalMaterial = false;
	TraceParams.AddIgnoredActor(this);

	FCollisionObjectQueryParams ObjTraceParams = FCollisionObjectQueryParams(); 
	ObjTraceParams.AddObjectTypesToQuery(ECollisionChannel::ECC_WorldStatic);
	ObjTraceParams.AddObjectTypesToQuery(ECollisionChannel::ECC_WorldDynamic);

	FHitResult HitData;

	bool bTrace = GetWorld()->LineTraceSingleByObjectType(HitData, ActorLoc, TraceEnd, ObjTraceParams, TraceParams);

	if (bTrace) {
		FActorSpawnParameters SpawnParams;
		SpawnParams.Owner = this;
		SpawnParams.Instigator = Instigator;
		
		GetWorld()->SpawnActor<AActor>(PlantToSpawn, HitData.Location, FRotator(0.f, 0.f, 0.f), SpawnParams);

		Destroy();
	}
}

