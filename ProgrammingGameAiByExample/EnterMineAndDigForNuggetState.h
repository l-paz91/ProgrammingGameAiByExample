// -----------------------------------------------------------------------------
#ifndef EnterMineAndDigForNuggetState_H
#define EnterMineAndDigForNuggetState_H
// -----------------------------------------------------------------------------

//--INCLUDES--//
#include "State.h"

// -----------------------------------------------------------------------------

class EnterMineAndDigForNuggetState
	: public StateInterface<Miner>
{
public:
	EnterMineAndDigForNuggetState(const EnterMineAndDigForNuggetState&) = delete;
	void  operator=(const EnterMineAndDigForNuggetState&) = delete;

private:
	EnterMineAndDigForNuggetState() {}

	// StateInterface
	virtual void enter(Miner* pEntity);
	virtual void execute(Miner* pEntity);
	virtual void exit(Miner* pEntity);
	// ~StateInterface

	static EnterMineAndDigForNuggetState& getInstance()
	{
		static EnterMineAndDigForNuggetState instance;
		return instance;
	}
};

// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------
#endif // !EnterMineAndDigForNuggetState_H