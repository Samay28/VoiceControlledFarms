

#include "CropManager.h"
#include "Kismet/GameplayStatics.h"
#include "FarmLand.h"
#include "FarmLand2.h"
#include "FarmLand3.h"
#include "FarmLand4.h"
#include "FarmLand5.h"

// Sets default values
ACropManager::ACropManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	count = 0;
	SelectedCropIndex = 0;

}


void ACropManager::BeginPlay()
{
    Super::BeginPlay();


    TArray<AActor*> FoundFarms;
    UGameplayStatics::GetAllActorsOfClass(GetWorld(),AFarmLand::StaticClass(), FoundFarms);
    if (FoundFarms.Num() > 0)
    {
        Farm = Cast<AFarmLand>(FoundFarms[0]);  
    }

    FoundFarms.Empty();
    UGameplayStatics::GetAllActorsOfClass(GetWorld(),AFarmLand2::StaticClass(), FoundFarms);
    if (FoundFarms.Num() > 0)
    {
        Farm2 = Cast<AFarmLand2>(FoundFarms[0]);  
    }

    FoundFarms.Empty();
    UGameplayStatics::GetAllActorsOfClass(GetWorld(),AFarmLand3::StaticClass(), FoundFarms);
    if (FoundFarms.Num() > 0)
    {
        Farm3 = Cast<AFarmLand3>(FoundFarms[0]);  
    }


    FoundFarms.Empty();
   UGameplayStatics::GetAllActorsOfClass(GetWorld(),AFarmLand4::StaticClass(), FoundFarms);
    if (FoundFarms.Num() > 0)
    {
        Farm4 = Cast<AFarmLand4>(FoundFarms[0]);  
    }

    FoundFarms.Empty();
    UGameplayStatics::GetAllActorsOfClass(GetWorld(),AFarmLand5::StaticClass(), FoundFarms);
    if (FoundFarms.Num() > 0)
    {
        Farm5 = Cast<AFarmLand5>(FoundFarms[0]);  
    }
}


void ACropManager::selectCropsF1()
{
    if (Farm)
    {
        Farm->InputCropType(SelectedCropIndex);
    }
    else
    {
        UE_LOG(LogTemp, Warning, TEXT("Farm1 is null!"));
    }
}

void ACropManager::selectCropsF2()
{
    if (Farm2)
    {
        Farm2->InputCropType(SelectedCropIndex);
    }
    else
    {
        UE_LOG(LogTemp, Warning, TEXT("Farm2 is null!"));
    }
}

void ACropManager::selectCropsF3()
{
    if (Farm3)
    {
        Farm3->InputCropType(SelectedCropIndex);
    }
    else
    {
        UE_LOG(LogTemp, Warning, TEXT("Farm3 is null!"));
    }
}

void ACropManager::selectCropsF4()
{
    if (Farm4)
    {
        Farm4->InputCropType(SelectedCropIndex);
    }
    else
    {
        UE_LOG(LogTemp, Warning, TEXT("Farm4 is null!"));
    }
}

void ACropManager::selectCropsF5()
{
    if (Farm5)
    {
        Farm5->InputCropType(SelectedCropIndex);
    }
    else
    {
        UE_LOG(LogTemp, Warning, TEXT("Farm5 is null!"));
    }
}


// Called every frame
void ACropManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ACropManager::AssignCrops()
{
    switch (count)
    {
        case 0:
            selectCropsF1();
            break;
        case 1:
            selectCropsF2();
            break;
        case 2:
            selectCropsF3();
            break;
        case 3:
            selectCropsF4();
            break;
        case 4:
            selectCropsF5();
            break;
        default:
            UE_LOG(LogTemp, Warning, TEXT("No more farms to assign crops to!"));
            return;
    }
    count++;
}

