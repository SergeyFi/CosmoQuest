// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Engine/DataTable.h"
#include "Objects/Question.h"
#include "QuestionComponentC.generated.h"

UCLASS( ClassGroup=(Custom), meta=(IsBlueprintBase = "true") )
class COSMOQUEST_API UQuestionComponentC : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UQuestionComponentC();

	UFUNCTION(BlueprintCallable, Category = "Question")
	bool CheckAnswer(const FText& Text);

	UFUNCTION(BlueprintPure, Category = "Question")
	FText GetQuestion();

	void SetQuestionTable(UDataTable* Table);

	void AssignRandomQuestion();

protected:

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UQuestion* CurrentQuestion;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	UDataTable* QuestionTable;
};
