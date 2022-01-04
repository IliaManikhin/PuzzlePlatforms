// Fill out your copyright notice in the Description page of Project Settings.


#include "MovingPlatform.h"


AMovingPlatform::AMovingPlatform()
{
	PrimaryActorTick.bCanEverTick = true;
	SetMobility(EComponentMobility::Movable);
}

void AMovingPlatform::BeginPlay()
{
	Super::BeginPlay();
	if (HasAuthority())
	{
		SetReplicates(true);
		SetReplicateMovement(true);
	}
	
}

void AMovingPlatform::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	FVector Location = GetActorLocation();

	if (HasAuthority())
	{
		Location += FVector(Speed * DeltaSeconds, 0, 0);
		SetActorLocation(Location);
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("We are not SERVER"))
		
	}
	

}


