// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Particles/ParticleSystem.h"
#include "MyParticleSystem.generated.h"

UCLASS()
class TESTPROJECTCPP_API AMyParticleSystem : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMyParticleSystem();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		class UParticleSystem* MyParticleComponent;
	

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
