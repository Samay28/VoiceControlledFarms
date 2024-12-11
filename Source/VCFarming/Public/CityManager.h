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

   
    UFUNCTION(BlueprintCallable, Category = "City Management")
    float GetAlterSuccessRate(int CropIndex) const;

 
    UFUNCTION(BlueprintCallable, Category = "City Management")
    float GetAlterCost(int CropIndex) const;


    UFUNCTION(BlueprintCallable, Category = "City Management")
    void SetSelectedCityIndex(int CityIndex);

    UPROPERTY(BlueprintReadWrite, Category = "City Management")
    int SelectedCityIndex;

protected:
    
    virtual void BeginPlay() override;

  
    void InitializeBoostRates();
    void InitializeCost();

private:
    TArray<TArray<float>> CropBoostRatesByCity;
    TArray<TArray<float>> CropCostsByCity;

    int NumCities = 5; 
    int NumCrops = 13; // Example number of crops
};
