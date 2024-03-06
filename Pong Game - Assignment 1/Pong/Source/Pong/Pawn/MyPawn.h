// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Camera/CameraComponent.h"
#include "Components/StaticMeshComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "MyPawn.generated.h"

UCLASS()
class PONG_API AMyPawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AMyPawn();

	UPROPERTY(EditAnywhere, Category = "My Pawn")
	USceneComponent* SceneComponent;

	/*The pawns StaticMeshComponent, this will the Pawns visual*/
	UPROPERTY(EditAnywhere, Category = "My Pawn")
	UStaticMeshComponent* StaticMeshComponent;

	/*The pawns SpringArmComponent, this is the camera boom and will be attached to the RootComponent*/
	UPROPERTY(EditAnywhere, Category = "My Pawn")
	USpringArmComponent* SpringArmComponent;

	/*The pawns CameraComponent, this will be attached to the SpringArmComponent*/
	UPROPERTY(EditAnywhere, Category = "My Pawn")
	UCameraComponent* CameraComponent;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
