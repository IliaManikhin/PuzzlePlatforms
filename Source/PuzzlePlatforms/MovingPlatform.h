// Create by Ilia Manikhin in 2022

#pragma once

#include "CoreMinimal.h"
#include "Engine/StaticMeshActor.h"
#include "MovingPlatform.generated.h"

/**
 * 
 */
UCLASS()
class PUZZLEPLATFORMS_API AMovingPlatform : public AStaticMeshActor
{
	GENERATED_BODY()

public:
		AMovingPlatform();

		void AddActiveTrigger();
		void RemoveActiveTrigger();

protected:

	virtual void BeginPlay() override;

		virtual void Tick(float DeltaSeconds) override;

		UPROPERTY(EditAnywhere)
		float Speed = 20;

		UPROPERTY(EditAnywhere, Meta = (MakeEditWidget = true))
		FVector TargetLocation;

		

private:
	FVector GlobalTargetLocation;
	FVector GlobalStartLocation;
	
	UPROPERTY(EditAnywhere)
	int ActiveTriggers = 1;

};
