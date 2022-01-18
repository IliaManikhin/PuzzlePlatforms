// Create by Ilia Manikhin in 2022

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "MenuInterface.h"
#include "PuzzlePlatformsGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class PUZZLEPLATFORMS_API UPuzzlePlatformsGameInstance : public UGameInstance, public IMenuInterface
{
	GENERATED_BODY()

public:
		UPuzzlePlatformsGameInstance(const FObjectInitializer & ObjectInitializer);

		virtual void Init();

		UFUNCTION(BlueprintCallable)
		void LoadMenu();

		UFUNCTION(Exec)
		void Host();

		UFUNCTION(Exec)
		void Join(const FString& Address);

private:
	TSubclassOf <class UUserWidget> MenuClass;
	
};
