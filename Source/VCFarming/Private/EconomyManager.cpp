
#include "EconomyManager.h"


AEconomyManager::AEconomyManager()
{
 	
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AEconomyManager::BeginPlay()
{
	Super::BeginPlay();
	SetMoney(400);
	UE_LOG(LogTemp, Warning, TEXT("Money : %d"), GetMoney());
}

// Called every frame
void AEconomyManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AEconomyManager::DeductBalance(int amnt)
{
	Money -=amnt;
	UE_LOG(LogTemp, Warning, TEXT("Money : %d"), GetMoney());
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
