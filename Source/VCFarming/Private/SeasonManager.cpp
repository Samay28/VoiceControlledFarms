#include "SeasonManager.h"
#include "CityManager.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetMathLibrary.h"

ASeasonManager::ASeasonManager()
{
    PrimaryActorTick.bCanEverTick = false;
}

void ASeasonManager::BeginPlay()
{
    Super::BeginPlay();

    CM = Cast<ACityManager>(UGameplayStatics::GetActorOfClass(GetWorld(), ACityManager::StaticClass()));
    RandomizeSeason();
    // InitializeSuccessRates(); // Make sure this populates correctly

    // Log the current season for debugging
    UE_LOG(LogTemp, Warning, TEXT("Current Season: %s"), *UEnum::GetValueAsString(CurrentSeason));

    // Log the success rates for all crops for debugging
    for (int i = 0; i < 11; i++) // Ensure you're checking for valid crop indices (0-10)
    {
        if (CropSuccessRates.Contains(i))
        {
            UE_LOG(LogTemp, Warning, TEXT("CropIndex: %d, SuccessRate: %f"), i, CropSuccessRates[i]);
        }
        else
        {
            UE_LOG(LogTemp, Error, TEXT("CropIndex: %d not found in CropSuccessRates!"), i);
        }
    }
}

void ASeasonManager::RandomizeSeason()
{
    int32 RandomSeasonIndex = FMath::RandRange(0, 1);
    CurrentSeason = static_cast<ESeason>(RandomSeasonIndex);
}

float ASeasonManager::GetBaseSuccessRate(int CropIndex) const
{
    float BaseRate = 0;

    switch (CurrentSeason)
    {
    case ESeason::Summer:
    {
        switch (CropIndex)
        {
        case 0:                                       // Corn
        case 1:                                       // Millet
        case 2:                                       // Pumpkin
        case 3:                                       // Tomato
        case 4:                                       // Pepper plant
        case 5:                                       // Cucumber
        case 6:                                       // Watermelon
            BaseRate = FMath::RandRange(0.6f, 0.65f); // High rate for summer crops
            break;
        default:
            BaseRate = FMath::RandRange(0.35f, 0.40f); // Low rate for winter crops
            break;
        }
    }
    break;

    case ESeason::Winter:
    {
        switch (CropIndex)
        {
        case 7:                                       // Cabbage
        case 8:                                       // Onion
        case 9:                                       // Turnip
        case 10:                                      // Grapes
            BaseRate = FMath::RandRange(0.6f, 0.65f); // High rate for winter crops
            break;
        default:
            BaseRate = FMath::RandRange(0.35f, 0.4f); // Low rate for summer crops
            break;
        }
    }
    break;
    }

    return BaseRate;
}

float ASeasonManager::GetMarketPrice(int CropIndex) const
{
    float CurrentPrice = 0;

    switch (CurrentSeason)
    {
    case ESeason::Summer:
    {
        switch (CropIndex)
        {
        case 0:                                      // Corn
        case 1:                                      // Millet
        case 2:                                      // Pumpkin
        case 3:                                      // Tomato
        case 4:                                      // Pepper plant
        case 5:                                      // Cucumber
        case 6:                                      // Watermelon
            CurrentPrice = FMath::RandRange(25, 30); // less price for summer crops
            break;
        default:
            CurrentPrice = FMath::RandRange(55, 60); // high price for winter crops
            break;
        }
    }
    break;

    case ESeason::Winter:
    {
        switch (CropIndex)
        {
        case 7:                                      // Cabbage
        case 8:                                      // Onion
        case 9:                                      // Turnip
        case 10:                                     // Grapes
            CurrentPrice = FMath::RandRange(25, 30); // less price for winter crops
            break;
        default:
            CurrentPrice = FMath::RandRange(55, 60); // high price for summer crops
            break;
        }
    }
    break;
    }

    return CurrentPrice;
}

void ASeasonManager::InitializeSuccessRates()
{
    for (int CropIndex = 0; CropIndex <= 10; CropIndex++) // Ensure you cover all crop indices (0-10)
    {
        // Use GetBaseSuccessRate instead of GetCropSuccessRate during initialization
        float SuccessRate = GetBaseSuccessRate(CropIndex);
        CropSuccessRates.Add(CropIndex, SuccessRate);
    }

    UE_LOG(LogTemp, Warning, TEXT("Success rates have been reinitialized."));
}

float ASeasonManager::GetCropSuccessRate(int CropIndex) const
{

    const float* FoundRate = CropSuccessRates.Find(CropIndex);

    if (FoundRate)
    {
        // Add the altered rate from the CityManager
        float AlteredRate = CM ? CM->GetAlterSuccessRate(CropIndex) : 0.0f;
        return *FoundRate + AlteredRate;
    }

    UE_LOG(LogTemp, Warning, TEXT("CropIndex %d not found in CropSuccessRates!"), CropIndex);
    return 0.0f;
}

