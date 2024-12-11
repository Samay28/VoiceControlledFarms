
#include "FarmLand5.h"
#include "EconomyManager.h"
#include "MarketManager.h"
#include "SeasonManager.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
AFarmLand5::AFarmLand5()
{

	PrimaryActorTick.bCanEverTick = true;
	FarmMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("FarmMesh"));
	FarmMesh->SetupAttachment(GetRootComponent());

	CropTypeMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("CropMesh"));
	CropTypeMesh->SetupAttachment(FarmMesh);
	RemainingTime = 60;
	QualityCompromisePerc = 100;
	CurrentCropIndex = 110;
}

void AFarmLand5::BeginPlay()
{
	Super::BeginPlay();
	CropTypeMesh->SetVisibility(false);

	Economy = Cast<AEconomyManager>(UGameplayStatics::GetActorOfClass(GetWorld(), AEconomyManager::StaticClass()));
	SeasonManager= Cast<ASeasonManager>(UGameplayStatics::GetActorOfClass(GetWorld(), ASeasonManager::StaticClass()));
	MarketManager = Cast<AMarketManager>(UGameplayStatics::GetActorOfClass(GetWorld(), AMarketManager::StaticClass()));
}

// Called every frame
void AFarmLand5::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AFarmLand5::InputCropType(int index, float SuccessRate)
{
	if (CropMeshes.IsValidIndex(index))
	{
		CurrentCropIndex = index;
		CropTypeMesh->SetVisibility(true);
		CropTypeMesh->SetStaticMesh(CropMeshes[index]);
		CurrentSuccessRate = SuccessRate;
		UE_LOG(LogTemp, Warning, TEXT("CurrentSuccessRate : %f"), CurrentSuccessRate);
		CropsGrown = true;
		StartHarvestTimer();
	}
}
void AFarmLand5::StartHarvestTimer()
{
	RemainingTime = 30;

	GetWorld()->GetTimerManager().SetTimer(CountdownTimerHandle, this, &AFarmLand5::UpdateCountdown, 1.0f, true);
}

void AFarmLand5::UpdateCountdown()
{
	RemainingTime--;
	UE_LOG(LogTemp, Warning, TEXT("Time remaining: %d seconds"), RemainingTime);

	if (RemainingTime <= 0)
	{
		GetWorld()->GetTimerManager().ClearTimer(CountdownTimerHandle);
		UE_LOG(LogTemp, Warning, TEXT("Harvest timer finished!"));

		bool bHarvestSuccess = FMath::FRand() <= CurrentSuccessRate;
		bool bQualityCompromised = FMath::FRand() <= QualityCompromisePerc;

		if (bHarvestSuccess)
		{
			if (bQualityCompromised)
			{
				MarketManager->SellHarvestAtHalf(CurrentCropIndex);
				Economy->CropsHarvested++;
				UE_LOG(LogTemp, Warning, TEXT("sold in half"));
			}
			else
			{
				MarketManager->SellHarvest(CurrentCropIndex); // GET MARKET PRICE
				Economy->CropsHarvested++;
			}
		}
		else
		{
			UE_LOG(LogTemp, Warning, TEXT("Harvest Failed!"));
			Economy->CropsRuined++;
		}
		CropTypeMesh->SetVisibility(false);
		EquipmentAccessed = false;
		CropsGrown = false;
		CurrentSuccessRate = 0;
		CurrentCropIndex = 111;
		QualityCompromisePerc = 100;
		SeasonManager->InitializeSuccessRates();
		MarketManager->setMarketRates();
	}
}
void AFarmLand5::IncreaseSuccessRate(float Delta)
{
	CurrentSuccessRate += Delta;
	UE_LOG(LogTemp, Warning, TEXT("Increased CurrentSuccessRate : %f"), CurrentSuccessRate);
}
