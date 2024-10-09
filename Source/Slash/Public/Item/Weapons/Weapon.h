// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Item/Item.h"
#include "Weapon.generated.h"

class USoundBase;
class UBoxComponent;
class USceneComponent;

/**
 * 
 */
UCLASS()
class SLASH_API AWeapon : public AItem
{
	GENERATED_BODY()

public:
	AWeapon();
	void AttachMeshToSocket(USceneComponent* InParent, const FName& InSocketName) const;
	void Equip(USceneComponent* InParent, FName InSocketName);
	
	TArray<TObjectPtr<AActor>> IgnoreActors;
protected:
	virtual void BeginPlay() override;
	virtual void OnSphereOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult) override;
	virtual void OnSphereEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex) override;

	UFUNCTION()
	void OnBoxOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult);

	UFUNCTION(BlueprintImplementableEvent)
	void CreateFields(const FVector& FieldLocation);
private:

	UPROPERTY(EditAnywhere, Category = "Weapon Properties")
 	//USoundBase* EquipSound;
	TObjectPtr<USoundBase> EquipSound;

	UPROPERTY(VisibleAnywhere, Category = "Weapon Properties")
	//UBoxComponent* WeaponBox;
	TObjectPtr<UBoxComponent> WeaponBox;

	UPROPERTY(VisibleAnywhere)
	//USceneComponent* BoxTraceStart;
	TObjectPtr<USceneComponent> BoxTraceStart;
	
	UPROPERTY(VisibleAnywhere)
	//USceneComponent* BoxTraceEnd;
	TObjectPtr<USceneComponent> BoxTraceEnd;

	

public:
	FORCEINLINE UBoxComponent* GetWeaponBox() const {return WeaponBox; }
};