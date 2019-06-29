// Copyright András Horváth

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "TankAIController.generated.h"

class UTankAimingComponent;

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankAIController : public AAIController
{
	GENERATED_BODY()

public:
	virtual void Tick(float DeltaTime) override;

private:
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere)
	float AcceptanceRadius = 3000;
	
};
