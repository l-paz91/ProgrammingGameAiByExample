// -----------------------------------------------------------------------------
#ifndef EnterMineAndDigForNuggetState_H
#define EnterMineAndDigForNuggetState_H
// -----------------------------------------------------------------------------

//--INCLUDES--//
#include "State.h"

class BaseGameEntityMkII;

// -----------------------------------------------------------------------------

class EnterMineAndDigForNuggetState
	: public StateInterface<BaseGameEntityMkII>
{
public:
	EnterMineAndDigForNuggetState(const EnterMineAndDigForNuggetState&) = delete;
	void  operator=(const EnterMineAndDigForNuggetState&) = delete;

	static EnterMineAndDigForNuggetState& getInstance();

private:
	EnterMineAndDigForNuggetState() {}

	// StateInterface
	virtual void enter(BaseGameEntityMkII* pEntity);
	virtual void execute(BaseGameEntityMkII* pEntity);
	virtual void exit(BaseGameEntityMkII* pEntity);
	// ~StateInterface
};

// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------
#endif // !EnterMineAndDigForNuggetState_H