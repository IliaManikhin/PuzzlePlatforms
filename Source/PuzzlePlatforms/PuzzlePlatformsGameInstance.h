// Create by Ilia Manikhin in 2022

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "OnlineSubsystem.h"
#include "Interfaces/OnlineSessionInterface.h"


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
		void Host(FString ServerName) override;

		UFUNCTION(Exec)
		void Join(uint32 Index) override;

		UFUNCTION()
		void LoadMainMenu() override;

		void RefreshServerList() override;

		void StartSession();


private:
	TSubclassOf <class UUserWidget> MenuClass;

	TSubclassOf <class UUserWidget> InGameMenuClass;

	class UMainMenu* Menu;

	class UInGameMenu* InGameMenu;

	IOnlineSessionPtr SessionInterface;

	void OnCreateSessionComplete(FName SessionName, bool Success);
	void OnDestroySessionComplete(FName SessionName, bool Success);
	void OnFindSessionsComplete(bool Success);
	void OnJoinSessionComplete(FName SessionName, EOnJoinSessionCompleteResult::Type Result);

	TSharedPtr<class FOnlineSessionSearch> SessionSearch;

	FString DesiredServerName;

	void CreateSession();
};
