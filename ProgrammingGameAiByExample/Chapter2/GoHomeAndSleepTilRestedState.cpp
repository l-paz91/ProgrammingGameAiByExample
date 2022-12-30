// -----------------------------------------------------------------------------

//--INCLUDES--//
#include <iostream>

#include "EnterMineAndDigForNuggetState.h"
#include "Miner.h"

#include "GoHomeAndSleepTilRestedState.h"

// -----------------------------------------------------------------------------

using namespace std;

// -----------------------------------------------------------------------------

GoHomeAndSleepTilRestedState& GoHomeAndSleepTilRestedState::getInstance()
{
	static GoHomeAndSleepTilRestedState instance;
	return instance;
}

// -----------------------------------------------------------------------------

void GoHomeAndSleepTilRestedState::enter(BaseGameEntityMkII* pEntity)
{
	if (Miner* miner = dynamic_cast<Miner*>(pEntity))
	{
		if (miner->getLocation() != LocationTypes::eSHACK)
		{
			cout << "\n" << miner->getName() << ": " << "Walkin' home";
			miner->SetLocation(LocationTypes::eSHACK);
		}
	}
}

// -----------------------------------------------------------------------------

void GoHomeAndSleepTilRestedState::execute(BaseGameEntityMkII* pEntity)
{
	if (Miner* miner = dynamic_cast<Miner*>(pEntity))
	{
		if (!miner->isFatigued())
		{
			cout << "\n" << miner->getName() << ": " 
				<< "What a gosh darn fantastic nap! Time to find more gold!";

			miner->getStateMachine()->changeState(reinterpret_cast<StateInterface<BaseGameEntityMkII>*>(&EnterMineAndDigForNuggetState::getInstance()));
		}
		else
		{
			miner->decrementFatigue();
			cout << "\n" << miner->getName() << ": " << "zzzzz.......";
		}
	}
}

// -----------------------------------------------------------------------------

void GoHomeAndSleepTilRestedState::exit(BaseGameEntityMkII* pEntity)
{
	if (Miner* miner = dynamic_cast<Miner*>(pEntity))
	{
		cout << "\n" << miner->getName() << ": " << "Leavin' the house";
	}
}

// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------