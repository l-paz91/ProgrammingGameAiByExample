// -----------------------------------------------------------------------------

//--INCLUDES--//
#include <iostream>

#include "EnterMineAndDigForNuggetState.h"
#include "Miner.h"

#include "QuenchThirstState.h"

// -----------------------------------------------------------------------------

using namespace std;

// -----------------------------------------------------------------------------

QuenchThirstState& QuenchThirstState::getInstance()
{
	static QuenchThirstState instance;
	return instance;
}

// -----------------------------------------------------------------------------

void QuenchThirstState::enter(BaseGameEntityMkII* pEntity)
{
	if (Miner* miner = dynamic_cast<Miner*>(pEntity))
	{
		if (miner->getLocation() != LocationTypes::eSALOON)
		{
			cout << "\n" << miner->getName() << ": " << "Boy, ah sure is thirsty! Walkin' to the saloon";
			miner->SetLocation(LocationTypes::eSALOON);
		}
	}
}

// -----------------------------------------------------------------------------

void QuenchThirstState::execute(BaseGameEntityMkII* pEntity)
{
	if (Miner* miner = dynamic_cast<Miner*>(pEntity))
	{
		if (miner->isThirsty())
		{
			miner->buyAndDrinkAWhiskey();
			cout << "\n" << miner->getName() << ": "
				<< "That's a mighty fine sippin' liqueur";

			miner->getStateMachine()->changeState(reinterpret_cast<StateInterface<BaseGameEntityMkII>*>(&EnterMineAndDigForNuggetState::getInstance()));
		}
		else
		{
			cout << "\n" << miner->getName() << ": " << "How did I get here?";
		}
	}
}

// -----------------------------------------------------------------------------

void QuenchThirstState::exit(BaseGameEntityMkII* pEntity)
{
	if (Miner* miner = dynamic_cast<Miner*>(pEntity))
	{
		cout << "\n" << miner->getName() << ": " << "Leavin' the saloon, feelin' good";
	}
}

// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------