
#include "FarmLand4.h"
#include "EconomyManager.h"
#include "MarketManager.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
AFarmLand4::AFarmLand4()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	FarmMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("FarmMesh"));
	FarmMesh->SetupAttachment(GetRootComponent());

	CropTypeMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("CropMesh"));
	CropTypeMesh->SetupAttachment(FarmMesh);
	RemainingTime = 60;
	CurrentCropIndex = 0;
}

// Called when the game starts or when spawned
void AFarmLand4::BeginPlay()
{
	Super::BeginPlay();
	CropTypeMesh->SetVisibility(false);

	Economy = Cast<AEconomyManager>(UGameplayStatics::GetActorOfClass(GetWorld(), AEconomyManager::StaticClass()));
	MarketManager = Cast<AMarketManager>(UGameplayStatics::GetActorOfClass(GetWorld(), AMarketManager::StaticClass()));
}

// Called every frame
void AFarmLand4::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AFarmLand4::InputCropType(int index, float SuccessRate)
{
	if (CropMeshes.IsValidIndex(index))
	{
		CropTypeMesh->SetVisibility(true);
		CropTypeMesh->SetStaticMesh(CropMeshes[index]);
		CurrentSuccessRate = SuccessRate;
		UE_LOG(LogTemp, Warning, TEXT("CurrentSuccessRate : %f"), CurrentSuccessRate);
		CropsGrown = true;
		StartHarvestTimer();
	}
}
void AFarmLand4::StartHarvestTimer()
{
	RemainingTime = 10;
	GetWorld()->GetTimerManager().SetTimer(CountdownTimerHandle, this, &AFarmLand4::UpdateCountdown, 1.0f, true);
}

void AFarmLand4::UpdateCountdown()
{
	RemainingTime--;
	UE_LOG(LogTemp, Warning, TEXT("Time remaining: %d seconds"), RemainingTime);

	if (RemainingTime <= 0)
	{
		GetWorld()->GetTimerManager().ClearTimer(CountdownTimerHandle);
		UE_LOG(LogTemp, Warning, TEXT("Harvest timer finished!"));

		bool bHarvestSuccess = FMath::FRand() <= CurrentSuccessRate;

		if (bHarvestSuccess)
		{
			MarketManager->SellHarvest(CurrentCropIndex); // GET MARKET PRICE
		}
		else
		{
			UE_LOG(LogTemp, Warning, TEXT("Harvest Failed!"));
		}
		CropTypeMesh->SetVisibility(false);
		CropsGrown = false;
	}
}

void AFarmLand4::IncreaseSuccessRate(float Delta)
{
	CurrentSuccessRate += Delta;
	UE_LOG(LogTemp, Warning, TEXT("Increased CurrentSuccessRate : %f"), CurrentSuccessRate);
}
