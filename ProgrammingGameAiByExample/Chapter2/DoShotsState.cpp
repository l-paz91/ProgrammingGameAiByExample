// -----------------------------------------------------------------------------

//--INCLUDES--//
#include "DoShotsState.h"

#include "MinersWife.h"

#include "std_lib_facilities.h"

// -----------------------------------------------------------------------------

DoShotsState& DoShotsState::getInstance()
{
	static DoShotsState instance;
	return instance;
}

// -----------------------------------------------------------------------------

void DoShotsState::enter(BaseGameEntityMkII* pEntity)
{
	if (MinersWife* miner = dynamic_cast<MinersWife*>(pEntity))
	{
		cout << "\n" << miner->getName() << ": SHOT TIME";
	}
}

// -----------------------------------------------------------------------------

void DoShotsState::execute(BaseGameEntityMkII* pEntity)
{
	if (MinersWife* miner = dynamic_cast<MinersWife*>(pEntity))
	{
		cout << "\n" << miner->getName() << ": that went down smooth!";
		miner->getStateMachine()->revertToPreviousState();
	}
}

// -----------------------------------------------------------------------------

void DoShotsState::exit(BaseGameEntityMkII* pEntity)
{
	if (MinersWife* miner = dynamic_cast<MinersWife*>(pEntity))
	{
		cout << "\n" << miner->getName() << ": alright, back to work!";
	}
}

// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------