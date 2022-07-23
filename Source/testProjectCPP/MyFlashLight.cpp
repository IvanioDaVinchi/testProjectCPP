// Fill out your copyright notice in the Description page of Project Settings.


#include "MyFlashLight.h"
#include "Components/BoxComponent.h"
#include "Components/PointLightComponent.h"
#include <Runtime/Engine/Classes/Kismet/GameplayStatics.h>

// Sets default values
AMyFlashLight::AMyFlashLight()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	TriggerBox = CreateDefaultSubobject<UBoxComponent>("TriggerBox");
	TriggerBox->SetupAttachment(RootComponent);
	PointLight = CreateDefaultSubobject<UPointLightComponent>("Point Light");
	
	TriggerBox->OnComponentBeginOverlap.AddDynamic(this, &AMyFlashLight::Triggered);
	TriggerBox->OnComponentEndOverlap.AddDynamic(this, &AMyFlashLight::UnTriggered);
}

void AMyFlashLight::Triggered(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor && (OtherActor != this) && OtherComp)
	{
		EnableInput(UGameplayStatics::GetPlayerController(GetWorld(), 0));
	}
}

void AMyFlashLight::UnTriggered(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	if (OtherActor && (OtherActor != this) && OtherComp)
	{
		DisableInput(UGameplayStatics::GetPlayerController(GetWorld(), 0));
	}
}

void AMyFlashLight::SetPointLightEnabled()
{
	PointLight->SetVisibility(true);
}

void AMyFlashLight::SetPointLightDisabled()
{
	PointLight->SetVisibility(false);
}

// Called when the game starts or when spawned
void AMyFlashLight::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMyFlashLight::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

