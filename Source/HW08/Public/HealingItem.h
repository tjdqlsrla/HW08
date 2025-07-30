// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MyBaseItem.h"
#include "HealingItem.generated.h"


UCLASS()
class HW08_API AHealingItem : public AMyBaseItem
{
	GENERATED_BODY()
	

public:
	AHealingItem();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item")
	int32 HealAmount;

	virtual void ActivateItem(AActor* Activator) override;
};
