// -----------------------------------------------------------------------------
#ifndef Miner_H
#define Miner_H
// -----------------------------------------------------------------------------

//--INCLUDES--//
#include "BaseGameEntityMkII.h"
#include "LocationTypes.h"
#include "PlayerEntities.h"

// -----------------------------------------------------------------------------

class Miner
	: public BaseGameEntityMkII
{
public:
	typedef BaseGameEntityMkII Super;

	Miner();
	virtual ~Miner() {}

	// BaseGameEntityMkII
	virtual void update() override;
	// ~BaseGameEntityMkII

	void increaseGoldCarried(int pAddition);
	void incrementFatigue();
	void decrementFatigue();
	void SetLocation(const LocationTypes pNewLocation);
	bool pocketsFull() const;
	bool isThirsty() const;

	std::string getName() { return PlayerEntitiesHelpers::getNameOfEntity(mPlayerType); }

	const LocationTypes getLocation() const { return mLocation; }
	const PlayerEntities getPlayerType() const { return mPlayerType; }
private:
	const int mComfortLevel;			//the amount of gold a miner must have before he feels comfortable
	const int mMaxNuggets;				//the amount of nuggets a miner can carry
	const int mThirstThreshold;			//above this value a miner is thirsty
	const int mTirednessThreshold;		//above this value a miner is sleepy

	int mGoldCarried;		// how many nuggets the miner has in pockets
	int mMoneyInBank;		// how much money miner has in bank
	int mThirst;			// the higher the value, the thirstier the miner
	int mFatigue;			// the higher the value, the more tired the miner

	LocationTypes mLocation;
	PlayerEntities mPlayerType;
};

// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------
#endif // !Miner_H