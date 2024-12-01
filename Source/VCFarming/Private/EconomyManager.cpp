
#include "EconomyManager.h"


AEconomyManager::AEconomyManager()
{
 	
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AEconomyManager::BeginPlay()
{
	Super::BeginPlay();
	SetMoney(1000);
	UE_LOG(LogTemp, Warning, TEXT("Money : %d"), GetMoney());
	CropsRuined = 0;
	CropsHarvested = 0;
	TotalExpenditure = 0;
	TotalCropsSowed = 0;

}

// Called every frame
void AEconomyManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AEconomyManager::DeductBalance(int amnt)
{
	Money -=amnt;
	TotalExpenditure += amnt;
	UE_LOG(LogTemp, Warning, TEXT("total exp : %d"), TotalExpenditure);
}

void AEconomyManager::AddBalance(int amnt)
{
	Money +=amnt;
	UE_LOG(LogTemp, Warning, TEXT("Money : %d"), GetMoney());
}

int AEconomyManager::GetMoney()
{	
    return Money;
}

void AEconomyManager::SetMoney(int amnt)
{
	Money = amnt;
}
