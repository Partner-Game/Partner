// Fill out your copyright notice in the Description page of Project Settings.


#include "Main_PlayerController.h"
#include "Blueprint/AIBlueprintHelperLibrary.h"

AMain_PlayerController::AMain_PlayerController()
{
	bShowMouseCursor = true;
}

// Key ���ε�
void AMain_PlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	InputComponent->BindAction("MouseMove", IE_Pressed, this, &AMain_PlayerController::InputClickPressed);
	InputComponent->BindAction("MouseMove", IE_Released, this, &AMain_PlayerController::InputClickReleased);
}

void AMain_PlayerController::InputClickPressed()
{
	bClickMouse = true;
}

void AMain_PlayerController::InputClickReleased()
{
	bClickMouse = false;
}


void AMain_PlayerController::SetNewDestination(const FVector DestLocation)
{
	APawn* const MyPawn = GetPawn();
	if (MyPawn)
	{
		float const Distance = FVector::Dist(DestLocation, MyPawn->GetActorLocation());

		//�� �Լ������� �켱 ��Ʈ�ѷ��� �����ϰ� �ִ� ���� 
		//�����ͼ� ���� ������ ������ �Ÿ��� �����ؼ�, 
		//�� �Ÿ��� 120 �𸮾� ���ֺ��� ũ�� ���� �������� �̵���Ų��. 
		//UAIBlueprintHelperLibraryŬ������ SimpleMoveToLocation() �Լ��� ���α׷��Ӱ� 
		//�������� ���� �̵���Ű�� ���� ó���� �ϴ� ��� �ڵ带 ������ �ۼ��ϴ� ��ſ� 
		//������ �Լ� ȣ��� �� ��� ���� �� �� �ֵ��� �����ش�.

		if (Distance > 120.0f)
		{
			UAIBlueprintHelperLibrary::SimpleMoveToLocation(this, DestLocation);
		}
	}
}

void AMain_PlayerController::MoveToMouseCursor()
{
	FHitResult Hit;

	GetHitResultUnderCursor(ECC_Visibility, false, Hit);
	if (Hit.bBlockingHit)
	{
		SetNewDestination(Hit.ImpactPoint);
	}
}

void AMain_PlayerController::PlayerTick(float DeltaTime)
{
	Super::PlayerTick(DeltaTime);

	if (bClickMouse)
	{
		MoveToMouseCursor();
	}
}