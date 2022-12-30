// -----------------------------------------------------------------------------

//--INCLUDES--//
#include "PlayerEntities.h"

// -----------------------------------------------------------------------------

namespace PlayerEntitiesHelpers
{
	std::string getNameOfEntity(PlayerEntities pPlayerEntity)
	{
		using namespace std;

		switch (pPlayerEntity)
		{
		case PlayerEntities::eMINER_BOB:
			return "Miner Bob";
		case PlayerEntities::eELSA:
			return "Elsa";
		case PlayerEntities::eDEFAULT:
			return "Default Player Entity";
		default:
			return "Unknown";
		}
	}
}
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------