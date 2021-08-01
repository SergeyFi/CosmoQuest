// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "Engine/DataTable.h"
#include "WaveDA.generated.h"

USTRUCT(BlueprintType)
struct FWave
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
class COSMOQUEST_API UWaveDA : public UDataAsset
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere)
	TArray<FWave> Waves;
};
