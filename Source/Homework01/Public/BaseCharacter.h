
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "BaseCharacter.generated.h"

class UInputAction;

// Interaction delegate
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnInteraction);

UCLASS()
class HOMEWORK01_API ABaseCharacter : public ACharacter
{
    GENERATED_BODY()

public:
    ABaseCharacter();

    virtual void Tick(float DeltaTime) override;

    virtual void SetupPlayerInputComponent(
        class UInputComponent* PlayerInputComponent
    ) override;

    UPROPERTY(BlueprintReadOnly, Category = "Sprint")
    bool bIsSprinting = false;

    UPROPERTY(BlueprintAssignable, Category = "Interaction")
    FOnInteraction OnInteraction;

protected:
    virtual void BeginPlay() override;

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Input")
    UInputAction* SprintAction;

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Input")
    UInputAction* InteractAction;

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Sprint")
    float SprintSpeed = 900.0f;

private:
    float NormalSpeed = 500.0f;

    void StartSprint();
    void StopSprint();
    void Interact();
};
