// Fill out your copyright notice in the Description page of Project Settings.


#include "MySpotLight.h"
#include "Components/SpotLightComponent.h"

// Sets default values
AMySpotLight::AMySpotLight()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	MySpotLightComponent = CreateDefaultSubobject<USpotLightComponent>(TEXT("SpotLight Component"));
	MySpotLightComponent->SetupAttachment(RootComponent);
	MySpotLightComponent->Intensity = 150.0f;

}

// Called when the game starts or when spawned
void AMySpotLight::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMySpotLight::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AMySpotLight::SetSpotLightEnabled()
{
}

void AMySpotLight::SetSpotLightDisabled()
{
}

