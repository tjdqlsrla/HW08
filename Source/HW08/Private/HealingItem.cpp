// Fill out your copyright notice in the Description page of Project Settings.


#include "HealingItem.h"
#include "MyCharacter.h"

AHealingItem::AHealingItem()
{
	HealAmount = 20;
	ItemType = "Healing";
}

void AHealingItem::ActivateItem(AActor* Activator)
{
    if (Activator && Activator->ActorHasTag("Player"))
    {
		if (AMyCharacter* PlayerCharacter = Cast<AMyCharacter>(Activator))
		{
			// ĳ������ ü���� ȸ��
			PlayerCharacter->AddHealth(HealAmount);
		}

        DestroyItem();
    }
}