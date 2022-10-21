#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MortarCannon.generated.h"

UCLASS()
class MORTAR_API AMortarCannon : public AActor
{
	GENERATED_BODY()
	
public:	
	AMortarCannon();
	
	virtual void Tick(float DeltaTime) override;

	bool GetPlayerIsNearly() const { return PlayerIsNealy; };
	
	void Shoot() const;
	void RotateForward();
	void RotateBack();
	
protected:
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Mortar | Mesh")
	UStaticMeshComponent* CannonBody;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Mortar | Mesh")
	class UArrowComponent* ArrowComponent;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Mortar | Mesh")
	class UBoxComponent *CollisionBoxOverlap;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Mortar | Parameters")
	TSubclassOf<AActor> Cannonball;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Mortar | Parameters")
	TSubclassOf<AActor> ExplosionVFX;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Mortar | Parameters")
	float CannonballOffsetSpawn = 300.0f;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Mortar | Parameters")
	float PitchSpeedRotation = 0.5f;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Mortar | Parameters")
	USoundBase* SoundShoot;
	
private:
	UFUNCTION()
	virtual void OnOverlapBegin(class UPrimitiveComponent* newComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
	virtual void OnOverlapEnd(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

	UPROPERTY()
	class APlayerCharacter* Player;

	bool PlayerIsNealy = false;
};
