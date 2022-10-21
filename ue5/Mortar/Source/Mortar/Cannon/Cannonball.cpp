#include "Cannonball.h"
#include "Components/BoxComponent.h"

ACannonball::ACannonball()
{
	GetStaticMeshComponent()->OnComponentHit.AddDynamic(this, &ACannonball::OnHit);

	PrimaryActorTick.bCanEverTick = true;
}

void ACannonball::BeginPlay()
{
	Super::BeginPlay();

	if (IsValid(GetStaticMeshComponent()))
	{
		GetStaticMeshComponent()->AddForce(StartPower * GetActorForwardVector() * GetStaticMeshComponent()->GetMass());
	}
}

void ACannonball::TickActor(float DeltaTime, ELevelTick TickType, FActorTickFunction& ThisTickFunction)
{
	Super::TickActor(DeltaTime, TickType, ThisTickFunction);

	GetStaticMeshComponent()->AddForce((UpPower * FVector::UpVector + ForwardPower * GetActorForwardVector()) * GetStaticMeshComponent()->GetMass() );
}

void ACannonball::OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp,
                        FVector NormalImpulse, const FHitResult& Hit)
{
	const FVector SpawnVFX = GetActorLocation();
	const FRotator RotatorVFX = GetActorRotation();
	GetWorld()->SpawnActor(Explosion, &SpawnVFX, &RotatorVFX);
	Destroy();
}
