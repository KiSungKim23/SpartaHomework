// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyActor.generated.h"

UCLASS()
class TEST11_API AMyActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMyActor();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Move")
	FVector DestPosition = FVector::ZeroVector;
	FVector StartPosition = FVector::ZeroVector;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Move")
	int nowMove;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Move")
	float moveSpeed = 100.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Move")
	float Tolerance = 5.f;

	UFUNCTION(BlueprintCallable, Category = "Move")
	void MoveToDest();

	void SetLog();
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	const int maxMove = 10;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	int32 Step();

};
