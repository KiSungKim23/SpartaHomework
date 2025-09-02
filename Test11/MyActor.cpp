// Fill out your copyright notice in the Description page of Project Settings.


#include "MyActor.h"

// Sets default values
AMyActor::AMyActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	nowMove = 0;
}

void AMyActor::MoveToDest()
{
	const FVector Current = GetActorLocation();
	DestPosition.X = Current.X + Step();
	DestPosition.Y = Current.Y + Step();
	StartPosition = Current;
	nowMove++;
}

void AMyActor::SetLog()
{
	float dx = StartPosition.X - DestPosition.X;
	float dy = StartPosition.Y - DestPosition.Y;
	auto distance = FMath::Sqrt(dx * dx + dy * dy);
	UE_LOG(LogTemp, Log, TEXT("at X : %f , Y : %f "), DestPosition.X, DestPosition.Y);
	UE_LOG(LogTemp, Log, TEXT("distacne : %f"), distance);
}

// Called when the game starts or when spawned
void AMyActor::BeginPlay()
{
	Super::BeginPlay();
	StartPosition = GetActorLocation();
	nowMove = 0;
}

// Called every frame
void AMyActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (nowMove == 0)
	{
		MoveToDest();
	}

	if (nowMove <= maxMove)
	{
		const FVector Curr = GetActorLocation();
		const FVector Next = FMath::VInterpConstantTo(Curr, DestPosition, DeltaTime, moveSpeed);
		SetActorLocation(Next, false);

		if (FVector::DistSquared(Next, DestPosition) <= FMath::Square(Tolerance))
		{
			SetLog();
			SetActorLocation(DestPosition, false);
			MoveToDest();
		}
	}

	//SetActorLocation()
}

int32 AMyActor::Step()
{
	return FMath::RandRange(10, 20);
}

