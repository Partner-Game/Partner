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

	// ���콺 Ŭ�� ���� 
	bool bClickMouse;

	void InputClickPressed();
	void InputClickReleased();

	virtual void SetupInputComponent() override;

	// ���ο� ��ǥ�� �Է¹޾� ĳ���͸� �ش���ġ�� �̵���Ű�� ��Ȱ
	void SetNewDestination(const FVector DestLocation);

	void MoveToMouseCursor();

	virtual void PlayerTick(float DeltaTime) override;
};
