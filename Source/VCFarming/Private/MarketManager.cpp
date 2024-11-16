#include "MarketManager.h"
#include "SeasonManager.h"
#include "EconomyManager.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
AMarketManager::AMarketManager()
{
 	
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AMarketManager::BeginPlay()
{
	Super::BeginPlay();
	SeasonManager = Cast<ASeasonManager>(UGameplayStatics::GetActorOfClass(GetWorld(), ASeasonManager::StaticClass()));
	EconomyManager = Cast<AEconomyManager>(UGameplayStatics::GetActorOfClass(GetWorld(), AEconomyManager::StaticClass()));
	setMarketRates();
}


// Called every frame
void AMarketManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AMarketManager::setMarketRates()
{
	for(int i=0; i<11; i++)
	{
		float price = SeasonManager->GetMarketPrice(i);
		CropMarketPrice.Add(i,price);
	}
}
float AMarketManager::GetMarketPrices(int CropIndex) const
{	
	const float* FoundPrice = CropMarketPrice.Find(CropIndex);
	if(FoundPrice)
	{
		return *FoundPrice;
	}
    return 0.0f;
}

void AMarketManager::PurchaseCrops()
{
	EconomyManager->DeductBalance(15*24); //deduction crop cost
	UE_LOG(LogTemp, Warning, TEXT("Balance Deducted!"));
}

void AMarketManager::SellHarvest(int CropIndex) //Manually selling each farm harvest over here
{
	float* HarvestPrice = CropMarketPrice.Find(CropIndex);
	EconomyManager->AddBalance(*HarvestPrice);
}

void AMarketManager::SellHarvestAtHalf(int CropIndex)
{
	float* HarvestPrice = (CropMarketPrice.Find(CropIndex));

	float HP = *HarvestPrice/2;
	EconomyManager->AddBalance(HP);
}

