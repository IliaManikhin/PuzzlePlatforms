// Create by Ilia Manikhin in 2022


#include "InGameMenu.h"

bool UInGameMenu::Initialize()
{
	bool Success = Super::Initialize();
	if (!Success) return false;

	if (!ensure(CancelInGameMenuButton != nullptr)) return false;
	//CancelInGameMenu->OnClicked.AddDynamic(this, &UInGameMenu::CancelInGameMenu);  // todo method

	return true;
}

void UInGameMenu::CancelInGameMenu()
{
	UE_LOG(LogTemp, Warning, TEXT("Cancel in game menu called"));

}

void UInGameMenu::Setup()
{
	this->AddToViewport();

	UWorld* World = GetWorld();
	if (!ensure(World != nullptr)) return;

	APlayerController* PlayerController = World->GetFirstPlayerController();
	if (!ensure(PlayerController != nullptr)) return;

	FInputModeUIOnly InputModeData;

	InputModeData.SetWidgetToFocus(this->TakeWidget());
	InputModeData.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);

	PlayerController->SetInputMode(InputModeData);
	PlayerController->bShowMouseCursor = true;
}
