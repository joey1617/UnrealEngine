// Fill out your copyright notice in the Description page of Project Settings.


#include "OnHit.h"
#include "Components/BoxComponent.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
AOnHit::AOnHit()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	MyComp = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxComp"));
	MyComp->SetSimulatePhysics(true);
	MyComp->SetNotifyRigidBodyCollision(true);
	MyComp->BodyInstance.SetCollisionProfileName("BlockAllDynamic");
	MyComp->OnComponentHit.AddDynamic(this, &AOnHit::OnCompHit);

	// Set as root component
	RootComponent = MyComp;

}

// Called when the game starts or when spawned
void AOnHit::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AOnHit::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AOnHit::OnCompHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{

	if ((OtherActor != NULL) && (OtherActor->GetName() == "Player") && (OtherComp != NULL))
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, FString::Printf(TEXT("I Hit: %s"), *OtherActor->GetName()));				
	}
}


