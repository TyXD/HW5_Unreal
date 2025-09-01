// Fill out your copyright notice in the Description page of Project Settings.


#include "MyActor.h"

// Sets default values
AMyActor::AMyActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	start = FVector2D(0, 0);
	totDist = 0.0f;
	evCnt = 0;
}

// Called when the game starts or when spawned
void AMyActor::BeginPlay()
{
	Super::BeginPlay();


	Move();

}

// Called every frame
void AMyActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AMyActor::Move()
{
	FVector2D previous;

	UE_LOG(LogTemp, Error, TEXT("Start | X: %f, Y: %f"), start.X, start.Y);

	for (int i = 0; i < 10; i++)
	{
		previous = start;

		start.X += Step();
		start.Y += Step();



		UE_LOG(LogTemp, Error, TEXT("Move: %d\t|\tX: %f, Y: %f"), i+1, start.X, start.Y);
		UE_LOG(LogTemp, Warning, TEXT("Distance: %f\t"), Distance(previous, start));

		totDist += Distance(previous, start);
		evCnt += createEvent();
	}

	UE_LOG(LogTemp, Warning, TEXT("Distance\t|\t%f"), totDist);
	UE_LOG(LogTemp, Warning, TEXT("Event Count \t|\t%d"), evCnt);

}

int32 AMyActor::Step()
{
	return FMath::RandRange(0, 1);
}

float AMyActor::Distance(FVector2D first, FVector2D second)
{
	return FVector2D::Distance(first, second);
}

int32 AMyActor::createEvent()
{
	if (FMath::RandRange(1, 100) <= 50)
	{
		UE_LOG(LogTemp, Warning, TEXT("이벤트가 발생하였습니다."));

		return 1;
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("이벤트가 발생하지 않았습니다."));

		return 0;
	}
}