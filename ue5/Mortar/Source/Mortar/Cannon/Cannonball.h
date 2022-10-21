#pragma once

#include "CoreMinimal.h"
#include "Engine/StaticMeshActor.h"
#include "Cannonball.generated.h"

UCLASS()
class MORTAR_API ACannonball : public AStaticMeshActor
{
	GENERATED_BODY()

public:
	ACannonball();

	virtual void TickActor(float DeltaTime, ELevelTick TickType, FActorTickFunction& ThisTickFunction) override;

protected:
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Cannonball|Options")
	float StartPower = 150000.0f;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Cannonball|Options")
	float UpPower = -500.0f;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Cannonball|Options")
	float ForwardPower = 1000.0f;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Cannonball")
	TSubclassOf<AActor> Explosion;

private:
	UFUNCTION()
	void OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);
	
};
