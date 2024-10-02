// Fill out your copyright notice in the Description page of Project Settings.


#include "FarmLand3.h"

// Sets default values
AFarmLand3::AFarmLand3()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	FarmMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("FarmMesh"));
	FarmMesh->SetupAttachment(GetRootComponent());

	CropTypeMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("CropMesh"));
	CropTypeMesh->SetupAttachment(FarmMesh);
	
}

// Called when the game starts or when spawned
void AFarmLand3::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AFarmLand3::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

