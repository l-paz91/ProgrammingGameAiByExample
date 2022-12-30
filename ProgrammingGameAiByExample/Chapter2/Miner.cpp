// -----------------------------------------------------------------------------

//--INCLUDES--//
#include "GoHomeAndSleepTilRestedState.h"

#include "Miner.h"

// -----------------------------------------------------------------------------

Miner::Miner(PlayerEntities pPlayerEntityType)
	: mComfortLevel(5)
	, mMaxNuggets(3)
	, mThirstThreshold(5)
	, mTirednessThreshold(5)
	, mGoldCarried(0)
	, mMoneyInBank(0)
	, mThirst(0)
	, mFatigue(0)
	, mLocation(LocationTypes::eDEFAULT)
	, mPlayerType(pPlayerEntityType)
{
	getStateMachine()->setCurrentState(reinterpret_cast<StateInterface<BaseGameEntityMkII>*>(&GoHomeAndSleepTilRestedState::getInstance()));
}

// -----------------------------------------------------------------------------

void Miner::update()
{
	++mThirst;

	Super::update();
}

// -----------------------------------------------------------------------------

void Miner::setGoldCarried(int pValue)
{
	mGoldCarried = pValue;
}

// -----------------------------------------------------------------------------

void Miner::increaseGoldCarried(int pAddition)
{
	mGoldCarried += pAddition;
}

// -----------------------------------------------------------------------------

void Miner::increaseMoneyInBank(int pAddition)
{
	mMoneyInBank += pAddition;
	if (mMoneyInBank < 0)
	{
		mMoneyInBank = 0;
	}
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

bool Miner::isFatigued() const
{
	return mFatigue > mTirednessThreshold;
}

// -----------------------------------------------------------------------------

void Miner::buyAndDrinkAWhiskey()
{
	mThirst = 0;
	mMoneyInBank -= 2;
}

// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------