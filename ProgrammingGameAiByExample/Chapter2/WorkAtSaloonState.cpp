// -----------------------------------------------------------------------------

//--INCLUDES--//
#include "WorkAtSaloonState.h"

#include "DoShotsState.h"
#include "MinersWife.h"

#include "std_lib_facilities.h"

// -----------------------------------------------------------------------------

WorkAtSaloonState& WorkAtSaloonState::getInstance()
{
	static WorkAtSaloonState instance;
	return instance;
}

// -----------------------------------------------------------------------------

void WorkAtSaloonState::enter(BaseGameEntityMkII* pEntity)
{

}

// -----------------------------------------------------------------------------

void WorkAtSaloonState::execute(BaseGameEntityMkII* pEntity)
{
	if (MinersWife* miner = dynamic_cast<MinersWife*>(pEntity))
	{
		switch (randint(0, 2))
		{
		case 0:
			cout << "\n" << miner->getName() << ": Polishing the same glass over and over with a dirty rag!";
			break;
		case 1:
			cout << "\n" << miner->getName() << ": Breaking up a fight!";
			break;
		case 2:
			cout << "\n" << miner->getName() << ": Making moonshine!";
			break;
		default:
			break;
		}
	}
}

// -----------------------------------------------------------------------------

void WorkAtSaloonState::exit(BaseGameEntityMkII* pEntity)
{

}

// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------


