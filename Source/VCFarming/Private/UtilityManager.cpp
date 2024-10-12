// Fill out your copyright notice in the Description page of Project Settings.


#include "UtilityManager.h"

// Sets default values
AUtilityManager::AUtilityManager()
{
 
	PrimaryActorTick.bCanEverTick = false;

}

float AUtilityManager::GetTotalSuccessRateModifier() const
{
    switch(UtilityChoice)
    {
        case EUtilityType::Premium: // Advanced/Premium utilities
            return 0.05f;
        case EUtilityType::Standard: // Standard/Modern utilities
            return 0.03f;
        case EUtilityType::Basic: // Basic/Old Style utilities
            return 0.01f;
        case EUtilityType::NotUsing:
        default:
            return 0.0f;
    }
}

float AUtilityManager::GetUtilityBoost(EUtilityType UtilityChoice) const
{
    return GetUtilityBoost(EquipmentChoice) +
           GetUtilityBoost(FertilizerChoice) +
           GetUtilityBoost(IrrigationChoice) +
           GetUtilityBoost(PestControlChoice);
}

// Called when the game starts or when spawned
void AUtilityManager::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AUtilityManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

