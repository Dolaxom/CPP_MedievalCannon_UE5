#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "BaseController.generated.h"

/**
 * 
 */
UCLASS()
class MORTAR_API ABaseController : public APlayerController
{
	GENERATED_BODY()
	
public:
	virtual void SetPawn(APawn* InPawn) override;

protected:
	virtual void SetupInputComponent() override;
	
private:
	void MoveForward(float Value);
	void MoveRight(float Value);
	void Turn(float Value);
	void LookUp(float Value);
	
	void Jump();
	void MakeCannonShoot();
	void CannonRotateForward();
	void CannonRotateBack();

	
	TSoftObjectPtr<class ABaseCharacter> CachedBaseCharacter;	
};
