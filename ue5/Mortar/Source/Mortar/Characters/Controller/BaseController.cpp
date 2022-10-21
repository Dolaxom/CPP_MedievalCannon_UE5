#include "BaseController.h"

#include "Mortar/Characters/BaseCharacter.h"

void ABaseController::SetPawn(APawn* InPawn)
{
	Super::SetPawn(InPawn);

	CachedBaseCharacter = Cast<ABaseCharacter>(InPawn);
}

void ABaseController::SetupInputComponent()
{
	Super::SetupInputComponent();

	InputComponent->BindAxis("MoveForward", this, &ABaseController::MoveForward);
	InputComponent->BindAxis("MoveRight", this, &ABaseController::MoveRight);
	InputComponent->BindAxis("Turn", this, &ABaseController::Turn);
	InputComponent->BindAxis("LookUp", this, &ABaseController::LookUp);

	InputComponent->BindAction("Jump", EInputEvent::IE_Pressed, this, &ABaseController::Jump);
	InputComponent->BindAction("Fire", EInputEvent::IE_Pressed, this, &ABaseController::MakeCannonShoot);
	InputComponent->BindAction("CannonForward", EInputEvent::IE_Pressed, this, &ABaseController::CannonRotateForward);
	InputComponent->BindAction("CannonBack", EInputEvent::IE_Pressed, this, &ABaseController::CannonRotateBack);
}

void ABaseController::MoveForward(float Value)
{
	if(CachedBaseCharacter.IsValid())
	{
		CachedBaseCharacter->MoveForward(Value);
	}
}

void ABaseController::MoveRight(float Value)
{
	if(CachedBaseCharacter.IsValid())
	{
		CachedBaseCharacter->MoveRight(Value);
	}
}

void ABaseController::Turn(float Value)
{
	if(CachedBaseCharacter.IsValid())
	{
		CachedBaseCharacter->Turn(Value);
	}
}

void ABaseController::LookUp(float Value)
{
	if(CachedBaseCharacter.IsValid())
	{
		CachedBaseCharacter->LookUp(Value);
	}
}

void ABaseController::Jump()
{
	if(CachedBaseCharacter.IsValid())
	{
		CachedBaseCharacter->Jump();
	}
}

void ABaseController::MakeCannonShoot()
{
	if(CachedBaseCharacter.IsValid())
	{
		CachedBaseCharacter->MakeCannonShoot();
	}
}

void ABaseController::CannonRotateForward()
{
	if(CachedBaseCharacter.IsValid())
	{
		CachedBaseCharacter->CannonRotateForward();
	}
}

void ABaseController::CannonRotateBack()
{
	if(CachedBaseCharacter.IsValid())
	{
		CachedBaseCharacter->CannonRotateBack();
	}
}
