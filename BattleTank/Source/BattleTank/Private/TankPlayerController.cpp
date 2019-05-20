// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"
#include "BattleTank.h"

void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();

	auto ControlledTank = GetControlledTank();
	if (!ControlledTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("PlayerController not possessing a tank!"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Player Controlled tank is: %s"), *(ControlledTank->GetName()));
	}	
}

void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	AimTowardsCrosshair();
}

ATank* ATankPlayerController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

void ATankPlayerController::AimTowardsCrosshair()
{
	if (!GetControlledTank()) { return; }

	// OUT parameter
	FVector HitLocation;

	if (GetSightRayHitLocation(HitLocation)) // Has side-effect, is going to line trace
	{
		UE_LOG(LogTemp, Warning, TEXT("Look direction is: %s"), *(HitLocation.ToString()));
		// TODO Tell ctonrolled tank to aim at this point
	}	
}

// Get world location if linetrace through crosshair, true if hits landscape
bool ATankPlayerController::GetSightRayHitLocation(FVector &OutHitLocation) const
{
	// Find the crosshair position
	int32 ViewportSizeX, ViewportSizeY;
	GetViewportSize(ViewportSizeX, ViewportSizeY);

	FVector2D ScreenLocation = FVector2D(ViewportSizeX*CrossHairXLocation, ViewportSizeY*CrossHairYLocation);
	OutHitLocation = FVector(ScreenLocation.X, ScreenLocation.Y,0);


	// De-project the screen position of the crosshair to a world direction
	// Line-trace along that look direction, and see what we hit (up to max range)

	return true;
}
