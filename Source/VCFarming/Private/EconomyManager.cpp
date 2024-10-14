// Fill out your copyright notice in the Description page of Project Settings.


#include "EconomyManager.h"

// Sets default values
AEconomyManager::AEconomyManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	SetMoney(100);

}

// Called when the game starts or when spawned
void AEconomyManager::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AEconomyManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AEconomyManager::DeductBalance(int amnt)
{
	Money -=amnt;
}

void AEconomyManager::AddBalance(int amnt)
{
	Money +=amnt;
}

int AEconomyManager::GetMoney()
{	
    return Money;
}

void AEconomyManager::SetMoney(int amnt)
{
	amnt = Money;
}
