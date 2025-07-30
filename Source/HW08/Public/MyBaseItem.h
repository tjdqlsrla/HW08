// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyItemInterface.h"
#include "MyBaseItem.generated.h"

class USphereComponent;

UCLASS()
class HW08_API AMyBaseItem : public AActor, public IMyItemInterface
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMyBaseItem();

protected:

	// ������ ����(Ÿ��)�� ���� �����ϰ� ����
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item")
	FName ItemType;
	// ��Ʈ ������Ʈ (��)
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Item|Component")
	USceneComponent* Scene;
	// �浹 ������Ʈ (�÷��̾� ���� ���� ������)
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Item|Component")
	USphereComponent* Collision;
	// ������ �ð� ǥ���� ����ƽ �޽�
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Item|Component")
	UStaticMeshComponent* StaticMesh;


	// IItemInterface���� �䱸�ϴ� �Լ����� �ݵ�� ����
	virtual void OnItemOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) override;
	virtual void OnItemEndOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex) override;
	virtual void ActivateItem(AActor* Activator) override;
	virtual FName GetItemType() const override;

	// �������� �����ϴ� ���� �Լ� (�߰� ����Ʈ�� ������ ���� �� ����)
	virtual void DestroyItem();

};
