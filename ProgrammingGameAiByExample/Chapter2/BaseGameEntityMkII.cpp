// -----------------------------------------------------------------------------

//--INCLUDES--//
#include <cassert>
#include <iostream>

#include "UniqueIdManager.h"

#include "BaseGameEntityMkII.h"

// -----------------------------------------------------------------------------

BaseGameEntityMkII::BaseGameEntityMkII()
	: mStateMachine(new EntityStateMachine<BaseGameEntityMkII>(this))
	, mID(UniqueIdManager::getUniqueID())
{
}

// -----------------------------------------------------------------------------

BaseGameEntityMkII::~BaseGameEntityMkII()
{
	if (mStateMachine)
	{
		delete mStateMachine;
	}
}

// -----------------------------------------------------------------------------

void BaseGameEntityMkII::update()
{
	mStateMachine->update();
}

// -----------------------------------------------------------------------------

EntityStateMachine<BaseGameEntityMkII>* BaseGameEntityMkII::getStateMachine() const
{
	return mStateMachine;
}

// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------