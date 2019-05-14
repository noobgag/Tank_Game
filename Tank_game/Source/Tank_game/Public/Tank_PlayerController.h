// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Tank.h"
#include "Engine/World.h"
#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "Tank_PlayerController.generated.h"

/**
 * 
 */
UCLASS()
class TANK_GAME_API ATank_PlayerController : public APlayerController
{
	GENERATED_BODY()
	
private:
	 virtual void BeginPlay() override;
	 virtual void Tick(float DeltaTime) override;

	 ATank * GetControlledTank() const;
	 void AimTowardCrosshair();
	 bool GetSightRayHitLocation(FVector & outHitLocation) const;
	 bool GetLookDirection(FVector2D ScreenLocation, FVector &LookDirection)const;
	 bool GetLookVectorHitLocation(FVector LookDirection, FVector & HitLocation)const;

	 UPROPERTY(EditAnywhere)
	float CrossHairXLocation = 0.5;

	 UPROPERTY(EditAnywhere)
	float CrossHairYLocation = 0.33333;

	 UPROPERTY(EditAnywhere)
	 float LineTraceRange = 1000000.f; //unreal unit is in cm so it is now 10km
};
