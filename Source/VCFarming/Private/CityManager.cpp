#include "CityManager.h"
#include "Engine/World.h"

// Sets default values
ACityManager::ACityManager()
{
    // Set this actor to call Tick() every frame. You can turn this off to improve performance if you don't need it.
    PrimaryActorTick.bCanEverTick = true;

    SelectedCityIndex = 2; // Default to invalid index

    // Initialize arrays for boost rates and costs
    CropBoostRatesByCity.SetNum(NumCities); // NumCities is the total number of cities
    CropCostsByCity.SetNum(NumCities);
}

// Returns the altered success rate for a crop
float ACityManager::GetAlterSuccessRate(int CropIndex) const
{
    if (SelectedCityIndex < 0 || SelectedCityIndex >= CropBoostRatesByCity.Num())
    {
        UE_LOG(LogTemp, Warning, TEXT("Invalid city index!"));
        return 0.0f;
    }

    if (CropIndex < 0 || CropIndex >= CropBoostRatesByCity[SelectedCityIndex].Num())
    {
        UE_LOG(LogTemp, Warning, TEXT("Invalid crop index!"));
        return 0.0f;
    }

    return CropBoostRatesByCity[SelectedCityIndex][CropIndex];
}

// Returns the altered cost for a crop
float ACityManager::GetAlterCost(int CropIndex) const
{
    if (SelectedCityIndex < 0 || SelectedCityIndex >= CropCostsByCity.Num())
    {
        UE_LOG(LogTemp, Warning, TEXT("Invalid city index!"));
        return 0.0f;
    }

    if (CropIndex < 0 || CropIndex >= CropCostsByCity[SelectedCityIndex].Num())
    {
        UE_LOG(LogTemp, Warning, TEXT("Invalid crop index!"));
        return 0.0f;
    }

    return CropCostsByCity[SelectedCityIndex][CropIndex];
}

// Called when the game starts or when spawned
void ACityManager::BeginPlay()
{
    Super::BeginPlay();

    // Initialize boost rates and costs for all cities
    InitializeBoostRates();
    InitializeCost();
}

void ACityManager::InitializeBoostRates()
{
    for (int CityIndex = 0; CityIndex < NumCities; ++CityIndex)
    {
        TArray<float> CropBoostRates;

        for (int CropIndex = 0; CropIndex < NumCrops; ++CropIndex)
        {
            // Favorable city-crop mapping based on provided data
            if ((CropIndex == 0 && (CityIndex == 1 || CityIndex == 2 || CityIndex == 3)) ||
                (CropIndex == 1 && (CityIndex == 3 || CityIndex == 2 || CityIndex == 4)) ||
                (CropIndex == 2 && (CityIndex == 1 || CityIndex == 2)) ||
                (CropIndex == 3 && (CityIndex == 1 || CityIndex == 2)) ||
                (CropIndex == 4 && (CityIndex == 5 || CityIndex == 2)) ||
                (CropIndex == 5 && (CityIndex == 1 || CityIndex == 2)) ||
                (CropIndex == 6 && (CityIndex == 1 || CityIndex == 2)) ||
                (CropIndex == 7 && (CityIndex == 1 || CityIndex == 2)) ||
                (CropIndex == 8 && (CityIndex == 1 || CityIndex == 3)) ||
                (CropIndex == 9 && (CityIndex == 1 || CityIndex == 2)) ||
                (CropIndex == 10 && (CityIndex == 2 || CityIndex == 3 || CityIndex == 1)))
            {
                CropBoostRates.Add(10.0f); // Boost success rate by 10%
            }
            else
            {
                CropBoostRates.Add(-5.0f); // Penalize success rate by 5%
            }
        }

        CropBoostRatesByCity[CityIndex] = CropBoostRates;
    }
}

void ACityManager::InitializeCost()
{
    for (int CityIndex = 0; CityIndex < NumCities; ++CityIndex)
    {
        TArray<float> CropCosts;

        for (int CropIndex = 0; CropIndex < NumCrops; ++CropIndex)
        {
            // Favorable city-crop mapping based on provided data
            if ((CropIndex == 0 && (CityIndex == 1 || CityIndex == 2 || CityIndex == 3)) ||
                (CropIndex == 1 && (CityIndex == 3 || CityIndex == 2 || CityIndex == 4)) ||
                (CropIndex == 2 && (CityIndex == 1 || CityIndex == 2)) ||
                (CropIndex == 3 && (CityIndex == 1 || CityIndex == 2)) ||
                (CropIndex == 4 && (CityIndex == 5 || CityIndex == 2)) ||
                (CropIndex == 5 && (CityIndex == 1 || CityIndex == 2)) ||
                (CropIndex == 6 && (CityIndex == 1 || CityIndex == 2)) ||
                (CropIndex == 7 && (CityIndex == 1 || CityIndex == 2)) ||
                (CropIndex == 8 && (CityIndex == 1 || CityIndex == 3)) ||
                (CropIndex == 9 && (CityIndex == 1 || CityIndex == 2)) ||
                (CropIndex == 10 && (CityIndex == 2 || CityIndex == 3 || CityIndex == 1)))
            {
                CropCosts.Add(-8.0f); // Lower cost for favorable crops
            }
            else
            {
                CropCosts.Add(12.0f); // Higher cost for other crops
            }
        }

        CropCostsByCity[CityIndex] = CropCosts;
    }
}

void ACityManager::SetSelectedCityIndex(int CityIndex)
{
    if (CityIndex >= 0 && CityIndex < NumCities)
    {
        SelectedCityIndex = CityIndex;
    }
    else
    {
        UE_LOG(LogTemp, Warning, TEXT("Invalid city index selected: %d"), CityIndex);
    }
}