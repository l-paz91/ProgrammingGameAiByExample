// -----------------------------------------------------------------------------
#ifndef GoHomeAndSleepTilRestedState_H
#define GoHomeAndSleepTilRestedState_H
// -----------------------------------------------------------------------------

//--INCLUDES--//
#include "State.h"

class BaseGameEntityMkII;

// -----------------------------------------------------------------------------

class GoHomeAndSleepTilRestedState
	: public StateInterface<BaseGameEntityMkII>
{
public:
	GoHomeAndSleepTilRestedState(const GoHomeAndSleepTilRestedState&) = delete;
	void  operator=(const GoHomeAndSleepTilRestedState&) = delete;

	static GoHomeAndSleepTilRestedState& getInstance();

private:
	GoHomeAndSleepTilRestedState() {}

	// StateInterface
	virtual void enter(BaseGameEntityMkII* pEntity);
	virtual void execute(BaseGameEntityMkII* pEntity);
	virtual void exit(BaseGameEntityMkII* pEntity);
	// ~StateInterface
};

// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------
#endif // !GoHomeAndSleepTilRestedState_H