#include "MyGameState.h"
#include "kismet/GameplayStatics.h"
#include "SpawnVolume.h"
#include "CoinItem.h"

AMyGameState::AMyGameState()
{
	Score = 0;
	SpawnedCoinCount = 0;
	CollectedCoinCount = 0;
	LevelDuration = 30.0f; // �� ������ 30��
	CurrentLevelIndex = 0;
	MaxLevels = 3;
}

void AMyGameState::BeginPlay()
{
	Super::BeginPlay();

	// ���� ���� �� ù �������� ����
	StartLevel();
}

int32 AMyGameState::GetScore() const
{
	return Score;
}

void AMyGameState::AddScore(int32 Amount)
{
	Score += Amount;
	UE_LOG(LogTemp, Warning, TEXT("Score: %d"), Score);
}

void AMyGameState::StartLevel()
{
	// ���� ���� ��, ���� ���� �ʱ�ȭ
	SpawnedCoinCount = 0;
	CollectedCoinCount = 0;

	// ���� �ʿ� ��ġ�� ��� SpawnVolume�� ã�� ������ 40���� ����
	TArray<AActor*> FoundVolumes;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ASpawnVolume::StaticClass(), FoundVolumes);

	const int32 ItemToSpawn = 40;

	for (int32 i = 0; i < ItemToSpawn; i++)
	{
		if (FoundVolumes.Num() > 0)
		{
			ASpawnVolume* SpawnVolume = Cast<ASpawnVolume>(FoundVolumes[0]);
			if (SpawnVolume)
			{
				AActor* SpawnedActor = SpawnVolume->SpawnRandomItem();
				// ���� ������ ���Ͱ� ���� Ÿ���̶�� SpawnedCoinCount ����
				if (SpawnedActor && SpawnedActor->IsA(ACoinItem::StaticClass()))
				{
					SpawnedCoinCount++;
				}
			}
		}
	}

	// 30�� �Ŀ� OnLevelTimeUp()�� ȣ��ǵ��� Ÿ�̸� ����
	GetWorldTimerManager().SetTimer(
		LevelTimerHandle,
		this,
		&AMyGameState::OnLevelTimeUp,
		LevelDuration,
		false
	);

	UE_LOG(LogTemp, Warning, TEXT("Level %d Start!, Spawned %d coin"),
		CurrentLevelIndex + 1,
		SpawnedCoinCount);
}

void AMyGameState::OnLevelTimeUp()
{
	// �ð��� �� �Ǹ� ������ ����
	EndLevel();
}

void AMyGameState::OnCoinCollected()
{
	CollectedCoinCount++;

	UE_LOG(LogTemp, Warning, TEXT("Coin Collected: %d / %d"),
		CollectedCoinCount,
		SpawnedCoinCount)

		// ���� �������� ������ ������ ���� �ֿ��ٸ� ��� ���� ����
		if (SpawnedCoinCount > 0 && CollectedCoinCount >= SpawnedCoinCount)
		{
			EndLevel();
		}
}

void AMyGameState::EndLevel()
{
	// Ÿ�̸� ����
	GetWorldTimerManager().ClearTimer(LevelTimerHandle);
	// ���� ���� �ε�����
	CurrentLevelIndex++;

	// ��� ������ �� ���Ҵٸ� ���� ���� ó��
	if (CurrentLevelIndex >= MaxLevels)
	{
		OnGameOver();
		return;
	}

	// ���� �� �̸��� �ִٸ� �ش� �� �ҷ�����
	if (LevelMapNames.IsValidIndex(CurrentLevelIndex))
	{
		UGameplayStatics::OpenLevel(GetWorld(), LevelMapNames[CurrentLevelIndex]);
	}
	else
	{
		// �� �̸��� ������ ���ӿ���
		OnGameOver();
	}
}

void AMyGameState::OnGameOver()
{
	UE_LOG(LogTemp, Warning, TEXT("Game Over!!"));
	// ���⼭ UI�� ���ٰų�, ����� ����� ���� ���� ����
}