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

	// 캐릭터가 카메라를 따라 회전하지않도록함 (마우스로 움직이기때문에)
	bUseControllerRotationPitch = false;
	bUseControllerRotationRoll = false;
	bUseControllerRotationYaw = false;

	/*이 코드는 캐릭터의 무브먼트를 규정하는 코드로, 캐릭터를 이동시키기 전에 이동 방향과 
	현재 캐릭터의 방향이 다르면 캐릭터를 이동 방향으로 초당 640도의 회전 속도로 회전시킨다음 이동시킨다. 
	그리고 캐릭터의 이동을 평면으로 제한하고, 시작할 때 캐릭터의 위치가 평면을 벗어난 상태라면 
	가까운 평면으로 붙여서 시작되도록 한다. 여기서 평면이란 내비게이션 메시를 의미한다.
	*/
	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 200.0f, 0.0f);
	GetCharacterMovement()->bConstrainToPlane = true;
	GetCharacterMovement()->bSnapToPlaneAtStart = true;

	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CarmeraBoom"));
	CameraBoom->SetupAttachment(GetRootComponent());
	CameraBoom->SetUsingAbsoluteRotation(true);
	CameraBoom->TargetArmLength = 800.0f;
	CameraBoom->SetRelativeRotation(FRotator(0.0f, 0.0f, 0.0f)); // -130.f / 45.0f 0.0f
	CameraBoom->bDoCollisionTest = false;
	CameraBoom->bEnableCameraLag = true;
	CameraBoom->bUsePawnControlRotation = true;
	CameraBoom->bInheritPitch = false;
	CameraBoom->bInheritRoll = false;
	//CameraBoom->bInheritYaw = false;

	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	FollowCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName);
	FollowCamera->bUsePawnControlRotation = false;


	PrimaryActorTick.bCanEverTick = true;
	PrimaryActorTick.bStartWithTickEnabled = true;


	GetCharacterMovement()->JumpZVelocity = 300.f;
	GetCharacterMovement()->AirControl = 0.2;


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

	PlayerInputComponent->BindAction("JUMP", IE_Pressed, this, &ACharacter::Jump);
	PlayerInputComponent->BindAction("JUMP", IE_Released, this, &ACharacter::StopJumping);

}

