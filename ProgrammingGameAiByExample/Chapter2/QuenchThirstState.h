// -----------------------------------------------------------------------------
#ifndef QuenchThirstState_H
#define QuenchThirstState_H
// -----------------------------------------------------------------------------

//--INCLUDES--//
#include "State.h"

class BaseGameEntityMkII;

// -----------------------------------------------------------------------------

class QuenchThirstState
	: public StateInterface<BaseGameEntityMkII>
{
public:
	QuenchThirstState(const QuenchThirstState&) = delete;
	void  operator=(const QuenchThirstState&) = delete;

	static QuenchThirstState& getInstance();

private:
	QuenchThirstState() {}

	// StateInterface
	virtual void enter(BaseGameEntityMkII* pEntity);
	virtual void execute(BaseGameEntityMkII* pEntity);
	virtual void exit(BaseGameEntityMkII* pEntity);
	// ~StateInterface
};
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------
#endif // !QuenchThirstState_H