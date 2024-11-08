// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "FarmLand.generated.h"

UCLASS()
class VCFARMING_API AFarmLand : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AFarmLand();

	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable)
	void InputCropType(int index, float SuccessRate);

	void IncreaseSuccessRate(float Delta);

	float CurrentSuccessRate;
	int CurrentCropIndex;
	bool CropsGrown;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UStaticMeshComponent* FarmMesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UStaticMeshComponent* CropTypeMesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<UStaticMesh*> CropMeshes;

	void StartHarvestTimer();

	class AEconomyManager* Economy;
	class AMarketManager* MarketManager;
private:

	FTimerHandle CountdownTimerHandle;
    int32 RemainingTime;
	void UpdateCountdown();

};
