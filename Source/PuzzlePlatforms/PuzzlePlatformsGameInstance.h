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
		void LoadMenuWidget();

		UFUNCTION(BlueprintCallable)
		void InGameLoadMenu();

		UFUNCTION(Exec)
		void Host() override;

		UFUNCTION(Exec)
		void Join(const FString& Address) override;

		UFUNCTION()
		void LoadMainMenu() override;


private:
	TSubclassOf <class UUserWidget> MenuClass;

	TSubclassOf <class UUserWidget> InGameMenuClass;

	class UMainMenu* Menu;

	class UInGameMenu* InGameMenu;
	
};
