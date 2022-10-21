#include "MortarCannon.h"
#include "Components/ArrowComponent.h"
#include "Components/BoxComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Mortar/Characters/PlayerCharacter.h"

AMortarCannon::AMortarCannon()
{
	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	
	CannonBody = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("CannonBody"));
	CannonBody->SetupAttachment(RootComponent);
	
	ArrowComponent = CreateDefaultSubobject<UArrowComponent>(TEXT("Arrow"));
	ArrowComponent->SetupAttachment(RootComponent);

	CollisionBoxOverlap = CreateDefaultSubobject<UBoxComponent>(TEXT("Box"));
	CollisionBoxOverlap->SetCollisionProfileName("Trigger");
	CollisionBoxOverlap->SetupAttachment(RootComponent);

	CollisionBoxOverlap->OnComponentBeginOverlap.AddDynamic(this, &AMortarCannon::OnOverlapBegin);
	CollisionBoxOverlap->OnComponentEndOverlap.AddDynamic(this, &AMortarCannon::OnOverlapEnd);
	
	PrimaryActorTick.bCanEverTick = true;
}

void AMortarCannon::BeginPlay()
{
	Super::BeginPlay();
	
	Player = Cast<APlayerCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));
}

void AMortarCannon::OnOverlapBegin(UPrimitiveComponent* newComp, AActor* OtherActor, UPrimitiveComponent* OtherComp,
	int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (Player == OtherActor)
	{
		Player->Mortal = Cast<AMortarCannon>(this);
		PlayerIsNealy = true;
	}
}

void AMortarCannon::OnOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	if (Player == OtherActor)
	{
		PlayerIsNealy = false;
	}
}

void AMortarCannon::Shoot() const
{
	if (!IsValid(Cannonball))
	{
		return;
	}
	
	const FVector SpawnCannonballPos = GetActorLocation() + GetActorForwardVector() * CannonballOffsetSpawn;
	const FRotator SpawnCannonballRot = GetActorRotation();
	
	if (IsValid(SoundShoot) && IsValid(ExplosionVFX))
	{
		GetWorld()->SpawnActor(ExplosionVFX, &SpawnCannonballPos, &SpawnCannonballRot);
		UGameplayStatics::PlaySoundAtLocation(GetWorld(), SoundShoot, GetActorLocation(), FRotator::ZeroRotator);
	}
	
	GetWorld()->SpawnActor(Cannonball, &SpawnCannonballPos, &SpawnCannonballRot);
}

void AMortarCannon::RotateForward()
{
	if (GetActorRotation().Pitch > 19.0f && GetActorRotation().Pitch < 70.0f)
	{
		const FQuat QuatRotation = FQuat(FRotator(PitchSpeedRotation, 0, 0));
		AddActorLocalRotation(QuatRotation, false, nullptr);		
	}
}

void AMortarCannon::RotateBack()
{
	if (GetActorRotation().Pitch > 20.0f && GetActorRotation().Pitch < 71.0f)
	{
		const FQuat QuatRotation = FQuat(FRotator(-PitchSpeedRotation, 0, 0));
		AddActorLocalRotation(QuatRotation, false, nullptr);		
	}
}
