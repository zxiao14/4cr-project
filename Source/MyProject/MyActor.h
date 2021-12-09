// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyActor.generated.h"

UCLASS()
class MYPROJECT_API AMyActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMyActor();
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Damage")
    int32 TotalDamage;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Damage")
    float DamageTimeInSeconds;

    UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Transient, Category = "Damage")
    float DamagePerSecond;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
    void PostInitProperties()
    {
        Super::PostInitProperties();
        CalculateValues();
    }
    UFUNCTION(BlueprintCallable, Category = "Damage")
    void CalculateValues()
    {
        DamagePerSecond = TotalDamage / DamageTimeInSeconds;
    }

    #if WITH_EDITOR
    void PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent)
    {
        CalculateValues();

        Super::PostEditChangeProperty(PropertyChangedEvent);
    }
    #endif
};
