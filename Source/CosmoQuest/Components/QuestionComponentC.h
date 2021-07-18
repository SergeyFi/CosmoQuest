// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
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
	void CheckAnswer(const FText& Text);

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UQuestion* CurrentQuestion;

	UPROPERTY(EditDefaultsOnly, Category = "Question")
	UQuestionData* QuestionData;

	void AssignRandomQuestion();

	
};
