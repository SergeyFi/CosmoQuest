// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "Objects/Question.h"
#include "QuestionData.generated.h"

/**
 * 
 */
UCLASS(BlueprintType, Blueprintable, meta = (IsBlueprintBase = "true"))
class COSMOQUEST_API UQuestionData : public UDataAsset
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Instanced)
	TArray<UQuestion*> Questions;
};
