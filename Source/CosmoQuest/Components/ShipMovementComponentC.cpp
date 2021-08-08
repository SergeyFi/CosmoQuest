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
	StartTick();

	bForwardMovement = true;
}

void UShipMovementComponentC::StopMovement()
{
	StopTick();

	bForwardMovement = false;
}


// Called when the game starts
void UShipMovementComponentC::BeginPlay()
{
	Super::BeginPlay();
}

void UShipMovementComponentC::StartTick()
{
	SetComponentTickEnabled(true);
}

void UShipMovementComponentC::StopTick()
{
	SetComponentTickEnabled(false);

	Time = 0.0f;
}

void UShipMovementComponentC::ForwardMovement(float DeltaTime)
{
	if (bForwardMovement)
	{
		GetOwner()->AddActorLocalOffset(GetOwner()->GetActorForwardVector() * ShipSpeedCurve->GetFloatValue(Time) * DeltaTime);
	}
}


// Called every frame
void UShipMovementComponentC::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	Time += DeltaTime;

	ForwardMovement(DeltaTime);
}

