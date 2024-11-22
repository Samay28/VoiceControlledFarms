// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MarketManager.generated.h"

UCLASS()
class VCFARMING_API AMarketManager : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMarketManager();
	virtual void Tick(float DeltaTime) override;

	void setMarketRates();

	UFUNCTION(BlueprintCallable)
	float GetMarketPrices(int CropIndex) const;

	UFUNCTION(BlueprintCallable)
	bool PurchaseCrops();

	UFUNCTION(BlueprintCallable)
	void SellHarvest(int CropIndex);

	void SellHarvestAtHalf(int CropIndex);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	class ASeasonManager* SeasonManager;
	class AEconomyManager* EconomyManager;

	UPROPERTY(EditAnywhere)
    TMap<int, float> CropMarketPrice;

};
