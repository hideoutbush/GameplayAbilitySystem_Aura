


#include "Character/AuraEnemy.h"

#include "AbilitySystem/AuraAttributeSet.h"
#include "Aura/Aura.h"

AAuraEnemy::AAuraEnemy()
{
	//使继承自AuraEnemy类设置下的网格体碰撞预设自动更改为自定义,并将可视性Visibility改为阻挡Block
	GetMesh()->SetCollisionResponseToChannel(ECC_Visibility,ECR_Block);
	//这些指针对于玩家状态具有有效值，但对于角色则无效
	AbilitySystemComponent = CreateDefaultSubobject<UAuraAbilitySystemComponent>("AbilitySystemComponent");
	AbilitySystemComponent->SetIsReplicated(true);
	
	AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Minimal);

	AttributeSet = CreateDefaultSubobject<UAuraAttributeSet>("AttributeSet");
}

void AAuraEnemy::HighlightActor()
{
	/*
	 * 对网格体及武器添加外轮廓线
	 */
	GetMesh()->SetRenderCustomDepth(true);
	GetMesh()->SetCustomDepthStencilValue(CUSTOM_DEPTH_RED);
	Weapon->SetRenderCustomDepth(true);
	Weapon->SetCustomDepthStencilValue(CUSTOM_DEPTH_RED);
}

void AAuraEnemy::UnHighlightActor()
{
	GetMesh()->SetRenderCustomDepth(false);
	Weapon->SetRenderCustomDepth(false);
}

void AAuraEnemy::BeginPlay()
{
	Super::BeginPlay();

	 check(AbilitySystemComponent);//U++中指针为空即可能发生崩溃，因此谨慎使用。
	AbilitySystemComponent->InitAbilityActorInfo(this,this);
}
