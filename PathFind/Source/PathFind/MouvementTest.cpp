#include "MouvementTest.h"


UMouvementTest::UMouvementTest()
{
	PrimaryComponentTick.bCanEverTick = true;
}


void UMouvementTest::BeginPlay()
{
	Super::BeginPlay();
}


void UMouvementTest::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (!test)
	{
		GetPathToTarget();
		test = true;
	}
	else
	{
		for (int i = 0; i < pathFinal->GetNodeInPath().Num(); i++)
			pathFinal->GetNodeInPath()[i]->PrintPos(GetWorld(), pathFinal->GetNodeInPath()[i]->GetPosition() + (FVector::UpVector * 300),FColor::Yellow);
	}
}


void UMouvementTest::GetPathToTarget()
{
	if (!target || !actorAttach) return;
	
	UActorComponent* _component = actorAttach->GetComponentByClass(pathFindClass);
	UA_PathFinder* _pathFinder = Cast<UA_PathFinder>(_component);

	if (!_pathFinder) return;
	pathFinal = _pathFinder->GetPathBetweenTwoActor(_pathFinder->GetNavGrind()->GetCloseNode(actorAttach->GetActorLocation()), _pathFinder->GetNavGrind()->GetCloseNode(target->GetActorLocation()));
	if (!pathFinal) return;
	GEngine->AddOnScreenDebugMessage(-1, 2, FColor::Red, FString::Printf(TEXT("Node Final Number : %d"), pathFinal->GetNodeInPath().Num()));
}

