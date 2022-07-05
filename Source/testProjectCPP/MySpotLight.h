// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MySpotLight.generated.h"

UCLASS()
class TESTPROJECTCPP_API AMySpotLight : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMySpotLight();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(VisibleAnywhere, BlueprintsReadOnly)
		class USpotLightComponent* MySpotLightComponent;

	UFUNCTION()
		void SetSpotLightEnabled();

	UFUNCTION()
		void SetSpotLightDisabled();
};
