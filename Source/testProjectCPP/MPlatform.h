// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/StaticMeshActor.h"
#include "MPlatform.generated.h"

/**
 * 
 */
UCLASS()
class TESTPROJECTCPP_API AMPlatform : public AStaticMeshActor
{
	GENERATED_BODY()
public:
	AMPlatform();
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float Speed = 20;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Meta = (MakeEditWidget = ture))
		FVector TargetLocation;

private:
	FVector GlobalStartLocation;
	FVector GlobalTargetLocation;
};
