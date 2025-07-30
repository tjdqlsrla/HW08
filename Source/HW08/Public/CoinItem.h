// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MyBaseItem.h"
#include "CoinItem.generated.h"

/**
 * 
 */
UCLASS()
class HW08_API ACoinItem : public AMyBaseItem
{
	GENERATED_BODY()
	
public:
	ACoinItem();

protected:
	// ���� ȹ�� �� ���� ���� (�ڽ� Ŭ�������� ��ӹ޾� ���� �ٲ��� ����)
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item")
	int32 PointValue;

	// �θ� Ŭ�������� ��ӹ��� ActivateItem �Լ��� �������̵�
	virtual void ActivateItem(AActor* Activator) override;
};
