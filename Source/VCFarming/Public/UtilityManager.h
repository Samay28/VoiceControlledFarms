// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "UtilityManager.generated.h"

UCLASS()
class VCFARMING_API AUtilityManager : public AActor
{
	GENERATED_BODY()
	
public:	
	
	AUtilityManager();
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Utilities")
    TEnumAsByte<EUtilityType> EquipmentChoice;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Utilities")
    TEnumAsByte<EUtilityType> FertilizerChoice;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Utilities")
    TEnumAsByte<EUtilityType> IrrigationChoice;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Utilities")
    TEnumAsByte<EUtilityType> PestControlChoice;

    // Method to get the overall success rate modifier from utilities
    float GetTotalSuccessRateModifier() const;

private:
    float GetUtilityBoost(EUtilityType UtilityChoice) const;

protected:
	
	virtual void BeginPlay() override;


};
