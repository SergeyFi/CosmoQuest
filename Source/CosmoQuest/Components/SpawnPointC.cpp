// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/SpawnPointC.h"
#include "Components/QuestionComponentC.h"

bool USpawnPointC::SpawnShip(TSubclassOf<AActor> ShipClass, UDataTable* QuestionTable)
{
	if (!bSpawnCoolDown && ShipClass && QuestionTable)
	{
		CoolDown();

		FActorSpawnParameters SpawnParameters;
		
		auto SpawnedShip = GetWorld()->SpawnActor<AActor>(ShipClass, GetComponentTransform(), SpawnParameters);

		if (SpawnedShip)
		{
			auto QuestionComponent = SpawnedShip->FindComponentByClass<UQuestionComponentC>();

			if (QuestionComponent)
			{
				QuestionComponent->SetQuestionTable(QuestionTable);
				QuestionComponent->AssignRandomQuestion();
			}
		}
	}

	return false;
}

void USpawnPointC::CoolDown()
{
	bSpawnCoolDown = true;
	
	GetWorld()->GetTimerManager().SetTimer(CoolDownTimer, this, &USpawnPointC::ResetCoolDown,
		FMath::RandRange(CoolDownTime, CoolDownTime + AdditionalCooldown));
}

void USpawnPointC::ResetCoolDown()
{
	bSpawnCoolDown = false;
}
