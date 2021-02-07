// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "Main_PlayerController.generated.h"

/**
 * 
 */
UCLASS()
class TIMERPROJECT_API AMain_PlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
	AMain_PlayerController();


protected:

	// 마우스 클릭 여부 
	bool bClickMouse;

	void InputClickPressed();
	void InputClickReleased();

	virtual void SetupInputComponent() override;

	// 새로운 목표로 입력받아 캐릭터를 해당위치로 이동시키는 역활
	void SetNewDestination(const FVector DestLocation);

	void MoveToMouseCursor();

	virtual void PlayerTick(float DeltaTime) override;
};
