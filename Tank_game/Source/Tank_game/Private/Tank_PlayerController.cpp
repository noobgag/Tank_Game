// Fill out your copyright notice in the Description page of Project Settings.

#include "Tank_PlayerController.h"

void ATank_PlayerController::BeginPlay() {
	Super::BeginPlay();

	UE_LOG(LogTemp, Warning, TEXT("PlayerController Begin Play"));
	ATank * tank = GetControlledTank();
	if (tank) {
		FString name= tank->GetName();
		UE_LOG(LogTemp, Warning, TEXT("The name of the tank pawn being controlled is %s"),*name);
	}
}
ATank * ATank_PlayerController::GetControlledTank() const {
	return Cast<ATank>(GetPawn());

}


