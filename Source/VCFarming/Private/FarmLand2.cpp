#include "FarmLand2.h"
#include "EconomyManager.h"
#include "MarketManager.h"
#include "SeasonManager.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
AFarmLand2::AFarmLand2()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	FarmMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("FarmMesh"));
	FarmMesh->SetupAttachment(GetRootComponent());

	CropTypeMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("CropMesh"));
	CropTypeMesh->SetupAttachment(FarmMesh);

	RemainingTime = 60;
	QualityCompromisePerc = 100;
	CurrentCropIndex = 110;
}

// Called when the game starts or when spawned
void AFarmLand2::BeginPlay()
{
	Super::BeginPlay();
	CropTypeMesh->SetVisibility(false);

	Economy = Cast<AEconomyManager>(UGameplayStatics::GetActorOfClass(GetWorld(), AEconomyManager::StaticClass()));
	MarketManager = Cast<AMarketManager>(UGameplayStatics::GetActorOfClass(GetWorld(), AMarketManager::StaticClass()));
}

// Called every frame
void AFarmLand2::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AFarmLand2::InputCropType(int index, float SuccessRate)
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

void AFarmLand2::StartHarvestTimer()
{
	RemainingTime = 30;

	GetWorld()->GetTimerManager().SetTimer(CountdownTimerHandle, this, &AFarmLand2::UpdateCountdown, 1.0f, true);
}

void AFarmLand2::UpdateCountdown()
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
				Economy->CropsRuined++;
				UE_LOG(LogTemp, Warning, TEXT("sold in half"));
			}
			else
			{
				MarketManager->SellHarvest(CurrentCropIndex); // GET MARKET PRICE
				Economy->CropsHarvested++;
			}
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

void AFarmLand2::IncreaseSuccessRate(float Delta)
{
	CurrentSuccessRate += Delta;
	UE_LOG(LogTemp, Warning, TEXT("Increased CurrentSuccessRate : %f"), CurrentSuccessRate);
}
