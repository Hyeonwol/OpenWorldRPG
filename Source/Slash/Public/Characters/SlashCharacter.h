// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "BaseCharacter.h"
#include "InputActionValue.h"
#include "Characters/CharacterTypes.h"
#include "SlashCharacter.generated.h"

class UInputMappingContext;
class UInputAction;
class UCameraComponent;
class USpringArmComponent;
class UGroomComponent;
class AItem;

UCLASS()
class SLASH_API ASlashCharacter : public ABaseCharacter
{
	GENERATED_BODY()

public:
	ASlashCharacter();

	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	

protected:
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input)
	//UInputMappingContext* SlashContext;
	TObjectPtr<UInputMappingContext> SlashContext;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input)
	//UInputAction* MovementAction;
	TObjectPtr<UInputAction> MovementAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input)
	//UInputAction* LookingAction;
	TObjectPtr<UInputAction> LookingAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input)
	//UInputAction* JumpingAction;
	TObjectPtr<UInputAction> JumpingAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input)
	//UInputAction* EquipAction;
	TObjectPtr<UInputAction> EquipAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input)
	//UInputAction* AttackAction;
	TObjectPtr<UInputAction> AttackAction;

	//Callbacks for input
	void Move(const FInputActionValue& Value);
	void Look(const FInputActionValue& Value);
	void EKeyPressed(const FInputActionValue& Value);
	virtual void Attack(const FInputActionValue& Value) override;

	//Play Montage Functions
	virtual void PlayAttackMontage() const override;
	void PlayEquipMontage(const FName& SectionName) const;

	//UFUNCTION(BlueprintCallable)
	virtual void AttackEnd() override;
	virtual bool CanAttack() const override;

	bool CanDisarm() const;
	bool CanArm() const;

	UFUNCTION(BlueprintCallable)
	void Disarm();

	UFUNCTION(BlueprintCallable)
	void Arm();

	UFUNCTION(BlueprintCallable)
	void FinishEquipping();
private:
	ECharacterState CharacterState = ECharacterState::ECS_Unequipped;

	UPROPERTY(BlueprintReadWrite, meta=(AllowPrivateAccess="true"))
	EActionState ActionState = EActionState::EAS_Unoccupied;
	
	UPROPERTY(VisibleAnywhere)
	//UCameraComponent* ViewCamera;
	TObjectPtr<UCameraComponent> ViewCamera;

	UPROPERTY(VisibleAnywhere)
	//USpringArmComponent* SpringArm;
	TObjectPtr<USpringArmComponent> SpringArm;

	UPROPERTY(VisibleAnywhere, Category = Hair)
	//UGroomComponent* Hair;
	TObjectPtr<UGroomComponent> Hair;

	UPROPERTY(VisibleAnywhere, Category = Hair)
	//UGroomComponent* Eyebrows;
	TObjectPtr<UGroomComponent> Eyebrows;

	UPROPERTY(VisibleInstanceOnly)
	//AItem* OverlappingItem;
	TObjectPtr<AItem> OverlappingItem;

	
	
	//Animation Montages

	UPROPERTY(EditDefaultsOnly, Category = Montages)
	//UAnimMontage* EquipMontage;
	TObjectPtr<UAnimMontage> EquipMontage;

public:
	FORCEINLINE void SetOverlappingItem(AItem* Item) { OverlappingItem = Item; }
	FORCEINLINE ECharacterState GetCharacterState() const { return CharacterState; }
};
