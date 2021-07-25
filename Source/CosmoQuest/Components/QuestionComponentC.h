// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Engine/DataTable.h"
#include "Objects/Data/QuestionData.h"

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

	UFUNCTION(BlueprintCallable, Category = "Question")
	FText GetQuestion();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UQuestion* CurrentQuestion;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UDataTable* QuestionTable;

	void AssignRandomQuestion();
};
