#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SeasonManager.generated.h"

UENUM(BlueprintType)
enum class ESeason : uint8
{
    Summer UMETA(DisplayName = "Summer"),
    Winter UMETA(DisplayName = "Winter")
};
UCLASS()
class VCFARMING_API ASeasonManager : public AActor
{
	GENERATED_BODY()
	
public:	
	ASeasonManager();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TMap<int, float> CropSuccessRates;  

	virtual void BeginPlay() override;


	float GetCropSuccessRate(int CropIndex) const;


	void ModifyCropSuccessRate(int CropIndex, float Delta);

protected:
	
	void InitializeSuccessRates();

private:

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Season", meta = (AllowPrivateAccess = "true"))
    ESeason CurrentSeason;

	
	void RandomizeSeason();
	float GetBaseSuccessRate(int CropIndex) const;
};
