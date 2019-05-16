// Fill out your copyright notice in the Description page of Project Settings.

#include "Tank.h"
#include "Tank_PlayerController.h"

void ATank_PlayerController::BeginPlay() {
	Super::BeginPlay();

	UE_LOG(LogTemp, Warning, TEXT("PlayerController Begin Play"));
	ATank * tank = GetControlledTank();
	if (tank) {
		FString name= tank->GetName();
		UE_LOG(LogTemp, Warning, TEXT("The name of the tank pawn being controlled by the player is %s"),*name);
	}
}

void ATank_PlayerController::Tick(float deltaTime) {
	Super::Tick(deltaTime);
	AimTowardCrosshair();
}

ATank * ATank_PlayerController::GetControlledTank() const {
	return Cast<ATank>(GetPawn());

}

void ATank_PlayerController::AimTowardCrosshair() {
	if (!GetControlledTank()) { return; }

	FVector HitLocation;
	if (GetSightRayHitLocation(HitLocation)) {

		GetControlledTank()->AimAt(HitLocation);
	}
	
}

bool ATank_PlayerController::GetSightRayHitLocation(FVector & outHitLocation)const {

	int32 ViewportSizeX, ViewportSizeY;	
	GetViewportSize(ViewportSizeX, ViewportSizeY); //these are out parameteres

	FVector2D ScreenLocation = FVector2D(ViewportSizeX *CrossHairXLocation, ViewportSizeY * CrossHairYLocation);

	FVector LookDirection;

	if (GetLookDirection(ScreenLocation, LookDirection)) {
		GetLookVectorHitLocation(LookDirection, outHitLocation);

		return true;
	}

	return false;
}

bool ATank_PlayerController::GetLookVectorHitLocation(FVector LookDirection, FVector & HitLocation)const {

	FHitResult HitResult;

	auto StartLocation = PlayerCameraManager->GetCameraLocation();
	auto EndLocation = StartLocation +LookDirection* LineTraceRange;

	if (GetWorld()->LineTraceSingleByChannel(
		HitResult,
		StartLocation,
		EndLocation,
		ECollisionChannel::ECC_Visibility)
	) {
		HitLocation  = HitResult.Location;
		return true;
	}

	HitLocation = FVector(0);
	return false;
}

bool ATank_PlayerController::GetLookDirection(FVector2D ScreenLocation, FVector &LookDirection)const {

	FVector CameraWorldLocation; //To be discraded
	return DeprojectScreenPositionToWorld(ScreenLocation.X,
								    ScreenLocation.Y, 
									CameraWorldLocation,
									LookDirection);
	
}

