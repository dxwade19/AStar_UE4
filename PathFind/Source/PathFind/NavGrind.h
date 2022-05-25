#pragma once
#include "A_Path.h"

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "NavGrind.generated.h"

UCLASS()
class PATHFIND_API ANavGrind : public AActor
{
	GENERATED_BODY()
	
private:

	UPROPERTY(EditAnyWhere, Category = "GrindSettings") int greedSize = 5;
	UPROPERTY(EditAnyWhere, Category = "GrindSettings") TSubclassOf<UObject> nodeClass;

	UPROPERTY(EditAnyWhere, Category = "GrindNode") TArray<UA_Node*> allNodeInGrind;


protected:
	virtual void BeginPlay() override;

	void GenerateGrind();
	void GetSuccessors();

public:
	ANavGrind();

	virtual void Tick(float DeltaTime) override;

	TArray<UA_Node*> GetGrind() { return allNodeInGrind; };

	void ResetGrindCost();

	UA_Node* GetCloseNode(FVector _pos);

};
