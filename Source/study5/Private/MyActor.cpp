// Fill out your copyright notice in the Description page of Project Settings.


#include "MyActor.h"

// Sets default values
AMyActor::AMyActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMyActor::BeginPlay()
{
	Super::BeginPlay();
	int32 start = 1;
	int32 end = 45;
	int32 num = 0;
	TArray<int32> Numbers;

	for (int32 i = 0; i < 6; ++i)
	{
		num = FMath::RandRange(start, end);
		while (Numbers.Contains(num))
		{
			num = FMath::RandRange(start, end);
		}
		
		Numbers.Add(num);
	}
	
	UE_LOG(LogTemp, Warning, TEXT("Lotto Numbers: %d, %d, %d, %d, %d, %d"), Numbers[0], Numbers[1], Numbers[2], Numbers[3], Numbers[4], Numbers[5]);
}

// Called every frame
void AMyActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

