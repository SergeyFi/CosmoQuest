// Fill out your copyright notice in the Description page of Project Settings.


#include "Objects/Question.h"

bool UQuestion::CheckAnswer_Implementation(const FText& AnswerText)
{
	for (auto Answer : QuestionData.Answers)
	{
		if (Answer.EqualTo(AnswerText))
		{
			return true;
		}
	}

	return false;
}

void UQuestion::InitQuestionData(FQuestionStruct Question)
{
	QuestionData = Question;
}

FText UQuestion::GetQuestion()
{
	return QuestionData.Question;
}
