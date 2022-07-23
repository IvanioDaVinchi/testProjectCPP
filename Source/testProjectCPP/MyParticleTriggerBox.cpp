// Fill out your copyright notice in the Description page of Project Settings.


#include "MyParticleTriggerBox.h"
#include "Components/BoxComponent.h"

// Sets default values
AMyParticleTriggerBox::AMyParticleTriggerBox()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	MyTriggerComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("Trigger Box Component"));
	MyTriggerComponent->SetupAttachment(RootComponent);

	MyTriggerComponent->OnComponentBeginOverlap.AddDynamic(this, &AMyParticleTriggerBox::Triggered);
	MyTriggerComponent->OnComponentEndOverlap.AddDynamic(this, &AMyParticleTriggerBox::UnTriggered);
}

// Called when the game starts or when spawned
void AMyParticleTriggerBox::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMyParticleTriggerBox::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AMyParticleTriggerBox::Triggered(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor && (OtherActor != this) && OtherComp)
	{
		for (AActor* PartSys : ArrayOfParticles)
		{
			PartSys->Destroy();
		}
	}
}

void AMyParticleTriggerBox::UnTriggered(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	if (OtherActor && (OtherActor != this) && OtherComp)
	{
		
	}
}

