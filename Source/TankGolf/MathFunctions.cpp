// Fill out your copyright notice in the Description page of Project Settings.


#include "MathFunctions.h"

void UMathFunctions::PredictTargetPosition(AActor* Instigator, AActor* Target, float CannonPitch, float ProjectileVelocity, FVector& TargetPosition)
{
	FVector VectorToTarget = Target->GetActorLocation() - Instigator->GetActorLocation();
	FVector TargetVelocity = Target->GetVelocity();

	float TargetToLegIntersectionLength = VectorToTarget.Size() * FVector::DotProduct(TargetVelocity.GetSafeNormal(), VectorToTarget.GetSafeNormal());
	FVector LegIntersection = Target->GetActorLocation() + TargetVelocity.GetSafeNormal() * TargetToLegIntersectionLength * -1;

	float DistanceToLegIntersection = (LegIntersection - Instigator->GetActorLocation()).Size();
	float ProjectileSpeedHorizontal = ProjectileVelocity * FMath::Cos(FMath::DegreesToRadians(CannonPitch));
	float TargetSpeedHorizontal = Target->GetVelocity().Size() * 100.f;

	float X1;
	float X2;
	float A = ProjectileSpeedHorizontal * ProjectileSpeedHorizontal - TargetSpeedHorizontal * TargetSpeedHorizontal;
	float B = -2 * TargetToLegIntersectionLength * TargetSpeedHorizontal;
	float C = -1 * (TargetToLegIntersectionLength * TargetToLegIntersectionLength + DistanceToLegIntersection * DistanceToLegIntersection);

	ABCFormula(A, B, C, X1, X2);

	TargetPosition = Target->GetActorLocation() + TargetVelocity * X1;
}

void UMathFunctions::ABCFormula(float A, float B, float C, float& X1, float& X2)
{
	float firstPart = -B / (A * 2.0f);
	float secondPart = FMath::Sqrt(B*B - 4*A*C) / (A*2.0f);

	X1 = firstPart + secondPart;
	X2 = firstPart - secondPart;
}