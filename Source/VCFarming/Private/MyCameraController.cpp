#include "MyCameraController.h"
#include "Engine/World.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"


// Sets default values
AMyCameraController::AMyCameraController()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
    SpringArm->SetupAttachment(RootComponent);
    SpringArm->TargetArmLength = 800.f; // Set the camera's height
    SpringArm->bDoCollisionTest = false;

    Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
    Camera->SetupAttachment(SpringArm);

    AutoPossessPlayer = EAutoReceiveInput::Player0;
}

// Called when the game starts or when spawned
void AMyCameraController::BeginPlay()
{
	Super::BeginPlay();
	
}

void AMyCameraController::GetMouseMovement(FVector2D& OutMouseMovement)
{	
	APlayerController* PlayerController = GetWorld()->GetFirstPlayerController();
    if (PlayerController)
    {
        float MouseX, MouseY;
        PlayerController->GetInputMouseDelta(MouseX, MouseY);
        OutMouseMovement.X = MouseX;
        OutMouseMovement.Y = -MouseY;
    }
}

// Called every frame
void AMyCameraController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	FVector2D MouseMovement;
	GetMouseMovement(MouseMovement);

	FVector NewLocation = GetActorLocation();

	NewLocation.X += MouseMovement.X * MovementSpeed * DeltaTime;
	NewLocation.Y += MouseMovement.Y * MovementSpeed * DeltaTime;

	NewLocation.X = FMath::Clamp(NewLocation.X, MinX, MaxX);
    NewLocation.Y = FMath::Clamp(NewLocation.Y, MinY, MaxY);

	SetActorLocation(NewLocation);
}

// Called to bind functionality to input
void AMyCameraController::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}