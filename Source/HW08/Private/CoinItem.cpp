// Fill out your copyright notice in the Description page of Project Settings.


#include "CoinItem.h"
#include "Engine/World.h"
#include "MyGameState.h"

ACoinItem::ACoinItem()
{
    // ���� �⺻���� 0���� ����
    PointValue = 0;
    ItemType = "DefaultCoin";
}

void ACoinItem::ActivateItem(AActor* Activator)
{
    // �÷��̾� �±� Ȯ��
    if (Activator && Activator->ActorHasTag("Player"))
    {
		if (UWorld* World = GetWorld())
		{
			if (AMyGameState* GameState = World->GetGameState<AMyGameState>())
			{
				GameState->AddScore(PointValue);
				GameState->OnCoinCollected();
			}
		}

		DestroyItem();
    }
}