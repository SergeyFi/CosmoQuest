// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "DamageDealer.generated.h"

/**
 * 
 */
UCLASS(Blueprintable)
class COSMOQUEST_API UDamageDealer : public UObject
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "DamageDealer")
	void ApplyDamage(AActor* Target, float Damage);
};
