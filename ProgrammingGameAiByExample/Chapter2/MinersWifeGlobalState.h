// -----------------------------------------------------------------------------
#ifndef MinersWifeGlobalState_H
#define MinersWifeGlobalState_H
// -----------------------------------------------------------------------------

//--INCLUDES--//
#include "State.h"

class BaseGameEntityMkII;

// -----------------------------------------------------------------------------

class MinersWifeGlobalState
	: public StateInterface<BaseGameEntityMkII>
{
public:
	MinersWifeGlobalState(const MinersWifeGlobalState&) = delete;
	void  operator=(const MinersWifeGlobalState&) = delete;

	static MinersWifeGlobalState& getInstance();

private:
	MinersWifeGlobalState() {}

	// StateInterface
	virtual void enter(BaseGameEntityMkII* pEntity);
	virtual void execute(BaseGameEntityMkII* pEntity);
	virtual void exit(BaseGameEntityMkII* pEntity);
	// ~StateInterface
};

// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------
#endif // !MinersWifeGlobalState_H