#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "MyCameraController.generated.h"

UCLASS()
class VCFARMING_API AMyCameraController : public APawn
{
    GENERATED_BODY()

public:
    AMyCameraController();

protected:
    virtual void BeginPlay() override;

public:
    virtual void Tick(float DeltaTime) override;

   void GetMouseMovement(FVector2D& OutMouseMovement);

   virtual void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent);

private:
    // Camera and SpringArm components
    UPROPERTY(VisibleAnywhere)
    class USpringArmComponent* SpringArm;

    UPROPERTY(VisibleAnywhere)
    class UCameraComponent* Camera;

    FVector2D PreviousCursorPosition;

    // Movement properties
    UPROPERTY(EditAnywhere)
    float MovementSpeed = 1000.0f;

    UPROPERTY(EditAnywhere)
    float MinX = -5000.0f;

    UPROPERTY(EditAnywhere)
    float MaxX = 5000.0f;

    UPROPERTY(EditAnywhere)
    float MinY = -5000.0f;

    UPROPERTY(EditAnywhere)
    float MaxY = 5000.0f;
};
