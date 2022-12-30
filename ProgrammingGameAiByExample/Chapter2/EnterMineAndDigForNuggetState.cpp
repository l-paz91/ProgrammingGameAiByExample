// -----------------------------------------------------------------------------

//--INCLUDES--//
#include <iostream>

#include "Miner.h"

#include "EnterMineAndDigForNuggetState.h"

// -----------------------------------------------------------------------------

using namespace std;

// -----------------------------------------------------------------------------

void EnterMineAndDigForNuggetState::enter(Miner* pEntity)
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

void EnterMineAndDigForNuggetState::execute(Miner* pEntity)
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
			//miner->changeState(VisitBankAndDepositGoldState::getInstance());
		}

		// if thirsty go and get a whiskey
		if (miner->isThirsty())
		{
			//miner->changeState(QuenchThirstState::getInstance());
		}
	}
}

// -----------------------------------------------------------------------------

void EnterMineAndDigForNuggetState::exit(Miner* pEntity)
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


