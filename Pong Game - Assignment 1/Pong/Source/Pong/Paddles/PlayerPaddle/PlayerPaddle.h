// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Camera/CameraComponent.h"
#include "Components/StaticMeshComponent.h"

#include "Components/BoxComponent.h"
#include "PlayerPaddle.generated.h"

UCLASS()
class PONG_API APlayerPaddle : public APawn
{
	GENERATED_BODY()

	UPROPERTY(EditDefaultsOnly, Category = "My Pawn")
	UBoxComponent* BoxRoot;
	/*The Pawns SceneComponent. This will be set as the Root Component*/
	UPROPERTY(EditAnywhere, Category = "My Pawn")
	USceneComponent* SceneComponent;

	/*The pawns StaticMeshComponent, this will the Pawns visual*/
	UPROPERTY(EditAnywhere, Category = "My Pawn")
	UStaticMeshComponent* StaticMeshComponent;



	/*The pawns velocity modifier*/
	UPROPERTY(EditAnywhere, Category = "My Pawn")
	float Velocity = 300.0f;
public:
	// Sets default values for this pawn's properties
	APlayerPaddle();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	UFUNCTION()
		void OnHitActor(AActor* SelfActor, AActor* OtherActor, FVector NormalImpulse, const FHitResult& Hit );
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private:

	/*The Pawns Move Forward Amount per frame*/
	float MoveUpAmount = 0;
	void MoveUp(float Amount);
};
