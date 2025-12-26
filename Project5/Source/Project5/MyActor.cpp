#include "MyActor.h"
#include "Engine/Engine.h"

// Sets default values
AMyActor::AMyActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMyActor::Turn()
{
	int ranX = FMath::RandRange(0, 360);
	int ranY = FMath::RandRange(0, 360);
	int ranZ = FMath::RandRange(0, 360);
	FRotator rotation(ranX, ranY, ranZ);
	SetActorRotation(rotation);
	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 3.0f, FColor::Blue, FString::Printf(TEXT("Rotation : %s"), *rotation.ToString()));
	}
}
void AMyActor::Move()
{
	int ranX = FMath::RandRange(0, 500);
	int ranY = FMath::RandRange(0, 500);
	int ranZ = FMath::RandRange(0, 20);
	FVector location(ranX, ranY, ranZ);
	SetActorLocation(location);
	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 3.0f, FColor::Blue, FString::Printf(TEXT("Location : %s"), *location.ToString()));
	}
}

	void AMyActor::BeginPlay()
	{
		Super::BeginPlay();
		if (GEngine)
		{
			FVector location = GetActorLocation();
			GEngine->AddOnScreenDebugMessage(-1, 3.0f, FColor::Blue, FString::Printf(TEXT("Location : %s"), *location.ToString()));
		}

		SetActorLocation(FVector(0, 50, 0));
		ElapsedTime = 0.0f;
		CurrentCount = 0;
	}


// Called every frame
	void AMyActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (ElapsedTime >= 1.0f && CurrentCount<10)
	{
		Move();
		Turn();
		CurrentCount += 1;
		ElapsedTime = 0.0f;
	}
		ElapsedTime += DeltaTime;
		

		
		
	
}

