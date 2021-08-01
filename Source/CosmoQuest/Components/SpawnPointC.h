// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ArrowComponent.h"
#include "Engine/DataTable.h"
#include "SpawnPointC.generated.h"

/**
 * 
 */
UCLASS( ClassGroup=(Custom), meta=(IsBlueprintBase = "true") )
class COSMOQUEST_API USpawnPointC : public UArrowComponent
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "Spawn")
	bool SpawnShip(TSubclassOf<AActor> ShipClass, UDataTable* QuestionTable);

protected:

	UPROPERTY(EditDefaultsOnly)
	float CoolDownTime = 5.0f;

	UPROPERTY(EditDefaultsOnly)
	float AdditionalCooldown = 2.0f;
	
	bool bSpawnCoolDown;

	void CoolDown();

	FTimerHandle CoolDownTimer;

	UFUNCTION()
	void ResetCoolDown();
};
