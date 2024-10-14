// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "EconomyManager.generated.h"

UCLASS()
class VCFARMING_API AEconomyManager : public AActor
{
	GENERATED_BODY()
	
public:	
	
	AEconomyManager();
	virtual void Tick(float DeltaTime) override;


	UFUNCTION(BlueprintCallable)
	void DeductBalance(int amnt);

	UFUNCTION(BlueprintCallable)
	void AddBalance(int amnt);

	int GetMoney();
	void SetMoney(int amnt);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	int Money;

};
