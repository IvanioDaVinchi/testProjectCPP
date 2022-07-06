// Fill out your copyright notice in the Description page of Project Settings.


#include "MyTriggerBox.h"
#include "Components/BoxComponent.h"
#include "MySpotLight.h"

// Sets default values
AMyTriggerBox::AMyTriggerBox()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	MyTriggerComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("TriggerBox Component"));
	MyTriggerComponent->SetupAttachment(RootComponent);

	MyTriggerComponent->OnComponentBeginOverlap.AddDynamic(this, &AMyTriggerBox::Triggered);
	MyTriggerComponent->OnComponentEndOverlap.AddDynamic(this, &AMyTriggerBox::UnTriggered);
}

// Called when the game starts or when spawned
void AMyTriggerBox::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMyTriggerBox::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AMyTriggerBox::Triggered(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor && (OtherActor != this) && OtherComp)
	{
		for (AMySpotLight* SpotLight : ArrayOfSpotLights)
		{
			SpotLight->SetSpotLightEnabled();
		}
	}
}

void AMyTriggerBox::UnTriggered(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	if (OtherActor && (OtherActor != this) && OtherComp)
	{
		for (AMySpotLight* SpotLight : ArrayOfSpotLights)
		{
			SpotLight->SetSpotLightDisabled();
		}
	}
}

