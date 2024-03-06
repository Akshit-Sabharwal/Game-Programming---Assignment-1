// Fill out your copyright notice in the Description page of Project Settings.


#include "GoalPost.h"
#include "Components/SceneComponent.h"
#include "Components/StaticMeshComponent.h"

// Sets default values
AGoalPost::AGoalPost()
{
	// Set this actor to call Tick() every frame
	PrimaryActorTick.bCanEverTick = true;

	Root= CreateDefaultSubobject<USceneComponent>("Actor Root");
	SetRootComponent(Root);

	VisualMesh = CreateDefaultSubobject<UStaticMeshComponent>("Actor Mesh");
	VisualMesh->SetupAttachment(RootComponent);

	// Set default values
	bIsAISide = false;  // Set to true if it's on the AI side

   
	OnActorHit.AddDynamic(this, &AGoalPost::OnHitActor);
}

void AGoalPost::OnHitActor(AActor* SelfActor, AActor* OtherActor, FVector NormalImpulse, const FHitResult& Hit)
{
	// Check if it's the AI side or Player side
	if (AGoalPost::bIsAISide)
	{
		// Custom behavior for collisions on the AI side
		if (GEngine)
		{
			GEngine->AddOnScreenDebugMessage(2, 10.f, FColor::Red, TEXT("Hit Actor on AI Side"));
		}
	}
	else
	{
		// Custom behavior for collisions on the Player side
		if (GEngine)
		{
			GEngine->AddOnScreenDebugMessage(2, 10.f, FColor::Green, TEXT("Hit Actor on Player Side"));
		}
	}
}

