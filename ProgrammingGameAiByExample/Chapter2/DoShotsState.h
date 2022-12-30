// -----------------------------------------------------------------------------
#ifndef DoShotsState_H
#define DoShotsState_H
// -----------------------------------------------------------------------------

//--INCLUDES--//
#include "State.h"

class BaseGameEntityMkII;

// -----------------------------------------------------------------------------

class DoShotsState
	: public StateInterface<BaseGameEntityMkII>
{
public:
	DoShotsState(const DoShotsState&) = delete;
	void  operator=(const DoShotsState&) = delete;

	static DoShotsState& getInstance();

private:
	DoShotsState() {}

	// StateInterface
	virtual void enter(BaseGameEntityMkII* pEntity);
	virtual void execute(BaseGameEntityMkII* pEntity);
	virtual void exit(BaseGameEntityMkII* pEntity);
	// ~StateInterface
};

// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------
#endif // !DoShotsState_H