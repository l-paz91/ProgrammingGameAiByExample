// -----------------------------------------------------------------------------

//--INCLUDES--//
#include "MinersWifeGlobalState.h"

#include "DoShotsState.h"
#include "MinersWife.h"
#include "std_lib_facilities.h"


// -----------------------------------------------------------------------------

MinersWifeGlobalState& MinersWifeGlobalState::getInstance()
{
	static MinersWifeGlobalState instance;
	return instance;
}

// -----------------------------------------------------------------------------

void MinersWifeGlobalState::enter(BaseGameEntityMkII* pEntity)
{

}

// -----------------------------------------------------------------------------

void MinersWifeGlobalState::execute(BaseGameEntityMkII* pEntity)
{
	if (MinersWife* miner = dynamic_cast<MinersWife*>(pEntity))
	{
		if (randint(10) < 1)
		{
			miner->getStateMachine()->changeState(reinterpret_cast<StateInterface<BaseGameEntityMkII>*>(&DoShotsState::getInstance()));
		}
	}
}

// -----------------------------------------------------------------------------

void MinersWifeGlobalState::exit(BaseGameEntityMkII* pEntity)
{

}

// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------