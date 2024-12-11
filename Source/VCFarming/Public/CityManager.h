#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CityManager.generated.h"

UCLASS()
class VCFARMING_API ACityManager : public AActor
{
    GENERATED_BODY()

public:
    // Sets default values for this actor's properties
    ACityManager();

    // Returns altered success rate for a given crop index
    UFUNCTION(BlueprintCallable, Category = "City Management")
    float GetAlterSuccessRate(int CropIndex) const;

    // Returns altered cost for a given crop index
    UFUNCTION(BlueprintCallable, Category = "City Management")
    float GetAlterCost(int CropIndex) const;

    // Set the selected city index
    UFUNCTION(BlueprintCallable, Category = "City Management")
    void SetSelectedCityIndex(int CityIndex);

    // Blueprint-readable property for the selected city
    UPROPERTY(BlueprintReadWrite, Category = "City Management")
    int SelectedCityIndex;

protected:
    // Called when the game starts or when spawned
    virtual void BeginPlay() override;

    // Initialize boost rates and costs
    void InitializeBoostRates();
    void InitializeCost();

private:
    TArray<TArray<float>> CropBoostRatesByCity;
    TArray<TArray<float>> CropCostsByCity;

    int NumCities = 5; // Example number of cities
    int NumCrops = 13; // Example number of crops
};
