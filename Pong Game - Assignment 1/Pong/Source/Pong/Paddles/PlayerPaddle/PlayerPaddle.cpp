// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerPaddle.h"
#include "Components/InputComponent.h"
#include "Camera/CameraComponent.h"
#include "Components/StaticMeshComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Camera/CameraActor.h"
DEFINE_LOG_CATEGORY_STATIC(LogPlayerPaddle, All, All)

// Sets default values
APlayerPaddle::APlayerPaddle()
{
	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

		// Create the box component
		BoxRoot = CreateDefaultSubobject<UBoxComponent>("RootBox");
		// Set the Box Component as the Root Component
		SetRootComponent(BoxRoot);

		// Enable collision for the Box Component
		BoxRoot->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
		BoxRoot->SetCollisionProfileName(TEXT("Pawn"));
		BoxRoot->SetSimulatePhysics(true);
		
		BoxRoot->SetLinearDamping(10);

		BoxRoot->GetBodyInstance()->bLockXRotation = true;
		BoxRoot->GetBodyInstance()->bLockYRotation = true;
		BoxRoot->GetBodyInstance()->bLockZRotation = true;
		//BoxRoot->GetBodyInstance()->bLockXTranslation = true;
		BoxRoot->GetBodyInstance()->bLockYTranslation = true;
		BoxRoot->GetBodyInstance()->bLockZTranslation = true;

		// Create Static Mesh Component
		StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");

		// Attach the Static Mesh Component to the Box Component
		StaticMeshComponent->SetupAttachment(BoxRoot);

		// Enable collision for the actor
		SetActorEnableCollision(true);

		// Set collision settings for the Static Mesh Component
		StaticMeshComponent->SetCollisionEnabled(ECollisionEnabled::NoCollision);
		


}

// Called when the game starts or when spawned
void APlayerPaddle::BeginPlay()
{
	Super::BeginPlay();

	APlayerController* PC = GetWorld()->GetFirstPlayerController();

	ACameraActor* camera = Cast<ACameraActor>( UGameplayStatics::GetActorOfClass(GetWorld(), ACameraActor::StaticClass()) );

	if(camera)
		PC->SetViewTarget(camera);

	OnActorHit.AddDynamic(this, &APlayerPaddle::OnHitActor);
}

void APlayerPaddle::OnHitActor(AActor* SelfActor, AActor* OtherActor, FVector NormalImpulse, const FHitResult& Hit)
{
	if (OtherActor && OtherActor->IsA(UStaticMeshComponent::StaticClass()))
	{
		// Print a message when the ball hits the side boundary
		GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Red, FString::Printf(TEXT("Player Paddle hit the side boundary")));

		
	}

}

// Called every frame
void APlayerPaddle::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	//TODO: Implement the movement. Think about how the movement is done after you have written the implementation code. 
	//IF the Controller is NOT null
	if (Controller)
	{
		//DECLARE a FRotator Rotation and Initialize it to pitch=0, roll=0 and the Yaw to the Controllers Yaw Rotation
		FRotator Rotation = FRotator(0.0f, Controller->GetControlRotation().Yaw, 0.f);
		//DECLARE a FVector Direction and set it to zero vector
		FVector Direction = FVector::ZeroVector;
		//IF the MoveForwardAmount is not zero
		if (MoveUpAmount != 0.0f)
		{
			//SET the Direction to this Actors Location + FRotationMatrix(??).GetUnitAxis(??) * MoveForwardAmount * Velocity * DeltaTime
			Direction = this->GetActorLocation() + FRotationMatrix(Rotation).GetUnitAxis(EAxis::X) * MoveUpAmount * Velocity * DeltaTime;
			//SET this actors location to the Direction
			this->SetActorLocation(Direction);
		}
		//ENDIF


	}
	//ENDIF
}

// Called to bind functionality to input
void APlayerPaddle::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	//TODO: Set up the Input Bindings. Be mindful of each input binding. What is the difference between the movement and looking around
	//IF PlayerInputComponent Is Not null
	if (PlayerInputComponent != NULL)
	{
		//BIND axis "MoveForward" to this objects MoveForward() Function
		PlayerInputComponent->BindAxis("MoveUp", this, &APlayerPaddle::MoveUp);
		
	}
	//ENDIF
}

void APlayerPaddle::MoveUp(float Amount)
{
	//TODO: Set the MoveForwardAmount, what are the values passed in
	//ASSIGN Amount to MoveForwardAmount
	MoveUpAmount = Amount;
}


