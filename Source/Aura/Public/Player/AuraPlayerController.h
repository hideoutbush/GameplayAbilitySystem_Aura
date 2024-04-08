

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "AuraPlayerController.generated.h"


/// <summary>
/// 对下方智能指针的声明并且只有当我们有权访问该模块时,才能成功包含该头文件，模块需要在Aura.Build.cs中添加
/// </summary>
class UInputMappingContext;
class UInputAction;
struct FInputActionValue;
class IEnemyInterface;

/**
 * 
 */
UCLASS()
class AURA_API AAuraPlayerController : public APlayerController
{
	GENERATED_BODY()
public:
	AAuraPlayerController();
	virtual  void PlayerTick(float DeltaTime) override;
protected:
	virtual void BeginPlay() override;
	virtual void SetupInputComponent() override;

private:
	UPROPERTY(EditAnywhere, Category = "Input")
	TObjectPtr<UInputMappingContext> AuraContext; 

	UPROPERTY(EditAnywhere, Category = "Input")
	TObjectPtr<UInputAction> MoveAction;

	//Move方法需要以输入操作之的形式接受该数据
	void Move(const  FInputActionValue& InputActionValue);

	void CursorTrace();
	TObjectPtr<IEnemyInterface> LastActor;
	TObjectPtr<IEnemyInterface>  ThisActor;
};
 
