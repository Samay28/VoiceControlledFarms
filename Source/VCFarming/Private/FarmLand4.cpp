

#include "FarmLand4.h"

// Sets default values
AFarmLand4::AFarmLand4()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	FarmMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("FarmMesh"));
	FarmMesh->SetupAttachment(GetRootComponent());

	CropTypeMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("CropMesh"));
	CropTypeMesh->SetupAttachment(FarmMesh);

}

// Called when the game starts or when spawned
void AFarmLand4::BeginPlay()
{
	Super::BeginPlay();
	CropTypeMesh->SetVisibility(false);
}

// Called every frame
void AFarmLand4::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AFarmLand4::InputCropType(int index, float SuccessRate)
{
	if(CropMeshes.IsValidIndex(index))
	{
		CropTypeMesh->SetVisibility(true);
		CropTypeMesh->SetStaticMesh(CropMeshes[index]);
		CurrentSuccessRate = SuccessRate;
		UE_LOG(LogTemp, Warning, TEXT("CurrentSuccessRate : %f"), CurrentSuccessRate);
		CropsGrown = true;
	}
}

void AFarmLand4::IncreaseSuccessRate(float Delta)
{
	CurrentSuccessRate += Delta;
	UE_LOG(LogTemp, Warning, TEXT("Increased CurrentSuccessRate : %f"), CurrentSuccessRate);
}
