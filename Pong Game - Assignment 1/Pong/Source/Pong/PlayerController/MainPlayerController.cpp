// Fill out your copyright notice in the Description page of Project Settings.

#include "MainPlayerController.h"

#include "../Paddles/PlayerPaddle/PlayerPaddle.h"

// Sets default values
AMainPlayerController::AMainPlayerController()
{

}

void AMainPlayerController::AcknowledgePossession(APawn* P)
{
    Super::AcknowledgePossession(P);
}

// Called when the controller possesses a pawn
void AMainPlayerController::OnPossess(APawn* aPawn)
{
    // Call the parent class's OnPossess to perform any base class setup
    Super::OnPossess(aPawn);

    // Attempt to cast the possessed pawn to AMainPawn and assign it to TheMainPawn
    TheMainPawn = Cast<APlayerPaddle>(aPawn);

    // Setup the input component for the MainPawn
    SetupInputComponent();
}

// Called when the controller unpossesses the current pawn
void AMainPlayerController::OnUnPossess()
{
    // Call the parent class's OnUnPossess to perform any base class cleanup
    Super::OnUnPossess();
}

// Setup input bindings for the player controller
void AMainPlayerController::SetupInputComponent()
{
    // Call the parent class's SetupInputComponent to perform any base class setup
    Super::SetupInputComponent();

    // Commented out code that binds input axis and actions to corresponding functions in the MainPawn
    /*
    if (InputComponent)
    {
        InputComponent->BindAxis("MoveForward", TheMainPawn, &AMainPawn::MoveForward);
        InputComponent->BindAxis("MoveRight", TheMainPawn, &AMainPawn::MoveRight);
        InputComponent->BindAxis("Turn", TheMainPawn, &AMainPawn::Turn);
        //PlayerInputComponent->BindAxis("LookUp", this, &APawn::AddControllerPitchInput);
        InputComponent->BindAction("Pause", IE_Pressed, TheMainPawn, &AMainPawn::Pause);
    }
    */
}