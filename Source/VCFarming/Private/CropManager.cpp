

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

    // Get all instances of AFarmLand and assign to a list
    UGameplayStatics::GetAllActorsOfClass(GetWorld(), AFarmLand::StaticClass(), FoundFarms1);
    
    // Get all instances of AFarmLand2 and assign to a list
    UGameplayStatics::GetAllActorsOfClass(GetWorld(), AFarmLand2::StaticClass(), FoundFarms2);

    // Get all instances of AFarmLand3 and assign to a list
    UGameplayStatics::GetAllActorsOfClass(GetWorld(), AFarmLand3::StaticClass(), FoundFarms3);

    // Get all instances of AFarmLand4 and assign to a list
    UGameplayStatics::GetAllActorsOfClass(GetWorld(), AFarmLand4::StaticClass(), FoundFarms4);

    // Get all instances of AFarmLand5 and assign to a list
    UGameplayStatics::GetAllActorsOfClass(GetWorld(), AFarmLand5::StaticClass(), FoundFarms5);
}


void ACropManager::selectCropsF1()
{
    for (AActor* FarmActor : FoundFarms1)
    {
        AFarmLand* FarmInstance = Cast<AFarmLand>(FarmActor);
        if (FarmInstance)
        {
            FarmInstance->InputCropType(SelectedCropIndex);
        }
        else
        {
            UE_LOG(LogTemp, Warning, TEXT("Farm1 is null!"));
        }
    }
}

// Function to apply crops to all instances of AFarmLand2
void ACropManager::selectCropsF2()
{
    for (AActor* FarmActor : FoundFarms2)
    {
        AFarmLand2* FarmInstance = Cast<AFarmLand2>(FarmActor);
        if (FarmInstance)
        {
            FarmInstance->InputCropType(SelectedCropIndex);
        }
        else
        {
            UE_LOG(LogTemp, Warning, TEXT("Farm2 is null!"));
        }
    }
}
void ACropManager::selectCropsF3()
{
    for (AActor* FarmActor : FoundFarms3)
    {
        AFarmLand3* FarmInstance = Cast<AFarmLand3>(FarmActor);
        if (FarmInstance)
        {
            FarmInstance->InputCropType(SelectedCropIndex);
        }
        else
        {
            UE_LOG(LogTemp, Warning, TEXT("Farm3 is null!"));
        }
    }
}

// Function to apply crops to all instances of AFarmLand2
void ACropManager::selectCropsF4()
{
    for (AActor* FarmActor : FoundFarms4)
    {
        AFarmLand4* FarmInstance = Cast<AFarmLand4>(FarmActor);
        if (FarmInstance)
        {
            FarmInstance->InputCropType(SelectedCropIndex);
        }
        else
        {
            UE_LOG(LogTemp, Warning, TEXT("Farm4 is null!"));
        }
    }
}

void ACropManager::selectCropsF5()
{
    for (AActor* FarmActor : FoundFarms5)
    {
        AFarmLand5* FarmInstance = Cast<AFarmLand5>(FarmActor);
        if (FarmInstance)
        {
            FarmInstance->InputCropType(SelectedCropIndex);
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

