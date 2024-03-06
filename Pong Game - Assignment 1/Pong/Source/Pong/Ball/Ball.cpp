// Ball.cpp

#include "Ball.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Components/SphereComponent.h"
#include "Components/ArrowComponent.h"
#include "Components/StaticMeshComponent.h"

// Sets default values
ABall::ABall()
{
    PrimaryActorTick.bCanEverTick = true;

    // Set this actor to call Tick() every frame
    // You can turn this off to improve performance if needed

    // Set up Collision Sphere
    CollisionSphere = CreateDefaultSubobject<USphereComponent>(TEXT("CollisionSphere"));
    CollisionSphere->InitSphereRadius(10.0f);
    CollisionSphere->SetCollisionProfileName("BlockAll");
    CollisionSphere->OnComponentHit.AddDynamic(this, &ABall::OnHit);
    RootComponent = CollisionSphere;

    // Set up Visual Mesh Root
    VisualMeshRoot = CreateDefaultSubobject<USceneComponent>(TEXT("VisualMeshRoot"));
    VisualMeshRoot->SetupAttachment(RootComponent);

    // Set up Visual Mesh
    VisualMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("VisualMesh"));
    VisualMesh->SetupAttachment(VisualMeshRoot);


    // Set up Projectile Movement
    BallDirectiom = CreateDefaultSubobject<UArrowComponent>(TEXT("BallDirection"));
    BallDirectiom->SetupAttachment(RootComponent);

    MovementComponent = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("ProjectileMovement"));
    MovementComponent->ProjectileGravityScale = 0.0f;
    MovementComponent->InitialSpeed = 300.0f;
    MovementComponent->MaxSpeed = 500.0f;
    MovementComponent->bShouldBounce = true;
    MovementComponent->Bounciness = 1.1f;
    MovementComponent->Friction = 0.0f;


}

// Called when the game starts or when spawned
void ABall::BeginPlay()
{
    Super::BeginPlay();

    SetActorRotation(BallDirectiom->GetRelativeRotation());

    FVector Direction = GetActorForwardVector();
    MovementComponent->Velocity = Direction * MovementComponent->InitialSpeed;
}

// Called every frame
void ABall::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    FVector NewLocation = GetActorLocation() + (MovementComponent->Velocity * DeltaTime);
    SetActorLocation(NewLocation);

}

void ABall::OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{

    // Check if the hit component is a StaticMeshComponent representing a side boundary
    if (OtherComp && OtherComp->IsA(UStaticMeshComponent::StaticClass()))
    {
        FVector ReflectedVelocity;
        // Print a message when the ball hits the side boundary
        GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Red, FString::Printf(TEXT("Ball hit the side boundary")));
 
    }

 
}
