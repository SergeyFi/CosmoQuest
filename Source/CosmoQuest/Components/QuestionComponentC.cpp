// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/QuestionComponentC.h"

// Sets default values for this component's properties
UQuestionComponentC::UQuestionComponentC()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;
}

bool UQuestionComponentC::CheckAnswer(const FText& Text)
{
	if (CurrentQuestion)
	{
		return CurrentQuestion->CheckAnswer(Text);
	}

	return false;
}


// Called when the game starts
void UQuestionComponentC::BeginPlay()
{
	Super::BeginPlay();

	AssignRandomQuestion();
	
}

void UQuestionComponentC::AssignRandomQuestion()
{
	if (QuestionData->Questions.Num() > 0)
	{
		CurrentQuestion = QuestionData->Questions[FMath::RandRange(0, QuestionData->Questions.Num() - 1)];
	}
}
