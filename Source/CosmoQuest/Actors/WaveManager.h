// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Engine/DataTable.h"
#include "WaveManager.generated.h"

USTRUCT(BlueprintType)
struct FWave: public FTableRowBase
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere)
	int32 ShipsCount;

	UPROPERTY(EditAnywhere)
	TArray<TSubclassOf<AActor>> ShipsClasses;

	UPROPERTY(EditAnywhere)
	UDataTable* QuestionTable;
};

UCLASS( ClassGroup=(Custom), meta=(IsBlueprintBase = "true") )
class COSMOQUEST_API AWaveManager : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AWaveManager();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// UPROPERTY(EditAnywhere)
	// UWaveDA* WavesDataAsset;

	UPROPERTY(EditAnywhere)
	float PauseBetweenWaves = 5.0f;

	UPROPERTY(EditAnywhere)
	float PauseBetweenSpawnMax = 6.0f;

	UPROPERTY(EditAnywhere)
	float PauseBetweenSpawnMin = 3.0f;

};
