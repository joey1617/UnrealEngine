// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/TriggerBox.h"
#include "GameFramework/Actor.h"
#include "GameFramework/SpringArmComponent.h"
#include "ProjetSessionCharacter.h"
#include "TeleporteurBox.generated.h"
/**
 * 
 */
UCLASS()
class PROJETSESSION_API ATeleporteurBox : public ATriggerBox
{
	GENERATED_BODY()

protected:
	virtual void BeginPlay() override;

public:
	ATeleporteurBox();

	UFUNCTION()
		void EnterTeleporteur(class AActor* overlappedActor, class AActor* otherActor);
	UFUNCTION()
		void ExitTeleporteur(class AActor* overlappedActor, class AActor* otherActor);
	UPROPERTY(EditAnywhere, Category = "Teleporteur")
		ATeleporteurBox* otherTele;
	UPROPERTY()
		bool teleporting;
	
};


