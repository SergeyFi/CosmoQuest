// Fill out your copyright notice in the Description page of Project Settings.


#include "CosmoQuest/Components/ShipMovementComponentC.h"

// Sets default values for this component's properties
UShipMovementComponentC::UShipMovementComponentC()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
	PrimaryComponentTick.bStartWithTickEnabled = false;

}

void UShipMovementComponentC::StartMovement()
{
	SetComponentTickEnabled(true);
}

void UShipMovementComponentC::StopMovement()
{
	SetComponentTickEnabled(false);
}


// Called when the game starts
void UShipMovementComponentC::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UShipMovementComponentC::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	Time += DeltaTime;

	GetOwner()->AddActorLocalOffset(GetOwner()->GetActorForwardVector() * ShipSpeedCurve->GetFloatValue(Time) * DeltaTime);
}

