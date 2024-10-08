// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CropManager.generated.h"

UCLASS()
class VCFARMING_API ACropManager : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ACropManager();
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(BlueprintReadWrite)
	int SelectedCropIndex;

	UFUNCTION(BlueprintCallable)
	void AssignCrops();
	int count;

protected:
	virtual void BeginPlay() override;

	void selectCropsF1();
	void selectCropsF2();
	void selectCropsF3();
	void selectCropsF4();
	void selectCropsF5();

	TArray<AActor *> FoundFarms1;
	TArray<AActor *> FoundFarms2;
	TArray<AActor *> FoundFarms3;
	TArray<AActor *> FoundFarms4;
	TArray<AActor *> FoundFarms5;
};
