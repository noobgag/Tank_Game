// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAimingComponent.h"
#include "TankBarrel.h"
#include "TankTurret.h"



// Sets default values for this component's properties
UTankAimingComponent::UTankAimingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	// ...
}

void UTankAimingComponent::SetBarrelReference(UTankBarrel * Barrel_) {
	if (!Barrel_) { return; }
	Barrel = Barrel_;
}

void UTankAimingComponent::SetTurretReference(UTankTurret * Turret_) {
	if (!Turret_) { return; }
	Turret = Turret_;
}

void UTankAimingComponent::AimAt(FVector HitLocation, float LaunchSpeed) {

	if (!Barrel ||!Turret) { return; }
	auto TankName = GetOwner()->GetName();
	FVector outLaunchVelocity;
	FVector StartLocation = Barrel->GetSocketLocation(FName("Projectile"));
	
	bool bHaveAimSolution = (UGameplayStatics::SuggestProjectileVelocity(					//if the function call succeed then printout the following location
		this,
		outLaunchVelocity,
		StartLocation,
		HitLocation,
		LaunchSpeed,
		false,
		0,
		0,
		ESuggestProjVelocityTraceOption::DoNotTrace)
		);

	if (bHaveAimSolution) {
		auto AimDirection = outLaunchVelocity.GetSafeNormal();

		MoveBarrelTowards(AimDirection);


		auto Time = GetWorld()->GetTimeSeconds();
		
	}

	else {
		//UE_LOG(LogTemp, Warning, TEXT("No aim solution found"));
	}

}

void UTankAimingComponent::MoveBarrelTowards(FVector AimDirection) {

	auto BarrelRotator = Barrel->GetForwardVector().Rotation();
	auto AimAsRotator = AimDirection.Rotation();
	auto DeltaRotator = AimAsRotator - BarrelRotator;


	Barrel->Elevate(DeltaRotator.Pitch); //TODO stop hardcoding the number
	Turret->Rotate(DeltaRotator.Yaw);
}

