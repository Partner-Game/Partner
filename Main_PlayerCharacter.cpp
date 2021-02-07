// Fill out your copyright notice in the Description page of Project Settings.


#include "Main_PlayerCharacter.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Components/SceneComponent.h"

// Sets default values
AMain_PlayerCharacter::AMain_PlayerCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.f);

	// ĳ���Ͱ� ī�޶� ���� ȸ�������ʵ����� (���콺�� �����̱⶧����)
	bUseControllerRotationPitch = false;
	bUseControllerRotationRoll = false;
	bUseControllerRotationYaw = false;

	/*�� �ڵ�� ĳ������ �����Ʈ�� �����ϴ� �ڵ��, ĳ���͸� �̵���Ű�� ���� �̵� ����� 
	���� ĳ������ ������ �ٸ��� ĳ���͸� �̵� �������� �ʴ� 640���� ȸ�� �ӵ��� ȸ����Ų���� �̵���Ų��. 
	�׸��� ĳ������ �̵��� ������� �����ϰ�, ������ �� ĳ������ ��ġ�� ����� ��� ���¶�� 
	����� ������� �ٿ��� ���۵ǵ��� �Ѵ�. ���⼭ ����̶� ������̼� �޽ø� �ǹ��Ѵ�.
	*/
	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 15.f, 0.0f);
	GetCharacterMovement()->bConstrainToPlane = true;
	GetCharacterMovement()->bSnapToPlaneAtStart = true;

	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CarmeraBoom"));
	CameraBoom->SetupAttachment(GetRootComponent());
	CameraBoom->SetUsingAbsoluteRotation(true);
	CameraBoom->TargetArmLength = 800.0f;
	CameraBoom->SetRelativeRotation(FRotator(-130.f, 45.f, 0.0f));
	CameraBoom->bDoCollisionTest = false;
	CameraBoom->bEnableCameraLag = true;

	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	FollowCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName);
	FollowCamera->bUsePawnControlRotation = false;

	PrimaryActorTick.bCanEverTick = true;
	PrimaryActorTick.bStartWithTickEnabled = true;



}

// Called when the game starts or when spawned
void AMain_PlayerCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMain_PlayerCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AMain_PlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

