// Fill out your copyright notice in the Description page of Project Settings.


#include "CosmoQuest/Components/ShipMovementComponentC.h"
#include "Kismet/KismetMathLibrary.h"

// Sets default values for this component's properties
UShipMovementComponentC::UShipMovementComponentC()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
	PrimaryComponentTick.bStartWithTickEnabled = true;

}

void UShipMovementComponentC::StopMovement()
{
	MovementTime = 0.0f;

	ShipSpeedCurve = nullptr;

	MovementVector = FVector(0.0f);
}

void UShipMovementComponentC::StopRotation()
{
	TargetRotation = FRotator(0.0F);
	bRotate = false;
}

void UShipMovementComponentC::SetMovementDirection(FVector Direction, UCurveFloat* SpeedCurve)
{
	MovementVector = Direction;
	ShipSpeedCurve = SpeedCurve;
}

void UShipMovementComponentC::RotateToRotator(FRotator Rotation)
{
	Rotation.Normalize();
	TargetRotation = Rotation;
	bRotate = true;
}

void UShipMovementComponentC::RotateToActor(AActor* Target)
{
	if (Target)
	{
		auto NewRotation = UKismetMathLibrary::FindLookAtRotation(GetOwner()->GetActorLocation(), Target->GetActorLocation());

		RotateToRotator(NewRotation);
	}
}

bool UShipMovementComponentC::IsRotating()
{
	return bRotate;
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
}


// Called every frame
void UShipMovementComponentC::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (!MovementVector.IsZero())
	{
		MovementTime += DeltaTime;
		
		if (ShipSpeedCurve)
		{
			GetOwner()->AddActorLocalOffset(MovementVector * DeltaTime * ShipSpeedCurve->GetFloatValue(MovementTime));
		}
	}

	if (!TargetRotation.IsZero())
	{
		GetOwner()->SetActorRotation(FMath::RInterpConstantTo(
			GetOwner()->GetActorRotation(),
			TargetRotation,
			DeltaTime,
			RotationSpeed
			));

		if (TargetRotation.Equals(GetOwner()->GetActorRotation(), 1.0f))
		{
			StopRotation();
		}
		
	}
}

