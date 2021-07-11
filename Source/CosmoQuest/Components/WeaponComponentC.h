// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "WeaponComponentC.generated.h"

USTRUCT(BlueprintType)
struct FWeaponData
{
	GENERATED_BODY()

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<AActor> Projectile;

	UPROPERTY(EditDefaultsOnly, meta = (MakeEditWidget = true))
	FVector ProjectileOffset;
};

/**
 * 
 */
UCLASS( ClassGroup=(Custom), meta=(IsBlueprintBase = "true") )
class COSMOQUEST_API UWeaponComponentC : public UStaticMeshComponent
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	void Fire();

	UPROPERTY(EditDefaultsOnly)
	FWeaponData WeaponData;

	
protected:
	// Called when the game starts
	virtual void BeginPlay() override;

private:

	void BindToAttackComponent();
};
