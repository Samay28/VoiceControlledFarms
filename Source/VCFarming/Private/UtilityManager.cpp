#include "UtilityManager.h"
#include "Kismet/KismetMathLibrary.h"

AUtilityManager::AUtilityManager()
{
    PrimaryActorTick.bCanEverTick = false;
    InitializeBoostRates();
}

void AUtilityManager::BeginPlay()
{
    for (int i = 0; i < 14; i++)
    {
        if (UtilityBoostRates.Contains(i))
        {
            UE_LOG(LogTemp, Warning, TEXT("Utility: %d, BoostRate: %f"), i, UtilityBoostRates[i]);
        }
    }
}

float AUtilityManager::GetBoostSuccessRate(int UtilityIndex) const
{
    float boostRate = 0.0f;
    float cost = 0.0f;
    if (UtilityIndex == 0 || UtilityIndex == 3 || UtilityIndex == 6 || UtilityIndex == 9)
    {
        boostRate = 0.05f;
    }
    else if (UtilityIndex == 1 || UtilityIndex == 4 || UtilityIndex == 7 || UtilityIndex == 10)
    {
        boostRate = 0.03f;
    }
    else if (UtilityIndex == 2 || UtilityIndex == 5 || UtilityIndex == 8 || UtilityIndex == 11)
    {
        boostRate = 0.01f;
    }
    else
    {
        boostRate = 0.0f;
    }
    return boostRate;
}

float AUtilityManager::GetMoneyDeducted(int UtilityIndex) const
{
    float cost = 0.0f;
    if (UtilityIndex == 0 || UtilityIndex == 3 || UtilityIndex == 6 || UtilityIndex == 9)
    {
        cost = 100;
    }
    else if (UtilityIndex == 1 || UtilityIndex == 4 || UtilityIndex == 7 || UtilityIndex == 10)
    {
        cost = 50;
    }
    else if (UtilityIndex == 2 || UtilityIndex == 5 || UtilityIndex == 8 || UtilityIndex == 11)
    {
        cost = 20;
    }
    else
    {
        cost = 0;
    }
    return cost;
}

void AUtilityManager::InitializeBoostRates()
{
    for (int UI = 0; UI < 14; UI++)
    {
        float BoostRate = GetBoostSuccessRate(UI);
        UtilityBoostRates.Add(UI, BoostRate);
    }
}

void AUtilityManager::InitializeCost()
{
    for (int UI = 0; UI < 14; UI++)
    {
        float costs = GetMoneyDeducted(UI);
        UtilityCost.Add(UI, costs);
    }
}
