// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "ShipMovementComponentC.generated.h"


UCLASS( ClassGroup=(Custom), meta=(IsBlueprintBase = "true") )
class COSMOQUEST_API UShipMovementComponentC : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UShipMovementComponentC();

	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION(BlueprintCallable)
	void StopMovement();

	UFUNCTION(BlueprintCallable)
	void StopRotation();

	UFUNCTION(BlueprintCallable)
	void SetMovementDirection(FVector Direction, UCurveFloat* SpeedCurve);

	UFUNCTION(BlueprintCallable)
	void RotateToRotator(FRotator Rotation);

	UFUNCTION(BlueprintCallable)
	void RotateToActor(AActor* Target);
	
	UFUNCTION(BlueprintPure)
	bool IsRotating();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	UPROPERTY(EditDefaultsOnly)
	float RotationSpeed;

private:

	float MovementTime;

	void StartTick();

	void StopTick();

	FVector MovementVector;

	FRotator TargetRotation;

	UPROPERTY()
	UCurveFloat* ShipSpeedCurve;

	bool bRotate;
};
