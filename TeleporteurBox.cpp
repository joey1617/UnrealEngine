// Fill out your copyright notice in the Description page of Project Settings.
#include "TeleporteurBox.h"

ATeleporteurBox::ATeleporteurBox()
{
	OnActorBeginOverlap.AddDynamic(this, &ATeleporteurBox::EnterTeleporteur);
	OnActorEndOverlap.AddDynamic(this, &ATeleporteurBox::ExitTeleporteur);
	teleporting = false;

}

void ATeleporteurBox::BeginPlay()
{
	Super::BeginPlay();
}

void ATeleporteurBox::EnterTeleporteur(class AActor* overlappedActor, class AActor* otherActor) {
	if (otherActor && otherActor != this)
	{
		if (otherTele)
		{
			AProjetSessionCharacter* character = Cast<AProjetSessionCharacter>(otherActor);
			if (character && !otherTele->teleporting)
			{
				teleporting = true;
				character->SetActorRotation(otherTele->GetActorRotation());
				character->GetController()->SetControlRotation(character->GetActorRotation());
				character->SetActorLocation(otherTele->GetActorLocation());
			}
		}
	}
}

void ATeleporteurBox::ExitTeleporteur(class AActor* overlappedActor, class AActor* otherActor) {

	if (otherActor && otherActor != this)
	{
		if (otherTele && !teleporting)
		{
			otherTele->teleporting = false;
		}
	}
}