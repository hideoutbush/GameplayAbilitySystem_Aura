

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemInterface.h"
#include "AttributeSet.h"
#include "AbilitySystem/AuraAbilitySystemComponent.h"
#include "GameFramework/PlayerState.h"
#include "AuraPlayerState.generated.h"


class  UAbilitySystemComponent;
class  UAttributeSet;
/**
 * 
 */
UCLASS() 
class AURA_API AAuraPlayerState : public APlayerState,public  IAbilitySystemInterface
{
	GENERATED_BODY()
public:
	AAuraPlayerState();
	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;//获取asc
	UAttributeSet* GetAttributeSet() const {return  AttributeSet;}//获取as
protected:
	UPROPERTY(EditAnywhere,Category = "")
	TObjectPtr<UAbilitySystemComponent> AbilitySystemComponent;

	UPROPERTY(EditAnywhere,Category="")
	TObjectPtr<UAttributeSet>AttributeSet;
	
};
