// Create by Ilia Manikhin in 2022

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MenuInterface.h"
#include "MainMenu.generated.h"

/**
 * 
 */
UCLASS()
class PUZZLEPLATFORMS_API UMainMenu : public UUserWidget
{
	GENERATED_BODY()

public:
	void SetMenuInterface(IMenuInterface* AMenuInterface);

	void Setup();
	void Teardown();

protected:
	virtual bool Initialize() override;

private:
		UPROPERTY(meta = (BindWidget))
		class UButton* Host;

		UPROPERTY(meta = (BindWidget))
		class UButton* Join;

		UFUNCTION()
		void HostServer();

		IMenuInterface* MenuInterface;
};
