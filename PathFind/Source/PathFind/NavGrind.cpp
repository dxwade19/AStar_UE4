#include "NavGrind.h"
//#include "A_AStarGame.h"
#include <DrawDebugHelpers.h>

ANavGrind::ANavGrind()
{
    PrimaryActorTick.bCanEverTick = true;
    allNodeInGrind = TArray<UA_Node*>();

    //Exemple de creation d'objet avec spawnActor d'une class C++
    //USceneComponent* _root = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));
    //RootComponent = _root;
}


void ANavGrind::BeginPlay()
{
    Super::BeginPlay();
    GenerateGrind();
}


void ANavGrind::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    for (int i = 0; i < allNodeInGrind.Num(); i++)
        allNodeInGrind[i]->PrintPos(GetWorld(), allNodeInGrind[i]->GetPosition(), FColor::White);

}


void ANavGrind::GenerateGrind()
{
    for (int i = 0; i < greedSize; i++)
    {
        for (int j = 0; j < greedSize; j++)
        {
            UA_Node* _node = NewObject<UA_Node>(this);
            _node->InitNode(i * 200, j * 200, GetActorLocation().Z);
            allNodeInGrind.Add(_node);
        }
    }
    GetSuccessors();
}

void ANavGrind::GetSuccessors()
{
    for (int i = 0; i < greedSize * greedSize; i++)
    {
        bool _canRight = i % greedSize != (greedSize - 1);
        bool _canLeft = i % greedSize != 0;
        bool _canTop = i >= greedSize;
        bool _canDown = i < (greedSize* greedSize) - greedSize;

        if (_canRight) allNodeInGrind[i]->AddSuccessor(allNodeInGrind[i + 1]);
        if (_canLeft) allNodeInGrind[i]->AddSuccessor(allNodeInGrind[i - 1]);
        if (_canTop)
        {
            allNodeInGrind[i]->AddSuccessor(allNodeInGrind[i - greedSize]);
            if (_canRight) allNodeInGrind[i]->AddSuccessor(allNodeInGrind[i + 1 - greedSize]);
            if (_canLeft) allNodeInGrind[i]->AddSuccessor(allNodeInGrind[i - 1 - greedSize]);
        }
        if (_canDown)
        {
            allNodeInGrind[i]->AddSuccessor(allNodeInGrind[i + greedSize]);
            if (_canRight) allNodeInGrind[i]->AddSuccessor(allNodeInGrind[i + 1 + greedSize]);
            if (_canLeft) allNodeInGrind[i]->AddSuccessor(allNodeInGrind[i - 1 + greedSize]);
        }
    }
}

void ANavGrind::ResetGrindCost()
{
    for (int i = 0; i < allNodeInGrind.Num(); i++)
        allNodeInGrind[i]->ResetCost();
 
}

UA_Node* ANavGrind::GetCloseNode(FVector _pos)
{
    UA_Node* _node = nullptr;
    float _distance = std::numeric_limits<float>::max();;

    for (int i = 0; i < allNodeInGrind.Num(); i++)
    {
        float _tmpDistance = FVector::Dist(_pos, allNodeInGrind[i]->GetPosition());
        if (_tmpDistance < _distance)
        {
            _distance = _tmpDistance;
            _node = allNodeInGrind[i];
        }
    }
    return _node;
}


//Exemple Manager

/*
    AA_AStarGame* _manager = GetWorld()->GetAuthGameMode<AA_AStarGame>();
    if (_manager)
    {
        _manager->GetGrindManager()->ResetGrindCost();
    }
*/
