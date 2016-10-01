// Fill out your copyright notice in the Description page of Project Settings.

#include "SeaForest.h"
#include "EngineUtils.h"
#include "CreatureBase.h"


ACreatureBase::ACreatureBase(const FObjectInitializer& ObjectInitializer)
{
	PrimaryActorTick.bCanEverTick = true;

	SearchSphere = ObjectInitializer.CreateDefaultSubobject<USphereComponent>(this, TEXT("SearchSphere"));
	SearchSphere->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Overlap);
	SearchSphere->SetSphereRadius(256.f, true);
	SearchSphere->OnComponentBeginOverlap.AddDynamic(this, &ACreatureBase::OnSphereOverlapBegin);
	SearchSphere->OnComponentEndOverlap.AddDynamic(this, &ACreatureBase::OnSphereOverlapEnd);

}

void ACreatureBase::BeginPlay()
{
	Super::BeginPlay();

	// Gets the main garden area, seems to lag behind by a frame so events after this should be done from StartAI()
	for (TActorIterator<AGardenAreaManager> ActorItr(GetWorld()); ActorItr; ++ActorItr)
	{
		MainGardenArea = *ActorItr;
		StartAI();
	}
}

void ACreatureBase::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

void ACreatureBase::SetupPlayerInputComponent(class UInputComponent* InputComponent)
{
	Super::SetupPlayerInputComponent(InputComponent);

}

void ACreatureBase::OnSphereOverlapBegin_Implementation(UPrimitiveComponent * OverlappedComp, AActor * OtherActor, UPrimitiveComponent * OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
{

}

void ACreatureBase::OnSphereOverlapEnd_Implementation(UPrimitiveComponent * OverlappedComp, AActor * OtherActor, UPrimitiveComponent * OtherComp, int32 OtherBodyIndex)
{

}

void ACreatureBase::StartAI_Implementation()
{

}

