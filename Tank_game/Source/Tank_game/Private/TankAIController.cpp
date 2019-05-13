// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"

void ATankAIController::BeginPlay() {
	Super::BeginPlay();

	auto ControlledTank = GetControlledTank();
	if (ControlledTank) {
		UE_LOG(LogTemp, Warning, TEXT("The tank being controlled by the AI controller is %s"), *(ControlledTank->GetName()));
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("The AI controller is not possessing a tank "));
	}

}

ATank* ATankAIController::GetControlledTank() const{
	return  Cast<ATank>(GetPawn());
}
