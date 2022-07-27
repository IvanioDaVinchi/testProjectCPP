// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyDoor.generated.h"

UCLASS()
class TESTPROJECTCPP_API AMyDoor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMyDoor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION()
		void OpenDoor(float dt);

	UFUNCTION()
		void ToggleDoor(FVector ForvardVector);

	UFUNCTION()
		void CloseDoor(float dt);

	UPROPERTY(EditAnywhere)
		class UStaticMeshComponent* Door;

	UPROPERTY(EditAnywhere)
		class UBoxComponent* BoxComp;

	bool Closing;
	bool Opening;
	bool isClosed;

	float MaxDegree;
	float AddRotation;
	float DoorCurrentRotation;
	float PosNeg;
	float DotP;
};
