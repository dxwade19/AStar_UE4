#pragma once
#include "NavGrind.h"

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "A_AStarGame.generated.h"

/**
 * 
 */
UCLASS()
class PATHFIND_API AA_AStarGame : public AGameModeBase
{
	GENERATED_BODY()

private:
		UPROPERTY(EditAnywhere) TSoftObjectPtr<ANavGrind> navGrind = nullptr;

public:
	FORCEINLINE ANavGrind* GetGrindManager() { return navGrind.Get(); }

};


//InitGame to creat object et ne pas oublier le Super::InitGame pour rappeler les fonctions
