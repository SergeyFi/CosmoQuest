// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "UObject/NoExportTypes.h"
#include "Question.generated.h"

USTRUCT(BlueprintType)
struct FQuestionStruct : public FTableRowBase
{
	GENERATED_BODY()

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Question")
	FText Question;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Question")
	TArray<FText> Answers;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Question")
	int32 Difficulty;
};

/**
 * 
 */
UCLASS(Blueprintable, BlueprintType, DefaultToInstanced, EditInlineNew)
class COSMOQUEST_API UQuestion : public UObject
{
	GENERATED_BODY()

public:

	void InitQuestionData(FQuestionStruct Question);

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Question")
	bool CheckAnswer(const FText& AnswerText);

	UFUNCTION(BlueprintCallable, Category = "Question")
	FText GetQuestion();

	FQuestionStruct QuestionData;
};
