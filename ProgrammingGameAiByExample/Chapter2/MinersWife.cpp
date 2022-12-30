// -----------------------------------------------------------------------------

//--INCLUDES--//
#include "MinersWifeGlobalState.h"
#include "WorkAtSaloonState.h"

#include "MinersWife.h"

// -----------------------------------------------------------------------------

MinersWife::MinersWife(PlayerEntities pPlayerEntityType)
	: mLocation(LocationTypes::eSHACK)
	, mPlayerType(pPlayerEntityType)
{
	getStateMachine()->setCurrentState(reinterpret_cast<StateInterface<BaseGameEntityMkII>*>(&WorkAtSaloonState::getInstance()));
	getStateMachine()->setPreviousState(reinterpret_cast<StateInterface<BaseGameEntityMkII>*>(&WorkAtSaloonState::getInstance()));
	getStateMachine()->setGlobalState(reinterpret_cast<StateInterface<BaseGameEntityMkII>*>(&MinersWifeGlobalState::getInstance()));
}

// -----------------------------------------------------------------------------

void MinersWife::update()
{
	Super::update();
}

// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------