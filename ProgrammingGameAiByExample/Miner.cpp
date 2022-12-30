// -----------------------------------------------------------------------------

//--INCLUDES--//
#include "Miner.h"

// -----------------------------------------------------------------------------

Miner::Miner()
	: mComfortLevel(5)
	, mMaxNuggets(3)
	, mThirstThreshold(5)
	, mTirednessThreshold(5)
	, mGoldCarried(0)
	, mMoneyInBank(0)
	, mThirst(0)
	, mFatigue(0)
	, mLocation(LocationTypes::eDEFAULT)
	, mPlayerType(PlayerEntities::eMINER_BOB)
{
	//getStateMachine()->setCurrentState(GoHomeAndSleepTillRestedState::getInstance());
	//getStateMachine()->setGlobalState(MinorGlobalState::getInstance());
}

// -----------------------------------------------------------------------------

void Miner::update()
{
	++mThirst;

	Super::update();
}

// -----------------------------------------------------------------------------

void Miner::increaseGoldCarried(int pAddition)
{
	mGoldCarried += pAddition;
}

// -----------------------------------------------------------------------------

void Miner::incrementFatigue()
{
	++mFatigue;
}

// -----------------------------------------------------------------------------

void Miner::decrementFatigue()
{
	--mFatigue;
}

// -----------------------------------------------------------------------------

void Miner::SetLocation(const LocationTypes pNewLocation)
{
	mLocation = pNewLocation;
}

// -----------------------------------------------------------------------------

bool Miner::pocketsFull() const
{
	return mGoldCarried >= mMaxNuggets;
}

// -----------------------------------------------------------------------------

bool Miner::isThirsty() const
{
	return mThirst >= mThirstThreshold;
}

// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------