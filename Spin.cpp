// Fill out your copyright notice in the Description page of Project Settings.


#include "Spin.h"

// Sets default values
ASpin::ASpin()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	PitchValue = 0.0f;
	YawValue = 0.0f;
	RollValue = 0.0f;

}

// Called when the game starts or when spawned
void ASpin::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASpin::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FQuat QuatRotation = FQuat(FRotator(PitchValue,YawValue,RollValue));

	AddActorLocalRotation(QuatRotation, false, 0, ETeleportType::None);
}


