
#include "BaseCharacter.h"
#include "EnhancedInputComponent.h"
#include "InputAction.h"
#include "GameFramework/CharacterMovementComponent.h"

ABaseCharacter::ABaseCharacter()
{
    PrimaryActorTick.bCanEverTick = true;
}

void ABaseCharacter::BeginPlay()
{
    Super::BeginPlay();

    // Save the default movement speed
    NormalSpeed = GetCharacterMovement()->MaxWalkSpeed;
}

void ABaseCharacter::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
}

void ABaseCharacter::SetupPlayerInputComponent(
    UInputComponent* PlayerInputComponent)
{
    Super::SetupPlayerInputComponent(PlayerInputComponent);

    UEnhancedInputComponent* EnhancedInput =
        Cast<UEnhancedInputComponent>(PlayerInputComponent);

    if (EnhancedInput)
    {
        if (SprintAction)
        {
            EnhancedInput->BindAction(
                SprintAction,
                ETriggerEvent::Started,
                this,
                &ABaseCharacter::StartSprint
            );

            EnhancedInput->BindAction(
                SprintAction,
                ETriggerEvent::Completed,
                this,
                &ABaseCharacter::StopSprint
            );

            EnhancedInput->BindAction(
                SprintAction,
                ETriggerEvent::Canceled,
                this,
                &ABaseCharacter::StopSprint
            );
        }

        if (InteractAction)
        {
            EnhancedInput->BindAction(
                InteractAction,
                ETriggerEvent::Started,
                this,
                &ABaseCharacter::Interact
            );
        }
    }
}

void ABaseCharacter::StartSprint()
{
    bIsSprinting = true;
    GetCharacterMovement()->MaxWalkSpeed = SprintSpeed;
}

void ABaseCharacter::StopSprint()
{
    bIsSprinting = false;
    GetCharacterMovement()->MaxWalkSpeed = NormalSpeed;
}

void ABaseCharacter::Interact()
{
    OnInteraction.Broadcast();
}

