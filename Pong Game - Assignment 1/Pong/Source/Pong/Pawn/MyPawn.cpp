// Fill out your copyright notice in the Description page of Project Settings.


#include "MyPawn.h"

// Sets default values
AMyPawn::AMyPawn()
{
	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//TODO: Create the component hierarchy in for this actor. What does the hierarchy look like. Draw it out on paper
	//CREATE scene component
	SceneComponent = CreateDefaultSubobject<USceneComponent>("Root");
	//SET the Scene Component as the  Root Component
	SetRootComponent(SceneComponent);
	//CREATE Static Mesh Component
	StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");

	//ATTACH the Static Mesh Component to the Root Component
	StaticMeshComponent->SetupAttachment(RootComponent);
	//CREATE Spring Arm Component
	SpringArmComponent = CreateDefaultSubobject<USpringArmComponent>("SpringArm");
	//ATTACH the Spring Arm Component to the Root Component
	SpringArmComponent->SetupAttachment(RootComponent);
	//CREATE Camera Component
	CameraComponent = CreateDefaultSubobject<UCameraComponent>("Camera");
	//ATTACH the Camera Component to the Spring Arm Component
	CameraComponent->SetupAttachment(SpringArmComponent);
	//SET the Spring Arm to Use Pawn Control Rotation (bUsePawnControlRotation)
	SpringArmComponent->bUsePawnControlRotation = true;
}

// Called when the game starts or when spawned
void AMyPawn::BeginPlay()
{
	Super::BeginPlay();
	APlayerController* PC = GetWorld()->GetFirstPlayerController();



	PC->SetViewTarget(this);
}

// Called every frame
void AMyPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AMyPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

