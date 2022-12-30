// -----------------------------------------------------------------------------
#ifndef BaseGameEntityMkII_H
#define BaseGameEntityMkII_H
// -----------------------------------------------------------------------------

//--INCLUDES--//
#include "BaseObject.h"
#include "EntityStateMachine.h"
#include "State.h"

// -----------------------------------------------------------------------------

class BaseGameEntityMkII
	: public BaseObjectInterface
{
public:
	BaseGameEntityMkII();
	virtual ~BaseGameEntityMkII();

	virtual void update() override;

	EntityStateMachine<BaseGameEntityMkII>* getStateMachine() const;

private:
	EntityStateMachine<BaseGameEntityMkII>* mStateMachine;

	int mID;
};

// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------
#endif // !BaseGameEntityMkII_H