// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyActor.generated.h"

UCLASS()
class HW5_UNREAL_API AMyActor : public AActor
{
	GENERATED_BODY()

public:	
	// Sets default values for this actor's properties
	AMyActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:

	FVector2D start;
	float totDist;
	int32 evCnt;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void Move();

	int32 Step();

	float Distance(FVector2D first, FVector2D second);

	int32 createEvent();
};
