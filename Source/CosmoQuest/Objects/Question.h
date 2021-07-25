// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Question.generated.h"

USTRUCT(BlueprintType)
struct FQuestionStruct
{
	GENERATED_BODY()

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Question")
	FText Question;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Question")
	TArray<FText> Answers;
};

/**
 * 
 */
UCLASS(Blueprintable, BlueprintType, DefaultToInstanced, EditInlineNew)
class COSMOQUEST_API UQuestion : public UObject
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Question")
	bool CheckAnswer(const FText& AnswerText);

	FQuestionStruct QuestionData;
};
