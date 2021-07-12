// Fill out your copyright notice in the Description page of Project Settings.


#include "DamageDealer.h"
#include "Components/HealthComponentC.h"

void UDamageDealer::ApplyDamage_Implementation(AActor* DamageTarget, float Damage)
{
	UHealthComponentC* HealthComponent = DamageTarget->FindComponentByClass<UHealthComponentC>();

	if (HealthComponent)
	{
		HealthComponent->RemoveHealth(Damage);
	}
}
