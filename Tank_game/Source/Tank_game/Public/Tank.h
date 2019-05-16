// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Tank.generated.h"	//always put new includes above generated.h

//Forward declarations
class UTankBarrel;
class UTankAimingComponent;

UCLASS()
class TANK_GAME_API ATank : public APawn
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintCallable,Category = Setup)
	void SetBarrelReference(UTankBarrel * Barrel_);

	void AimAt(FVector HitLocation);


protected:

	UTankAimingComponent * TankAimingComponet = nullptr;

private:	

	// Sets default values for this pawn's properties
	ATank();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(EditAnywhere, Category = Firing)
	float LaunchSpeed = 100000; //TODO find Sensible startinag value
	
};
