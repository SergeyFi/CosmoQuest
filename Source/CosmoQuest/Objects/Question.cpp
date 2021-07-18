// Fill out your copyright notice in the Description page of Project Settings.


#include "Objects/Question.h"

bool UQuestion::CheckAnswer(const FText& AnswerText)
{
	return  CheckAnswerImplementable(AnswerText);
}

bool UQuestion::CheckAnswerImplementable_Implementation(const FText& AnswerText)
{
	return AnswerText.EqualTo(TextAnswer);
}
