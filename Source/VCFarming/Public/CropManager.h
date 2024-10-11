#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SeasonManager.h"
#include "CropManager.generated.h"

UCLASS()
class VCFARMING_API ACropManager : public AActor
{
	GENERATED_BODY()
	
public:	
	ACropManager();

	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable)
	void AssignCrops();

protected:
	// Farm instances arrays for each type of farm
	TArray<AActor*> FoundFarms1;
	TArray<AActor*> FoundFarms2;
	TArray<AActor*> FoundFarms3;
	TArray<AActor*> FoundFarms4;
	TArray<AActor*> FoundFarms5;

	// Reference to the SeasonManager
	ASeasonManager* SeasonManager;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int SelectedCropIndex;

	// Internal counter for farm plots
	int count;

	// Crop selection methods for each farm type
	void selectCropsF1(float SuccessRate);
	void selectCropsF2(float SuccessRate);
	void selectCropsF3(float SuccessRate);
	void selectCropsF4(float SuccessRate);
	void selectCropsF5(float SuccessRate);
};
