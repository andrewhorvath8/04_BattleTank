// Fill out your copyright notice in the Description page of Project Settings.


#include "TankTrack.h"

void UTankTrack::SetThrottle(float Throttle)
{
	UE_LOG(LogTemp, Warning, TEXT("Intend move forward throttle: %f"), Throttle);
	auto ForceApplied = GetForwardVector() * Throttle * TrackMaxDriveForce;
	auto ForceLocation = GetComponentLocation();
	auto TankRoot = Cast<UPrimitiveComponent>(GetOwner()->GetRootComponent());
	TankRoot->AddForceAtLocation(ForceApplied,ForceLocation);
}