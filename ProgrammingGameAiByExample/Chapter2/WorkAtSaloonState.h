// -----------------------------------------------------------------------------
#ifndef WorkAtSaloonState_H
#define WorkAtSaloonState_H
// -----------------------------------------------------------------------------

//--INCLUDES--//
#include "State.h"

class BaseGameEntityMkII;

// -----------------------------------------------------------------------------

class WorkAtSaloonState
	: public StateInterface<BaseGameEntityMkII>
{
public:
	WorkAtSaloonState(const WorkAtSaloonState&) = delete;
	void  operator=(const WorkAtSaloonState&) = delete;

	static WorkAtSaloonState& getInstance();

private:
	WorkAtSaloonState() {}

	// StateInterface
	virtual void enter(BaseGameEntityMkII* pEntity);
	virtual void execute(BaseGameEntityMkII* pEntity);
	virtual void exit(BaseGameEntityMkII* pEntity);
	// ~StateInterface
};
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------
#endif // !WorkAtSaloonState_H