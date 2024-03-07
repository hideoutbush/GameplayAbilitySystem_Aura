

#pragma once

#include "CoreMinimal.h"
#include "Character/AuraCharacter.h"
#include "Interaction/EnemyInterface.h"
#include "AuraEnemy.generated.h"

/**
 * 
 */
UCLASS()
class AURA_API AAuraEnemy : public AAuraCharacter,public  IEnemyInterface
{
	GENERATED_BODY()
public:
	AAuraEnemy();

	/*EnemyInterface 敌人界面*/
	
	virtual  void HighlightActor() override;
	virtual  void UnHighlightActor() override;
	
	/*End EnemyInterface 敌人界面结束*/
protected:
	virtual void BeginPlay() override; 
};
