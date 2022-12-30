// -----------------------------------------------------------------------------
#ifndef QuenchThirstState_H
#define QuenchThirstState_H
// -----------------------------------------------------------------------------

//--INCLUDES--//
#include "State.h"

class Miner;

// -----------------------------------------------------------------------------

class QuenchThirstState
	: public StateInterface<Miner>
{
public:
	QuenchThirstState(const QuenchThirstState&) = delete;
	void  operator=(const QuenchThirstState&) = delete;

	static QuenchThirstState& getInstance();

private:
	QuenchThirstState() {}

	// StateInterface
	virtual void enter(Miner* pEntity);
	virtual void execute(Miner* pEntity);
	virtual void exit(Miner* pEntity);
	// ~StateInterface
};
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------
#endif // !QuenchThirstState_H