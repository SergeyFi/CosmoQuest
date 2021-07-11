// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AttackComponentC.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FAttack);

UCLASS( ClassGroup=(Custom), meta=(IsBlueprintBase = "true") )
class COSMOQUEST_API UAttackComponentC : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UAttackComponentC();

	UFUNCTION(BlueprintCallable)
	void Attack();

	UPROPERTY(BlueprintAssignable)
	FAttack OnAttack;

	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;
		
};
