// Create by Ilia Manikhin in 2022

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "ServerRow.generated.h"

/**
 * 
 */
UCLASS()
class PUZZLEPLATFORMS_API UServerRow : public UUserWidget
{
	GENERATED_BODY()

public:

	UPROPERTY(BlueprintReadOnly)
	bool Selected = false;

	UPROPERTY(meta = (BindWidget))
	class UTextBlock* ServerName;

	void Setup(class UMainMenu* InParent, uint32 InIndex);

	UPROPERTY(meta = (BindWidget))
	class UButton* RowButton;

	UPROPERTY()
	class UMainMenu* Parent;

	uint32 Index;

	UFUNCTION()
	void OnClicked();
	
};
