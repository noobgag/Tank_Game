// Fill out your copyright notice in the Description page of Project Settings.

#include "Tank_PlayerController.h"

ATank * ATank_PlayerController::GetControlledTank() const {
	return Cast<ATank>(GetPawn());

}


