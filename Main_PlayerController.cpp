// Fill out your copyright notice in the Description page of Project Settings.


#include "Main_PlayerController.h"
#include "Blueprint/AIBlueprintHelperLibrary.h"

AMain_PlayerController::AMain_PlayerController()
{
	bShowMouseCursor = true;
}

// Key 바인딩
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

		//이 함수에서는 우선 컨트롤러가 소유하고 있는 폰을 
		//가져와서 폰과 목적지 사이의 거리를 측정해서, 
		//그 거리가 120 언리얼 유닛보다 크면 폰을 목적지로 이동시킨다. 
		//UAIBlueprintHelperLibrary클래스의 SimpleMoveToLocation() 함수는 프로그래머가 
		//목적지로 폰을 이동시키기 위한 처리를 하는 모든 코드를 일일이 작성하는 대신에 
		//간단한 함수 호출로 그 모든 일을 할 수 있도록 도와준다.

		if (Distance > 60.0f) //120.f
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