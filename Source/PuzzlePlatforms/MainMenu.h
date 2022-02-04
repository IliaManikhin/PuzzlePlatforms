// Create by Ilia Manikhin in 2022

#pragma once

#include "CoreMinimal.h"
#include "MenuWidget.h"

#include "MainMenu.generated.h"

USTRUCT()
struct FServerData
{
	GENERATED_BODY()

	FString Name; //Name of the server
	uint16 CurentPlayers; 
	uint16 MaxPlayers; 
	FString HostUserName;
	
};

/**
 * 
 */
UCLASS()
class PUZZLEPLATFORMS_API UMainMenu : public UMenuWidget
{
	GENERATED_BODY()

public:
	UMainMenu(const FObjectInitializer& ObjectInitializer);

	//This method populate the struct 
	void SetServerList(TArray<FServerData> ServerNames);

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
		class UWidget* HostMenu;

		UPROPERTY(meta = (BindWidget))
		class UButton* ConfirmJoinMenuButton;

		UPROPERTY(meta = (BindWidget))
		class UWidget* MainMenu;

		UPROPERTY(meta = (BindWidget))
		class UEditableTextBox* ServerHostName;

		UPROPERTY(meta = (BindWidget))
		class UButton* ConfirmHostMenuButton;

		UPROPERTY(meta = (BindWidget))
		class UButton* CancelHostMenuButton;

		UPROPERTY(meta = (BindWidget))
		class UPanelWidget* ServerList;

		TSubclassOf <class UUserWidget> ServerRowClass;

		UFUNCTION()
		void HostServer();

		UFUNCTION()
		void JoinServer();

		UFUNCTION()
		void OpenHostMenu();

		UFUNCTION()
		void OpenJoinMenu();

		UFUNCTION()
		void OpenMainMenu();

		UFUNCTION()
		void ExitGame();

		TOptional<uint32> SelectedIndex;

		void UpdateChildren();

};
