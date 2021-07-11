// Fill out your copyright notice in the Description page of Project Settings.


#include "CosmoQuest/Components/AttackComponentC.h"

// Sets default values for this component's properties
UAttackComponentC::UAttackComponentC()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;
}

void UAttackComponentC::Attack()
{
	OnAttack.Broadcast();
}


// Called when the game starts
void UAttackComponentC::BeginPlay()
{
	Super::BeginPlay();
}


// Called every frame
void UAttackComponentC::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

