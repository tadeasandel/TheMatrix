// Fill out your copyright notice in the Description page of Project Settings.

#include "OpenDoor.h"
#include "GameFramework/Actor.h"

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

	InitialYaw = GetOwner()->GetActorRotation().Yaw;
	CurrentYaw = InitialYaw;
	TargetYaw += InitialYaw;
}

// Called every frame
void UOpenDoor::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	UE_LOG(LogTemp, Warning, TEXT("%f , %f"), TargetYaw, GetOwner()->GetActorRotation().Yaw);

	// float StartingYaw = GetOwner()->GetActorRotation().Yaw;
	// FRotator OpenDoor = FRotator(0, TargetYaw, 0);
	// OpenDoor.Yaw = FMath::Lerp(StartingYaw, TargetYaw, 0.1f);
	// FMath::Clamp(OpenDoor.Yaw, 0f, 90f);

	CurrentYaw = FMath::Lerp(CurrentYaw, TargetYaw, 0.05f * DeltaTime);
	FRotator DoorRotation = GetOwner()->GetActorRotation();
	DoorRotation.Yaw = CurrentYaw;
	GetOwner()->SetActorRotation(DoorRotation);
}
