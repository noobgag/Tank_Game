// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"

void ATankAIController::BeginPlay() {
	Super::BeginPlay();

	auto ControlledTank = GetControlledTank();
	auto PlayerTank = GetPlayerTank();

	if (ControlledTank) {
		UE_LOG(LogTemp, Warning, TEXT("The tank being controlled by the AI controller is %s"), *(ControlledTank->GetName()));
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("The AI controller is not possessing a tank "));
	}

	if (PlayerTank) {
		UE_LOG(LogTemp, Warning, TEXT("The tank being controlled by the AI controller is %s"), *(PlayerTank->GetName()));
	}

	else {
		UE_LOG(LogTemp, Warning, TEXT("The AI controller cant find the player tank  "));
	}
	

}

ATank* ATankAIController::GetControlledTank() const{
	return  Cast<ATank>(GetPawn());
}

ATank * ATankAIController::GetPlayerTank() const
{
	auto  playerTank = GetWorld()->GetFirstPlayerController();
	if (playerTank) {
		return Cast<ATank>(playerTank);
	}

	else {
		return nullptr;
	}
	
}
