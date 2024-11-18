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

	int CurrentCropIndex;


public:	

	virtual void Tick(float DeltaTime) override;

	void InputCropType(int index, float SuccessRate);

	UPROPERTY(BlueprintReadWrite)
	float CurrentSuccessRate;


	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<UStaticMesh*> CropMeshes;

	void IncreaseSuccessRate(float Delta);

	bool CropsGrown;
	void StartHarvestTimer();

	class AEconomyManager* Economy;
	class AMarketManager* MarketManager;

	UPROPERTY(BlueprintReadWrite)
	float QualityCompromisePerc;

private:

	FTimerHandle CountdownTimerHandle;
    int32 RemainingTime;
	void UpdateCountdown();
	
};
