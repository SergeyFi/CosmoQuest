// Fill out your copyright notice in the Description page of Project Settings.


#include "CosmoQuest/Components/WeaponComponentC.h"
#include "AttackComponentC.h"

void UWeaponComponentC::Fire_Implementation()
{
	if (WeaponData.Projectile)
	{		
		GetWorld()->SpawnActor<AActor>(WeaponData.Projectile, GetComponentLocation() + WeaponData.ProjectileOffset, GetComponentRotation());
	}
}

void UWeaponComponentC::BeginPlay()
{
	Super::BeginPlay();

	BindToAttackComponent();
}

void UWeaponComponentC::BindToAttackComponent()
{
	auto AttackComponent = GetOwner()->FindComponentByClass<UAttackComponentC>();

	if (AttackComponent)
	{
		AttackComponent->OnAttack.AddDynamic(this, &UWeaponComponentC::Fire);
	}
}
