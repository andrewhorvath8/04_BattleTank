// Copyright András Horváth


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
	if (ensure(PlayerTank))
	{
		// move towards player tank
		MoveToActor(PlayerTank, AcceptanceRadius); // TODO check radius is in cm

		// Aim towards player tank
		auto ControlledTank = Cast<ATank>(GetPawn());
		if (ensure(ControlledTank))
		{
			ControlledTank->AimAt(PlayerTank->GetActorLocation());
			// Fire if ready
			ControlledTank->Fire();
		}
	}
}