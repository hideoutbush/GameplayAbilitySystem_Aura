


#include "Character/AuraEnemy.h"

#include "AbilitySystem/AuraAttributeSet.h"
#include "Aura/Aura.h"

AAuraEnemy::AAuraEnemy()
{
	//ʹ�̳���AuraEnemy�������µ���������ײԤ���Զ�����Ϊ�Զ���,����������Visibility��Ϊ�赲Block
	GetMesh()->SetCollisionResponseToChannel(ECC_Visibility,ECR_Block);
	//��Щָ��������״̬������Чֵ�������ڽ�ɫ����Ч
	AbilitySystemComponent = CreateDefaultSubobject<UAuraAbilitySystemComponent>("AbilitySystemComponent");
	AbilitySystemComponent->SetIsReplicated(true);
	
	AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Minimal);

	AttributeSet = CreateDefaultSubobject<UAuraAttributeSet>("AttributeSet");
}

void AAuraEnemy::HighlightActor()
{
	/*
	 * �������弰���������������
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

	 check(AbilitySystemComponent);//U++��ָ��Ϊ�ռ����ܷ�����������˽���ʹ�á�
	AbilitySystemComponent->InitAbilityActorInfo(this,this);
}
