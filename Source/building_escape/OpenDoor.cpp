// Copyright Michał Jędrzejek 2021


#include "OpenDoor.h"
#include "building_escapeGameModeBase.h"

// Sets default values for this component's properties
UOpenDoor::UOpenDoor()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UOpenDoor::BeginPlay()
{
	Super::BeginPlay();

	/*float MyFloat = 180.f;

	FRotator CurrentRotation = GetOwner()->GetActorRotation();

	CurrentRotation.Yaw = MyFloat;

	GetOwner()->SetActorRotation(CurrentRotation);*/
}


// Called every frame
void UOpenDoor::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	//UE_LOG(LogTemp, Warning, TEXT("%s"), *GetOwner()->GetActorRotation().ToString());
	UE_LOG(LogTemp, Warning, TEXT("Yaw: %f"), GetOwner()->GetActorRotation().Yaw);

	float CurrentYaw = GetOwner()->GetActorRotation().Yaw;
	FRotator Target(0.f, TargetYaw, 0.f);
	Target.Yaw = FMath::Lerp(CurrentYaw, 0.f, 0.05f);
	GetOwner()->SetActorRotation(Target);
}

