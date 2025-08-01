// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "MyItemInterface.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UMyItemInterface : public UInterface
{
	GENERATED_BODY()
};


class HW08_API IMyItemInterface
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
    UFUNCTION()
    virtual void OnItemOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) = 0;
    // 플레이어가 이 아이템의 범위를 벗어났을 때 호출
    UFUNCTION()
    virtual void OnItemEndOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex) = 0;
    // 아이템이 사용되었을 때 호출
    virtual void ActivateItem(AActor* Activator) = 0;
    // 이 아이템의 유형(타입)을 반환 (예: "Coin", "Mine" 등)
    virtual FName GetItemType() const = 0;
};
