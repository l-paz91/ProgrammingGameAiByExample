// -----------------------------------------------------------------------------
#ifndef GoHomeAndSleepTilRestedState_H
#define GoHomeAndSleepTilRestedState_H
// -----------------------------------------------------------------------------

//--INCLUDES--//
#include "State.h"

class Miner;

// -----------------------------------------------------------------------------

class GoHomeAndSleepTilRestedState
	: public StateInterface<Miner>
{
public:
	GoHomeAndSleepTilRestedState(const GoHomeAndSleepTilRestedState&) = delete;
	void  operator=(const GoHomeAndSleepTilRestedState&) = delete;

	static GoHomeAndSleepTilRestedState& getInstance();

private:
	GoHomeAndSleepTilRestedState() {}

	// StateInterface
	virtual void enter(Miner* pEntity);
	virtual void execute(Miner* pEntity);
	virtual void exit(Miner* pEntity);
	// ~StateInterface
};

// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------
#endif // !GoHomeAndSleepTilRestedState_H