// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "HealthComponentC.generated.h"


UCLASS( ClassGroup=(Custom), meta=(IsBlueprintBase = "true") )
class COSMOQUEST_API UHealthComponentC : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UHealthComponentC();

	UFUNCTION(BlueprintCallable, Category = "Health")
	void RemoveHealth(float Damage);

	UFUNCTION(BlueprintCallable,  Category = "Health")
	float GetHealth();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	UPROPERTY(EditDefaultsOnly)
	float Health = 100.0f;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
};
