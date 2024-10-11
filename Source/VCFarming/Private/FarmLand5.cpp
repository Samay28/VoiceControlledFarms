// Fill out your copyright notice in the Description page of Project Settings.


#include "FarmLand5.h"

// Sets default values
AFarmLand5::AFarmLand5()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	FarmMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("FarmMesh"));
	FarmMesh->SetupAttachment(GetRootComponent());

	CropTypeMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("CropMesh"));
	CropTypeMesh->SetupAttachment(FarmMesh);

}

// Called when the game starts or when spawned
void AFarmLand5::BeginPlay()
{
	Super::BeginPlay();
	CropTypeMesh->SetVisibility(false);
}

// Called every frame
void AFarmLand5::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AFarmLand5::InputCropType(int index, int SuccessRate)
{
	if(CropMeshes.IsValidIndex(index))
	{
		CropTypeMesh->SetVisibility(true);
		CropTypeMesh->SetStaticMesh(CropMeshes[index]);
		CurrentSuccessRate = SuccessRate;
	}
}