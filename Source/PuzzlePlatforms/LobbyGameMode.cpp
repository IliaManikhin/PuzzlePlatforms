// Create by Ilia Manikhin in 2022


#include "LobbyGameMode.h"

#include "TimerManager.h"
#include "PuzzlePlatformsGameInstance.h"


void ALobbyGameMode::PostLogin(APlayerController* NewPlayer)
{
	Super::PostLogin(NewPlayer);
	++NumberOfPlayers;
	if (NumberOfPlayers >= 3)
	{
		
		/*
		Timer.SetTimer(TimerHandle, 6.f, false, 0.f);
		UE_LOG(LogTemp, Warning, TEXT("Start timer"));*/
		GetWorldTimerManager().SetTimer(GameStartTimer, this, &ALobbyGameMode::StartGame, 10);

	}

}

void ALobbyGameMode::Logout(AController* Exiting)
{
	Super::Logout(Exiting);
	--NumberOfPlayers;
}

void ALobbyGameMode::StartGame()
{
	auto GameInstance = Cast<UPuzzlePlatformsGameInstance>(GetGameInstance());

	if (GameInstance == nullptr) return;

	GameInstance->StartSession();

	UWorld* World = GetWorld();
	if (!ensure(World != nullptr)) return;

	bUseSeamlessTravel = true;
	World->ServerTravel("/Game/Maps/Game?listen");
}
