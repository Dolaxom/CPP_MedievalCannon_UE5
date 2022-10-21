#include "BaseCharacterAnimInstance.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Mortar/Characters/BaseCharacter.h"

void UBaseCharacterAnimInstance::NativeBeginPlay()
{
	Super::NativeBeginPlay();
	checkf(TryGetPawnOwner()->IsA<ABaseCharacter>(), TEXT("Error from UBaseCharacterAnimInstance.c, line 8"));
	CachedBaseCharacter = StaticCast<ABaseCharacter*>(TryGetPawnOwner());
}

void UBaseCharacterAnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);
	
	if(!CachedBaseCharacter.IsValid())
	{
		return;
	}

	const UCharacterMovementComponent* CharacterMovement = CachedBaseCharacter->GetCharacterMovement();

	Speed = CharacterMovement->Velocity.Size();
	bIsFalling = CharacterMovement->IsFalling();
}
