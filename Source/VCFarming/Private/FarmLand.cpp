// Fill out your copyright notice in the Description page of Project Settings.

#include "FarmLand.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
AFarmLand::AFarmLand()
{

	PrimaryActorTick.bCanEverTick = true;
	FarmMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("FarmMesh"));
	FarmMesh->SetupAttachment(GetRootComponent());

	CropTypeMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("CropMesh"));
	CropTypeMesh->SetupAttachment(FarmMesh);

	RemainingTime = 60;

}

void AFarmLand::BeginPlay()
{
	Super::BeginPlay();
	CropTypeMesh->SetVisibility(false);
}


// Called every frame
void AFarmLand::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AFarmLand::InputCropType(int index, float SuccessRate)
{
	if (CropMeshes.IsValidIndex(index))
	{
		CropTypeMesh->SetVisibility(true);
		CropTypeMesh->SetStaticMesh(CropMeshes[index]);
		CurrentSuccessRate = SuccessRate;
		UE_LOG(LogTemp, Warning, TEXT("CurrentSuccessRate : %f"), CurrentSuccessRate);
		CropsGrown = true;
		StartHarvestTimer();
	}
}

void AFarmLand::StartHarvestTimer()
{
	RemainingTime = 60;

    GetWorld()->GetTimerManager().SetTimer(CountdownTimerHandle, this, &AFarmLand::UpdateCountdown, 1.0f, true);
}


void AFarmLand::UpdateCountdown()
{
	RemainingTime--;
	UE_LOG(LogTemp, Warning, TEXT("Time remaining: %d seconds"), RemainingTime);

    if (RemainingTime <= 0)
    {
        GetWorld()->GetTimerManager().ClearTimer(CountdownTimerHandle);
        UE_LOG(LogTemp, Warning, TEXT("Harvest timer finished!"));
    
    }
}
void AFarmLand::Harvest()
{

}

void AFarmLand::IncreaseSuccessRate(float Delta)
{
	CurrentSuccessRate += Delta;
	UE_LOG(LogTemp, Warning, TEXT("Increased CurrentSuccessRate : %f"), CurrentSuccessRate);
}
