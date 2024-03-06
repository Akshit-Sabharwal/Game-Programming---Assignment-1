// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Camera/CameraComponent.h"
#include "Components/StaticMeshComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "GoalPost.generated.h"

UCLASS()
class PONG_API AGoalPost : public AActor
{
	GENERATED_BODY()

public:
	AGoalPost();

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Goal")
	class USceneComponent* Root;

	UPROPERTY(VisibleAnywhere, Category = "Goal")
	class UStaticMeshComponent* VisualMesh;  // Add a mesh component for the cube


	// Add a variable to store whether it's on the AI side or player side
	UPROPERTY(EditInstanceOnly, Category = "Goal")
	bool bIsAISide;

protected:

	UFUNCTION()
	void OnHitActor(AActor* SelfActor, AActor* OtherActor, FVector NormalImpulse, const FHitResult& Hit);


private:
	USoundBase* Sound;

};
