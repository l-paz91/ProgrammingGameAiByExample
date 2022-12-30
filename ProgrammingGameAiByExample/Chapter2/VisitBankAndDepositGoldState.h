// -----------------------------------------------------------------------------
#ifndef VisitBankAndDepositGoldState_H
#define VisitBankAndDepositGoldState_H
// -----------------------------------------------------------------------------

//--INCLUDES--//
#include "State.h"

class BaseGameEntityMkII;

// -----------------------------------------------------------------------------

class VisitBankAndDepositGoldState
	: public StateInterface<BaseGameEntityMkII>
{
public:
	VisitBankAndDepositGoldState(const VisitBankAndDepositGoldState&) = delete;
	void  operator=(const VisitBankAndDepositGoldState&) = delete;

	static VisitBankAndDepositGoldState& getInstance();

private:
	VisitBankAndDepositGoldState() {}

	// StateInterface
	virtual void enter(BaseGameEntityMkII* pEntity);
	virtual void execute(BaseGameEntityMkII* pEntity);
	virtual void exit(BaseGameEntityMkII* pEntity);
	// ~StateInterface
};

// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------
#endif // !VisitBankAndDepositGoldState_H