// -----------------------------------------------------------------------------
#ifndef VisitBankAndDepositGoldState_H
#define VisitBankAndDepositGoldState_H
// -----------------------------------------------------------------------------

//--INCLUDES--//
#include "State.h"

class Miner;

// -----------------------------------------------------------------------------

class VisitBankAndDepositGoldState
	: public StateInterface<Miner>
{
public:
	VisitBankAndDepositGoldState(const VisitBankAndDepositGoldState&) = delete;
	void  operator=(const VisitBankAndDepositGoldState&) = delete;

	static VisitBankAndDepositGoldState& getInstance();

private:
	VisitBankAndDepositGoldState() {}

	// StateInterface
	virtual void enter(Miner* pEntity);
	virtual void execute(Miner* pEntity);
	virtual void exit(Miner* pEntity);
	// ~StateInterface
};

// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------
#endif // !VisitBankAndDepositGoldState_H