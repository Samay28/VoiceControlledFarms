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

    UPROPERTY(EditAnywhere)
    TMap<int, float> UtilityBoostRates;

    virtual void BeginPlay() override;

    UFUNCTION(BlueprintCallable)
    float GetBoostSuccessRate(int UtilityIndex) const;



protected:    
    void InitializeBoostRates();

    
    
};
