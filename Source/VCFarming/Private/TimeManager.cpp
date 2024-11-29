
#include "TimeManager.h"

// Sets default values
ATimeManager::ATimeManager()
{
	PrimaryActorTick.bCanEverTick = true;
	SessionTimerLeft = 1200;
}

// Called when the game starts or when spawned
void ATimeManager::BeginPlay()
{
	Super::BeginPlay();
	GetWorld()->GetTimerManager().SetTimer(timeHandle, this, &ATimeManager::Timer, 1.0f, true);
}

void ATimeManager::Timer()
{
	SessionTimerLeft--;
	if(SessionTimerLeft<=0)
	{
		SessionTimerLeft = 0;
	}
}

// Called every frame
void ATimeManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

