// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AttributeComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class SLASH_API UAttributeComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	UAttributeComponent();
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

protected:
	virtual void BeginPlay() override;

private:
	//현재 HP
	UPROPERTY(EditAnywhere, Category="ActorAttributes")
	float Health = 100.f;

	//최대 HP
	UPROPERTY(EditAnywhere, Category="ActorAttributes")
	float MaxHealth = 100.f;

public:
	void ReceiveDamage(float Damage);
	float GetHealthPercent() const;

	bool IsAlive() const;
};
