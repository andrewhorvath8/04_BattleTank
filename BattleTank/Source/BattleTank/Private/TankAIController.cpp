// Fill out your copyright notice in the Description page of Project Settings.


#include "TankAIController.h"
#include "Tank.h"
#include "GameFramework/Actor.h"
#include "Engine/World.h"


void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	auto PlayerTank = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
	if (PlayerTank)
	{
		// TODO move towards player tank

		// Aim towards player tank
		auto ControlledTank = Cast<ATank>(GetPawn());
		if (ControlledTank)
		{
			ControlledTank->AimAt(PlayerTank->GetActorLocation());
			// Fire if ready
			ControlledTank->Fire();
		}
	}
}