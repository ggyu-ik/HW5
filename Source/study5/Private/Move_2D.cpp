// Fill out your copyright notice in the Description page of Project Settings.


#include "Move_2D.h"

// Sets default values
AMove_2D::AMove_2D()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

void AMove_2D::move()
{
	if (step() == 1)
	{
		location.X += 1;
	}
	if (step() == 1)
	{
		location.Y += 1;
	}
}

int32 AMove_2D::step() // 50% 확률구하기 이동용
{
	if (FMath::RandRange(0, 1))
	{
		return 1;
	}
		return 0;
}

float AMove_2D::distance(FVector2D a, FVector2D b) // 두 좌표 거리 구하기 
{
	return FMath::Sqrt((b.X - a.X) * (b.X - a.X) + (b.Y - a.Y) * (b.Y - a.Y));
}

int32 AMove_2D::createEvent() // 50% 확률구하기 이벤트용
{
	if (FMath::RandRange(0, 1))
	{
		return 1;
	}
	return 0;
}

// Called when the game starts or when spawned
void AMove_2D::BeginPlay()
{
	Super::BeginPlay();

	int32 count = 0; // 이동 횟수
	evCnt = 0;
	totDist = 0;
	location = FVector2D(0, 0);

	UE_LOG(LogTemp, Error, TEXT("move start, Current Location(%.0f, %.0f)"), location.X, location.Y); // 시작 좌표 출력

	while (count < 10)
	{
		start = FVector2D(location.X, location.Y);
		
		move();

		end = FVector2D(location.X, location.Y); // 이동 후 좌표

		UE_LOG(LogTemp, Warning, TEXT("Current Location(%.0f, %.0f), Move Distance: %.3f"), location.X, location.Y, distance(start, end)); // 이동 후 좌표, 거리 출력

		totDist += distance(start, end); // 총 이동 거리 구하기

		if (createEvent() == 1) // 50% 확률로 이벤트 출력
		{
			UE_LOG(LogTemp, Error, TEXT("Event!"));
			evCnt++; // 이벤트 카운트 증가
		}
		count++;
	}
	UE_LOG(LogTemp, Error, TEXT("TOTAL EVENT : %d, TOTAL DISTANCE : %.3f"), evCnt, totDist); // 총 이벤트 발생 횟수, 이동 거리 출력
}

// Called every frame
void AMove_2D::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

