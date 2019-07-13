// Copyright Andr�s Horv�th

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Components/StaticMeshComponent.h"
#include "TankAimingComponent.generated.h"

// Enum for aiming state
UENUM()
enum class EFiringState : uint8
{
	RELOADING,
	AIMING,
	LOCKED,
	OUTOFAMMO
};


// Forward declaration
class UTankBarrel;
class UTankTurret;
class AProjectile;

// Holds barrel's properties and Elevate method
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BATTLETANK_API UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, category = "Setup")
	void Initialise(UTankBarrel* BarrelToSet, UTankTurret* TurretToSet);

	UPROPERTY(BlueprintReadOnly, category = "State")
	EFiringState FiringState = EFiringState::RELOADING;

	EFiringState GetFiringState() const;

	UFUNCTION(BlueprintCallable, Category = "Firing")
	int GetRoundsLeft() const;

	UPROPERTY(EditDefaultsOnly, Category = "Firing")
	float LaunchSpeed = 13000; // 130m/s

	void AimAt(FVector HitLocation);

	UPROPERTY(EditAnywhere, Category = "Setup")
	TSubclassOf<AProjectile> ProjectileBlueprint;

	UPROPERTY(EditDefaultsOnly, Category = "Firing")
	float ReloadTimeInSeconds = 3;

	UFUNCTION(BlueprintCallable, Category = "Firing")
	void Fire();

	bool IsBarrelMoving();

	double LastFireTime = 0;

private:
	// Sets default values for this component's properties
	UTankAimingComponent();

	FVector AimDirection = FVector(0.0, 0.0, 0.0);

	virtual void BeginPlay() override;

	virtual void TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UTankBarrel* Barrel = nullptr;
	UTankTurret* Turret = nullptr;

	int RoundsLeft = 5;

	void MoveBarrelTowards(FVector AimDirection);
};