// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Move_2D.generated.h"

UCLASS()
class STUDY5_API AMove_2D : public AActor
{
	GENERATED_BODY()
	FVector2D location;
	FVector2D start;
	FVector2D end;
	int32 evCnt;
	float totDist;

public:	
	// Sets default values for this actor's properties
	AMove_2D();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	int32 step();
	void move();
	float distance(FVector2D a, FVector2D b);
	int32 createEvent();

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
