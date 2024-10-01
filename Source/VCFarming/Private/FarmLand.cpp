// Fill out your copyright notice in the Description page of Project Settings.


#include "FarmLand.h"

// Sets default values
AFarmLand::AFarmLand()
{
 	
	PrimaryActorTick.bCanEverTick = true;
	FarmMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("FarmMesh"));
	FarmMesh->SetupAttachment(GetRootComponent());
}


void AFarmLand::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AFarmLand::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

