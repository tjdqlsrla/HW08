// Fill out your copyright notice in the Description page of Project Settings.


#include "MyBaseItem.h"
#include "Components/SphereComponent.h"

// Sets default values
AMyBaseItem::AMyBaseItem()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

    // ��Ʈ ������Ʈ ���� �� ����
    Scene = CreateDefaultSubobject<USceneComponent>(TEXT("Scene"));
    SetRootComponent(Scene);

    // �浹 ������Ʈ ���� �� ����
    Collision = CreateDefaultSubobject<USphereComponent>(TEXT("Collision"));
    // ��ħ�� �����ϴ� �������� ����
    Collision->SetCollisionProfileName(TEXT("OverlapAllDynamic"));
    // ��Ʈ ������Ʈ�� ����
    Collision->SetupAttachment(Scene);

    // ����ƽ �޽� ������Ʈ ���� �� ����
    StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
    StaticMesh->SetupAttachment(Collision);
    // �޽ð� ���ʿ��ϰ� �浹�� ���� �ʵ��� �ϱ� ����, ������ NoCollision ������ ������ �� ����.

// Overlap �̺�Ʈ ���ε�
    Collision->OnComponentBeginOverlap.AddDynamic(this, &AMyBaseItem::OnItemOverlap);
    Collision->OnComponentEndOverlap.AddDynamic(this, &AMyBaseItem::OnItemEndOverlap);

}

void AMyBaseItem::OnItemOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
    // OtherActor�� �÷��̾����� Ȯ�� ("Player" �±� Ȱ��)
    if (OtherActor && OtherActor->ActorHasTag("Player"))
    {
        GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Green, FString::Printf(TEXT("Overlap!!!")));
        // ������ ��� (ȹ��) ���� ȣ��
        ActivateItem(OtherActor);
    }
}

// �÷��̾ ������ ������ ����� �� ����
void AMyBaseItem::OnItemEndOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	// �⺻�� �� �Լ� - �ʿ��ϴٸ� �ڽ� Ŭ�������� Ȱ��
}

// �������� ���(Activate)�Ǿ��� �� ����
void AMyBaseItem::ActivateItem(AActor* Activator)
{
    GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Green, FString::Printf(TEXT("Overlap!!")));
}

// ������ ������ ��ȯ
FName AMyBaseItem::GetItemType() const
{
	return ItemType;
}

// �������� �ı�(����)�ϴ� �Լ�
void AMyBaseItem::DestroyItem()
{
	// AActor���� �����ϴ� Destroy() �Լ��� ��ü ����
	Destroy();
}

