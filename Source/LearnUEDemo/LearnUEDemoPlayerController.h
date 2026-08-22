// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
//#include "Templates/SubclassOf.h"
#include "GameFramework/PlayerController.h"
#include "InputActionValue.h"
#include "LearnUEDemoPlayerController.generated.h"


class UNiagaraSystem;
class UInputMappingContext;
class UInputAction;
class UPathFollowingComponent;

DECLARE_LOG_CATEGORY_EXTERN(LogTemplateCharacter, Log, All);

/**
 *  Player controller for a top-down perspective game.
 *  Implements point and click based controls
 */
UCLASS(abstract)
class ALearnUEDemoPlayerController : public APlayerController
{
	GENERATED_BODY()

protected:
	/** Component used for moving along a NavMesh path. */
	UPROPERTY(VisibleDefaultsOnly, Category = AI)
	TObjectPtr<UPathFollowingComponent> PathFollowingComponent;

	/** MappingContext */
	UPROPERTY(EditAnywhere, Category="Input")
	TObjectPtr<UInputMappingContext> DefaultMappingContext;

	/** True if the controlled character should navigate to the mouse cursor. */
	uint32 bMoveToMouseCursor : 1;

	/** Set to true if we're using touch input */
	uint32 bIsTouch : 1;
	UPROPERTY(EditAnywhere)
	float speed;
	
	UPROPERTY(EditAnywhere, Category="Input")
	TObjectPtr<UInputAction> MovementInput;

public:
	/** Constructor */
	ALearnUEDemoPlayerController();

protected:
	/** Initialize input bindings */
	virtual void SetupInputComponent() override;

	/** Helper function to get the move destination */
	void UpdateCachedDestination();

	void Move(const FInputActionValue& Value);
};
