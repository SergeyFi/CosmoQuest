// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Question.generated.h"

/**
 * 
 */
UCLASS(Blueprintable, BlueprintType, DefaultToInstanced, EditInlineNew)
class COSMOQUEST_API UQuestion : public UObject
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintCallable, Category = "Question")
	bool CheckAnswer(const FText& AnswerText);

protected:

	UFUNCTION(BlueprintNativeEvent)
	bool CheckAnswerImplementable(const FText& AnswerText);

	UPROPERTY(EditDefaultsOnly, Category = "Question")
	FText QuestionText;

	UPROPERTY(EditDefaultsOnly, Category = "Question")
	FText TextAnswer;
};
