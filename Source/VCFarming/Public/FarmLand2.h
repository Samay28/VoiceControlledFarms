// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "FarmLand2.generated.h"

UCLASS()
class VCFARMING_API AFarmLand2 : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AFarmLand2();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UStaticMeshComponent* FarmMesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UStaticMeshComponent* CropTypeMesh;

	UPROPERTY(BlueprintReadOnly)
	int CurrentCropIndex;

	UPROPERTY(BlueprintReadOnly)
    int32 RemainingTime;
public:	

	virtual void Tick(float DeltaTime) override;

	void InputCropType(int index, float SuccessRate);

	UPROPERTY(BlueprintReadWrite)
	float CurrentSuccessRate;


	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<UStaticMesh*> CropMeshes;

	void IncreaseSuccessRate(float Delta);

	UPROPERTY(BlueprintReadOnly)
	bool CropsGrown;

	UPROPERTY(BlueprintReadWrite)
	bool EquipmentAccessed;
	
	void StartHarvestTimer();

	class AEconomyManager* Economy;
	class AMarketManager* MarketManager;
	class ASeasonManager* SeasonManager;

	UPROPERTY(BlueprintReadWrite)
	float QualityCompromisePerc;

private:

	FTimerHandle CountdownTimerHandle;

	void UpdateCountdown();
	
};
