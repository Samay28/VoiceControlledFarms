#include "CropManager.h"
#include "Kismet/GameplayStatics.h"
#include "SeasonManager.h"
#include "FarmLand.h"
#include "FarmLand2.h"
#include "FarmLand3.h"
#include "FarmLand4.h"
#include "FarmLand5.h"

// Sets default values
ACropManager::ACropManager()
{
	PrimaryActorTick.bCanEverTick = true;
	count = 0;
	SelectedCropIndex = 0;
	SeasonManager = nullptr;  // Initialize pointer to null
}

void ACropManager::BeginPlay()
{
	Super::BeginPlay();

	// Find all farm actors
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), AFarmLand::StaticClass(), FoundFarms1);
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), AFarmLand2::StaticClass(), FoundFarms2);
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), AFarmLand3::StaticClass(), FoundFarms3);
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), AFarmLand4::StaticClass(), FoundFarms4);
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), AFarmLand5::StaticClass(), FoundFarms5);

	// Find the SeasonManager
	SeasonManager = Cast<ASeasonManager>(UGameplayStatics::GetActorOfClass(GetWorld(), ASeasonManager::StaticClass()));
	if (!SeasonManager)
	{
		UE_LOG(LogTemp, Error, TEXT("SeasonManager not found!"));
	}
}

void ACropManager::selectCropsF1(float SuccessRate)
{
	for (AActor* FarmActor : FoundFarms1)
	{
		AFarmLand* FarmInstance = Cast<AFarmLand>(FarmActor);
		if (FarmInstance)
		{
			FarmInstance->InputCropType(SelectedCropIndex, SuccessRate);
			UE_LOG(LogTemp, Warning, TEXT("SuccessRate : %f"), SuccessRate);
		}
		else
		{
			UE_LOG(LogTemp, Warning, TEXT("Farm1 is null!"));
		}
	}
}

void ACropManager::selectCropsF2(float SuccessRate)
{
	for (AActor* FarmActor : FoundFarms2)
	{
		AFarmLand2* FarmInstance = Cast<AFarmLand2>(FarmActor);
		if (FarmInstance)
		{
			FarmInstance->InputCropType(SelectedCropIndex, SuccessRate);
		}
		else
		{
			UE_LOG(LogTemp, Warning, TEXT("Farm2 is null!"));
		}
	}
}

void ACropManager::selectCropsF3(float SuccessRate)
{
	for (AActor* FarmActor : FoundFarms3)
	{
		AFarmLand3* FarmInstance = Cast<AFarmLand3>(FarmActor);
		if (FarmInstance)
		{
			FarmInstance->InputCropType(SelectedCropIndex, SuccessRate);
		}
		else
		{
			UE_LOG(LogTemp, Warning, TEXT("Farm3 is null!"));
		}
	}
}

void ACropManager::selectCropsF4(float SuccessRate)
{
	for (AActor* FarmActor : FoundFarms4)
	{
		AFarmLand4* FarmInstance = Cast<AFarmLand4>(FarmActor);
		if (FarmInstance)
		{
			FarmInstance->InputCropType(SelectedCropIndex, SuccessRate);
		}
		else
		{
			UE_LOG(LogTemp, Warning, TEXT("Farm4 is null!"));
		}
	}
}

void ACropManager::selectCropsF5(float SuccessRate)
{
	for (AActor* FarmActor : FoundFarms5)
	{
		AFarmLand5* FarmInstance = Cast<AFarmLand5>(FarmActor);
		if (FarmInstance)
		{
			FarmInstance->InputCropType(SelectedCropIndex, SuccessRate);
		}
		else
		{
			UE_LOG(LogTemp, Warning, TEXT("Farm5 is null!"));
		}
	}
}

// Called every frame
void ACropManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ACropManager::AssignCrops()
{
	if (!SeasonManager)
	{
		UE_LOG(LogTemp, Warning, TEXT("SeasonManager not found!"));
		return;
	}

	// Get the crop success rate from the SeasonManager
	float SuccessRate = SeasonManager->GetCropSuccessRate(SelectedCropIndex);

	switch (count)
	{
		case 0:
			selectCropsF1(SuccessRate);
			break;
		case 1:
			selectCropsF2(SuccessRate);
			break;
		case 2:
			selectCropsF3(SuccessRate);
			break;
		case 3:
			selectCropsF4(SuccessRate);
			break;
		case 4:
			selectCropsF5(SuccessRate);
			break;
		default:
			UE_LOG(LogTemp, Warning, TEXT("No more farms to assign crops to!"));
			return;
	}

	count++;
}
