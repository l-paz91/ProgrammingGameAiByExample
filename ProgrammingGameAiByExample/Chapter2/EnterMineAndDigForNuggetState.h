// -----------------------------------------------------------------------------
#ifndef EnterMineAndDigForNuggetState_H
#define EnterMineAndDigForNuggetState_H
// -----------------------------------------------------------------------------

//--INCLUDES--//
#include "State.h"

class Miner;

// -----------------------------------------------------------------------------

class EnterMineAndDigForNuggetState
	: public StateInterface<Miner>
{
public:
	EnterMineAndDigForNuggetState(const EnterMineAndDigForNuggetState&) = delete;
	void  operator=(const EnterMineAndDigForNuggetState&) = delete;

	static EnterMineAndDigForNuggetState& getInstance();

private:
	EnterMineAndDigForNuggetState() {}

	// StateInterface
	virtual void enter(Miner* pEntity);
	virtual void execute(Miner* pEntity);
	virtual void exit(Miner* pEntity);
	// ~StateInterface
};

// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------
#endif // !EnterMineAndDigForNuggetState_H