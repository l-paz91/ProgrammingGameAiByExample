// -----------------------------------------------------------------------------

//--INCLUDES--//
#include <iostream>

#include "EnterMineAndDigForNuggetState.h"
#include "GoHomeAndSleepTilRestedState.h"
#include "Miner.h"

#include "VisitBankAndDepositGoldState.h"

// -----------------------------------------------------------------------------

using namespace std;

// -----------------------------------------------------------------------------

VisitBankAndDepositGoldState& VisitBankAndDepositGoldState::getInstance()
{
	static VisitBankAndDepositGoldState instance;
	return instance;
}

// -----------------------------------------------------------------------------

void VisitBankAndDepositGoldState::enter(BaseGameEntityMkII* pEntity)
{
	if (Miner* miner = dynamic_cast<Miner*>(pEntity))
	{
		if (miner->getLocation() != LocationTypes::eBANK)
		{
			cout << "\n" << miner->getName() << ": " << "Goin' to the bank. Yes siree";
			miner->SetLocation(LocationTypes::eBANK);
		}
	}

}

// -----------------------------------------------------------------------------

void VisitBankAndDepositGoldState::execute(BaseGameEntityMkII* pEntity)
{
	if (Miner* miner = dynamic_cast<Miner*>(pEntity))
	{
		miner->increaseMoneyInBank(miner->getGoldCarried());
		miner->setGoldCarried(0);

		cout << "\n" << miner->getName() << ": " << "Depositin' gold. Total savings now: "
			<< miner->getMoneyInBank();

		//wealthy enough for a rest?
		if (miner->getMoneyInBank() >= miner->getComfortLevel())
		{
			cout << "\n" << miner->getName() << ": "
				<< "WooHoo! Rich enough for now. Back home to mah li'lle lady";

			miner->getStateMachine()->changeState(reinterpret_cast<StateInterface<BaseGameEntityMkII>*>(&GoHomeAndSleepTilRestedState::getInstance()));
		}
		else
		{
			// get more gold - this looks horrible but it works
			miner->getStateMachine()->changeState(reinterpret_cast<StateInterface<BaseGameEntityMkII>*>(&EnterMineAndDigForNuggetState::getInstance()));
		}
	}
}

// -----------------------------------------------------------------------------

void VisitBankAndDepositGoldState::exit(BaseGameEntityMkII* pEntity)
{
	if (Miner* miner = dynamic_cast<Miner*>(pEntity))
	{
		cout << "\n" << miner->getName() << ": " << "Leavin' the bank";
	}
}

// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------


