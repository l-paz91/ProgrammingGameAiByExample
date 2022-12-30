// -----------------------------------------------------------------------------
#ifndef MinersWife_H
#define MinersWife_H
// -----------------------------------------------------------------------------

//--INCLUDES--//
#include "BaseGameEntityMkII.h"
#include "LocationTypes.h"
#include "PlayerEntities.h"

// -----------------------------------------------------------------------------

class MinersWife
	: public BaseGameEntityMkII
{
public:
	typedef BaseGameEntityMkII Super;

	MinersWife(PlayerEntities pPlayerEntityType);
	virtual ~MinersWife() {}

	// BaseGameEntityMkII
	virtual void update() override;
	// ~BaseGameEntityMkII

	const LocationTypes getLocation() const { return mLocation; }
	void setLocation(const LocationTypes pNewLocation);

	std::string getName() { return PlayerEntitiesHelpers::getNameOfEntity(mPlayerType); }

private:
	LocationTypes mLocation;
	PlayerEntities mPlayerType;
};

// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------
#endif // !MinersWife_H