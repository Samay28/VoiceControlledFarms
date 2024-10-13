#include "MarketManager.h"
#include "SeasonManager.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
AMarketManager::AMarketManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AMarketManager::BeginPlay()
{
	Super::BeginPlay();
	SeasonManager = Cast<ASeasonManager>(UGameplayStatics::GetActorOfClass(GetWorld(), ASeasonManager::StaticClass()));
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
