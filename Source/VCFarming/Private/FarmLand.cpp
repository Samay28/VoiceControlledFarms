// Fill out your copyright notice in the Description page of Project Settings.


#include "FarmLand.h"

// Sets default values
AFarmLand::AFarmLand()
{
 	
	PrimaryActorTick.bCanEverTick = true;
	FarmMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("FarmMesh"));
	FarmMesh->SetupAttachment(GetRootComponent());

	CropTypeMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("CropMesh"));
	CropTypeMesh->SetupAttachment(FarmMesh);
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
	if(CropMeshes.IsValidIndex(index))
	{
		CropTypeMesh->SetVisibility(true);
		CropTypeMesh->SetStaticMesh(CropMeshes[index]);
		CurrentSuccessRate = SuccessRate;
		UE_LOG(LogTemp, Warning, TEXT("CurrentSuccessRate : %f"), CurrentSuccessRate);
		CropsGrown = true;
	}
}

void AFarmLand::IncreaseSuccessRate(float Delta)
{
	CurrentSuccessRate += Delta;
	UE_LOG(LogTemp, Warning, TEXT("Increased CurrentSuccessRate : %f"), CurrentSuccessRate);
}
