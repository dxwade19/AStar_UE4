#pragma once
#include "NavGrind.h"

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "A_PathFinder.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class PATHFIND_API UA_PathFinder : public UActorComponent
{
	GENERATED_BODY()

private:
	UPROPERTY() UA_Path* pathToFollow;
	UPROPERTY(EditAnywhere) ANavGrind* navGrind;

protected:
	virtual void BeginPlay() override;

public:	
	UA_PathFinder();
	ANavGrind* GetNavGrind() { return navGrind; }


	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UA_Path* GetPathBetweenTwoActor(UA_Node* _startNode, UA_Node* _endNode);
};
