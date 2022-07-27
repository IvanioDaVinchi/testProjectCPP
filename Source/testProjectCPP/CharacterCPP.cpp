// Fill out your copyright notice in the Description page of Project Settings.


#include "CharacterCPP.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/InputComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/Controller.h"
#include "GameFramework/SpringArmComponent.h"

// Sets default values
ACharacterCPP::ACharacterCPP()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->bUsePawnControlRotation = true;

	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	FollowCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName);
	FollowCamera->bUsePawnControlRotation = false;

	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->JumpZVelocity = 750.0f;
	GetCharacterMovement()->MaxWalkSpeed = 450.0f;

	bDead = false;

	TriggerCapsule = CreateDefaultSubobject<UCapsuleComponent>(TEXT("Trigger Capsule"));
	TriggerCapsule->SetupAttachment(RootComponent);
	TriggerCapsule->InitCapsuleSize(55.0f, 96.0f);
	TriggerCapsule->SetCollisionProfileName(TEXT("Trigger"));

	TriggerCapsule->OnComponentBeginOverlap.AddDynamic(this, &ACharacterCPP::OnOverlapBegin);
	TriggerCapsule->OnComponentEndOverlap.AddDynamic(this, &ACharacterCPP::OnOverlapEnd);

	Door = NULL;
}

void ACharacterCPP::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor && (OtherActor != this) && OtherComp && OtherActor->GetClass()->IsChildOf(AMyDoor::StaticClass()))
	{
		Door = Cast<AMyDoor>(OtherActor);
	}
}

void ACharacterCPP::OnOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	if (OtherActor && (OtherActor != this) && OtherComp)
	{
		Door = NULL;
	}
}

// Called when the game starts or when spawned
void ACharacterCPP::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACharacterCPP::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ACharacterCPP::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("Turn", this, &APawn::AddControllerYawInput);
	PlayerInputComponent->BindAxis("LookUp", this, &APawn::AddControllerPitchInput);
	PlayerInputComponent->BindAxis("MoveForward", this, &ACharacterCPP::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &ACharacterCPP::MoveRight);
	
	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ACharacterCPP::Jump);
	PlayerInputComponent->BindAction("Jump", IE_Released, this, &ACharacterCPP::StopJumping);

	PlayerInputComponent->BindAction("Use", IE_Pressed, this, &ACharacterCPP::OnUse);
}

void ACharacterCPP::MoveForward(float Axis)
{
	if (Controller != NULL && Axis != 0.0f && !bDead)
	{
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0,Rotation.Yaw,0);
		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
		AddMovementInput(Direction, Axis);
	}
}

void ACharacterCPP::MoveRight(float Axis)
{
	if (Controller != NULL && Axis != 0.0f && !bDead)
	{
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);
		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
		AddMovementInput(Direction, Axis);
	}
}

void ACharacterCPP::Jump()
{
	if (Controller != NULL && !bDead)
	{
		ACharacter::Jump();
	}
}

void ACharacterCPP::StopJumping()
{
	if (Controller != NULL && !bDead)
	{
		ACharacter::StopJumping();
	}
}

void ACharacterCPP::OnUse()
{
	if (Door)
	{
		FVector ForwardVector = FollowCamera->GetForwardVector();
		Door->ToggleDoor(ForwardVector);
	}
}