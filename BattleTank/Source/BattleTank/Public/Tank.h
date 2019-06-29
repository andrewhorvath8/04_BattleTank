// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Tank.generated.h"

class UTankBarrel;
class UTankTurret;
class AProjectile;

UCLASS()
class BATTLETANK_API ATank : public APawn
{
	GENERATED_BODY()

private:
	// Sets default values for this pawn's properties
	ATank();

public:	
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable)
	void Fire();

	// TODO remove once firing moved to aimingcomponent
	UPROPERTY(EditDefaultsOnly, Category = "Firing")
	float LaunchSpeed = 13000; // 130m/s

	UPROPERTY(EditDefaultsOnly, Category = "Firing")
	float ReloadTimeInSeconds = 3;

	UPROPERTY(EditAnywhere, Category = "Setup")
	TSubclassOf<AProjectile> ProjectileBlueprint;

	// TODO remove
	UTankBarrel* Barrel = nullptr;

	double LastFireTime = 0;
};
