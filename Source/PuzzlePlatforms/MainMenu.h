// Create by Ilia Manikhin in 2022

#pragma once

#include "CoreMinimal.h"
#include "MenuWidget.h"

#include "MainMenu.generated.h"

/**
 * 
 */
UCLASS()
class PUZZLEPLATFORMS_API UMainMenu : public UMenuWidget
{
	GENERATED_BODY()

public:
	UMainMenu(const FObjectInitializer& ObjectInitializer);

	void SetServerList(TArray<FString> ServerNames);

	void SelectIndex(uint32 Index);

protected:
	virtual bool Initialize() override;

private:
		UPROPERTY(meta = (BindWidget))
		class UButton* HostButton;

		UPROPERTY(meta = (BindWidget))
		class UButton* JoinButton;

		UPROPERTY(meta = (BindWidget))
		class UButton* ExitGameButton;

		UPROPERTY(meta = (BindWidget))
		class UButton* CancelJoinMenuButton;

		UPROPERTY(meta = (BindWidget))
		class UWidgetSwitcher* MenuSwitcher;

		UPROPERTY(meta = (BindWidget))
		class UWidget* JoinMenu;

		UPROPERTY(meta = (BindWidget))
		class UButton* ConfirmJoinMenuButton;

		UPROPERTY(meta = (BindWidget))
		class UWidget* MainMenu;

		UPROPERTY(meta = (BindWidget))
		class UPanelWidget* ServerList;

		TSubclassOf <class UUserWidget> ServerRowClass;

		UFUNCTION()
		void HostServer();

		UFUNCTION()
		void JoinServer();

		UFUNCTION()
		void OpenJoinMenu();

		UFUNCTION()
		void OpenMainMenu();

		UFUNCTION()
		void ExitGame();

		TOptional<uint32> SelectedIndex;

};
