// Fill out your copyright notice in the Description page of Project Settings.

#include "SeaForest.h"
#include "GardenAreaManager.h"


// Sets default values
AGardenAreaManager::AGardenAreaManager(const FObjectInitializer& ObjectInitializer)
{
	PrimaryActorTick.bCanEverTick = true;

	GardenArea = ObjectInitializer.CreateDefaultSubobject<UBoxComponent>(this, TEXT("GardenAreaVolume"));
	GardenArea->SetBoxExtent(FVector(256.f, 256.f, 256.f), true);
	GardenArea->OnComponentBeginOverlap.AddDynamic(this, &AGardenAreaManager::OnGAOverlapBegin);
	GardenArea->OnComponentEndOverlap.AddDynamic(this, &AGardenAreaManager::OnGAOverlapEnd);
	GardenArea->SetCollisionObjectType(ECollisionChannel::ECC_EngineTraceChannel1);
}

// Called when the game starts or when spawned
void AGardenAreaManager::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AGardenAreaManager::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

void AGardenAreaManager::OnGAOverlapBegin_Implementation(UPrimitiveComponent * OverlappedComp, AActor * OtherActor, UPrimitiveComponent * OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
{
}

void AGardenAreaManager::OnGAOverlapEnd_Implementation(UPrimitiveComponent * OverlappedComp, AActor * OtherActor, UPrimitiveComponent * OtherComp, int32 OtherBodyIndex)
{
}

// Gets a random location (at floor level) for a creature to move to
FVector AGardenAreaManager::GetRandLocInArea()
{
	float BoxExtentX = GardenArea->GetUnscaledBoxExtent()[0] * 0.95f;
	float BoxExtentY = GardenArea->GetUnscaledBoxExtent()[1] * 0.95f;

	float AxisX = FMath::FRandRange(-BoxExtentX, BoxExtentX);
	float AxisY = FMath::FRandRange(-BoxExtentY, BoxExtentY);

	return (GetActorLocation() + FVector(AxisX, AxisY, 0.f));
}

