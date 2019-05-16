// Fill out your copyright notice in the Description page of Project Settings.

#include "Tank.h"
#include "TankAimingComponent.h"



// Sets default values
ATank::ATank()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	//no need to protect 
	TankAimingComponet = CreateDefaultSubobject<UTankAimingComponent>(FName("Aiming Component"));

}

// Called when the game starts or when spawned
void ATank::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame


// Called to bind functionality to input
void ATank::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void ATank::SetBarrelReference(UTankBarrel * Barrel_) {
	TankAimingComponet->SetBarrelReference(Barrel_);

}

void ATank::SetTurretReference(UTankTurret * Turret_) {
	TankAimingComponet->SetTurretReference(Turret_);

}

void ATank::AimAt(FVector HitLocation) {

	TankAimingComponet->AimAt(HitLocation , LaunchSpeed);
	
}

void ATank::Fire() {
	UE_LOG(LogTemp, Warning, TEXT("Fire in the hole "));
}
