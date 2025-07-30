#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ItemSpawnRow.h"
#include "SpawnVolume.generated.h"

class UBoxComponent;

UCLASS()
class HW08_API ASpawnVolume : public AActor
{
    GENERATED_BODY()

public:
    ASpawnVolume();

    UFUNCTION(BlueprintCallable, Category = "Spawning")
    AActor* SpawnRandomItem(); // ���� ������ AActor* �� ����

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Spawning")
    USceneComponent* Scene;
    // ���� ������ ����� �ڽ� ������Ʈ
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Spawning")
    UBoxComponent* SpawningBox;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Spawning")
    UDataTable* ItemDataTable;


    FVector GetRandomPointInVolume() const;
    FItemSpawnRow* GetRandomItem() const;
    AActor* SpawnItem(TSubclassOf<AActor> ItemClass);
};