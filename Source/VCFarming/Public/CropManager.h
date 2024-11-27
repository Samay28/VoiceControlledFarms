#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
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

	// Internal counter for farm plots
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int count;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Ucount;

	UPROPERTY(EditAnywhere, Category = "Crop Name")
	TMap<int32, FString> CropIndexToName;

	UFUNCTION(BlueprintCallable)
	FString PrintCropName(int selectedIndex);
	

protected:
	// Farm instances arrays for each type of farm
	TArray<AActor*> FoundFarms1;
	TArray<AActor*> FoundFarms2;
	TArray<AActor*> FoundFarms3;
	TArray<AActor*> FoundFarms4;
	TArray<AActor*> FoundFarms5;

	// Reference to the SeasonManager
	class ASeasonManager* SeasonManager;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int SelectedCropIndex;



	// Crop selection methods for each farm type
	void selectCropsF1(float SuccessRate);
	void selectCropsF2(float SuccessRate);
	void selectCropsF3(float SuccessRate);
	void selectCropsF4(float SuccessRate);
	void selectCropsF5(float SuccessRate);

	//Utility Part
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int SelectedUtilityIndex;

	UFUNCTION(BlueprintCallable)
	void AssignBoost();

	class AUtilityManager* UtilityManager;

};
