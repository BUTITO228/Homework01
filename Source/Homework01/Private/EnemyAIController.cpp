
#include "EnemyAIController.h"
#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "GameFramework/Pawn.h"

void AEnemyAIController::OnPossess(APawn* InPawn)
{
    Super::OnPossess(InPawn);

    if (InPawn && BehaviorTreeAsset)
    {
        UBlackboardComponent* BlackboardComp = nullptr;

        if (UseBlackboard(
            BehaviorTreeAsset->BlackboardAsset,
            BlackboardComp))
        {
            BlackboardComp->SetValueAsVector(
                TEXT("StartLocation"),
                InPawn->GetActorLocation()
            );

            RunBehaviorTree(BehaviorTreeAsset);
        }
    }
}
