// -----------------------------------------------------------------------------

//--INCLUDES--//
#include <iostream>

#include "Miner.h"
#include "QuenchThirstState.h"
#include "VisitBankAndDepositGoldState.h"

#include "EnterMineAndDigForNuggetState.h"

// -----------------------------------------------------------------------------

using namespace std;

// -----------------------------------------------------------------------------

EnterMineAndDigForNuggetState& EnterMineAndDigForNuggetState::getInstance()
{
	static EnterMineAndDigForNuggetState instance;
	return instance;
}

// -----------------------------------------------------------------------------

void EnterMineAndDigForNuggetState::enter(BaseGameEntityMkII* pEntity)
{
	// if the miner is not already located at the gold mine, then change
	// location to the gold mine
	if (Miner* miner = dynamic_cast<Miner*>(pEntity))
	{
		if (miner->getLocation() != LocationTypes::eGOLDMINE)
		{
			cout << '\n' << miner->getName() << ": "
				<< "Walkin' to the gold mine";

			miner->SetLocation(LocationTypes::eGOLDMINE);
		}
	}
}

// -----------------------------------------------------------------------------

void EnterMineAndDigForNuggetState::execute(BaseGameEntityMkII* pEntity)
{
	// the miner digs for gold until he is carrying in excess of MaxNuggets
	// if he gets thirsty during his digging he stops work and changes state
	// to go to the saloon for a whiskey
	if (Miner* miner = dynamic_cast<Miner*>(pEntity))
	{
		miner->increaseGoldCarried(1);
		miner->incrementFatigue();

		cout << '\n' << miner->getName() << ": "
			<< "Pickin' up a nugget";

		// if enough gold mined, go and put it in the bank
		if (miner->pocketsFull())
		{
			miner->getStateMachine()->changeState(reinterpret_cast<StateInterface<BaseGameEntityMkII>*>(&VisitBankAndDepositGoldState::getInstance()));
		}

		// if thirsty go and get a whiskey
		if (miner->isThirsty())
		{
			miner->getStateMachine()->changeState(reinterpret_cast<StateInterface<BaseGameEntityMkII>*>(&QuenchThirstState::getInstance()));
		}
	}
}

// -----------------------------------------------------------------------------

void EnterMineAndDigForNuggetState::exit(BaseGameEntityMkII* pEntity)
{
	if (Miner* miner = dynamic_cast<Miner*>(pEntity))
	{
		cout << '\n' << miner->getName() << ": "
			<< "Ah'm leavin' the gold mine with mah pockets full o' sweet gold";
	}
}

// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------


