// Ball.h

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Camera/CameraComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Components/SphereComponent.h"
#include "Ball.generated.h"

UCLASS()
class PONG_API ABall : public AActor
{
    GENERATED_BODY()

public:
    // Sets default values for this actor's properties
    ABall();

protected:
    // Called when the game starts or when spawned
    virtual void BeginPlay() override;

public:
    // Called every frame
    virtual void Tick(float DeltaTime) override;

private:
    UPROPERTY(VisibleDefaultsOnly, Category = Projectile)
    class USphereComponent* CollisionSphere;

    UPROPERTY(VisibleAnywhere, Category = "Components")
    class UProjectileMovementComponent* MovementComponent;

    UPROPERTY(VisibleDefaultsOnly, Category = Projectile)
    UStaticMeshComponent* ProjectileMeshComponent;

    UPROPERTY(VisibleAnywhere,Category = "Ball")
    USceneComponent* VisualMeshRoot;

    UPROPERTY(VisibleAnywhere, Category = "Ball")
    UStaticMeshComponent* VisualMesh;
    UPROPERTY(VisibleAnywhere, Category = "Ball")
    class UArrowComponent* BallDirectiom;

    UPROPERTY(EditAnywhere)
    float InitialSpeed;

    UPROPERTY(EditAnywhere)
    float MaxSpeed;

    FVector BallVelocity;

    UFUNCTION()
    void OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);
};
