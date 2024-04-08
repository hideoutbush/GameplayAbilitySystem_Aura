


#include "Character/AuraCharacter.h"

#include "GameFramework/CharacterMovementComponent.h"
#include "Player/AuraPlayerController.h"
#include "Player/AuraPlayerState.h"
#include "UI/HUD/AuraHUD.h"

AAuraCharacter::AAuraCharacter()
{
	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->RotationRate = FRotator(0.f,400.f,0.f);
	GetCharacterMovement()->bConstrainToPlane = true;
	GetCharacterMovement()->bSnapToPlaneAtStart = true;

	bUseControllerRotationPitch = false;
	bUseControllerRotationRoll = false;
	bUseControllerRotationYaw = false;
}

void AAuraCharacter::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);
	//Init ability actor for the server(在服务器上实例化带有技能的actor)
	InitAbilityActorInfo();
}

void AAuraCharacter::OnRep_PlayerState()
{
	Super::OnRep_PlayerState();
	//Init ability actor for the Client(在客户端上实例化带有技能的actor)
	InitAbilityActorInfo();
	
}

void AAuraCharacter::InitAbilityActorInfo()
{
	//导致GetPlayerState传入Goblin类Character:AuraEnemy类误继承了Character,应该直接继承CharacterBase避免调用混乱。
	//获取为NULL的原因:1.Discord中的解释为需要在运行模式下GameMode中创建AuraPawn类通过APawn父类中的泛型调用Playerstate返回值
	AAuraPlayerState* AuraPlayerState =  GetPlayerState<AAuraPlayerState>();
	check(AuraPlayerState);
	AuraPlayerState->GetAbilitySystemComponent()->InitAbilityActorInfo(AuraPlayerState,this);
	AbilitySystemComponent = AuraPlayerState->GetAbilitySystemComponent(); 
	AttributeSet = AuraPlayerState->GetAttributeSet();

	if(AAuraPlayerController* AuraPlayerController= Cast<AAuraPlayerController>(GetController()))
	{
		if (AAuraHUD* AuraHUD =Cast<AAuraHUD> (AuraPlayerController->GetHUD()))
		{
			AuraHUD->InitOverlay(AuraPlayerController,AuraPlayerState,AbilitySystemComponent,AttributeSet);
		}
		
	}
}
