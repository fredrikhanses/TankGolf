// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "MathFunctions.generated.h"

/**
 * 
 */
UCLASS()
class TANKGOLF_API UMathFunctions : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintCallable, Category="Math")
	static void PredictTargetPosition(AActor* Instigator, AActor* Target, float CannonPitch, float ProjectileVelocity, FVector& TargetPosition);

	UFUNCTION(BlueprintCallable, Category="Math")
	static void ABCFormula(float A, float B, float C, float& X1, float& X2);
};
