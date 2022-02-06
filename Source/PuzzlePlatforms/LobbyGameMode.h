// Create by Ilia Manikhin in 2022

#pragma once

#include "CoreMinimal.h"
#include "PuzzlePlatformsGameMode.h"
#include "LobbyGameMode.generated.h"

/**
 * 
 */
UCLASS()
class PUZZLEPLATFORMS_API ALobbyGameMode : public APuzzlePlatformsGameMode
{
	GENERATED_BODY()

public:
		void PostLogin(APlayerController* NewPlayer) override;

		void Logout(AController* Exiting) override;

private:
	void StartGame();

	uint32 NumberOfPlayers = 0;

	FTimerHandle GameStartTimer;

	//class FTimerManager Timer;
	
};
