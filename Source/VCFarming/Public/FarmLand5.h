// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "FarmLand5.generated.h"

UCLASS()
class VCFARMING_API AFarmLand5 : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AFarmLand5();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UStaticMeshComponent* FarmMesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UStaticMeshComponent* CropTypeMesh;

	UPROPERTY(BlueprintReadOnly)
    int32 RemainingTime;

public:	
	// Called every frame
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
	
	UPROPERTY(BlueprintReadOnly)
	int CurrentCropIndex;

	void StartHarvestTimer();

	class AEconomyManager* Economy;
	class AMarketManager* MarketManager;

	UPROPERTY(BlueprintReadWrite)
	float QualityCompromisePerc;
private:

	FTimerHandle CountdownTimerHandle;

	void UpdateCountdown();
};
