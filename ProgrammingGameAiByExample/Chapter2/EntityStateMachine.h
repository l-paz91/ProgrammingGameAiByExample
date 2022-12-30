// -----------------------------------------------------------------------------
#ifndef EntityStateMachine_H
#define EntityStateMachine_H
// -----------------------------------------------------------------------------

//--INCLUDES--//
#include <cassert>

#include "State.h"

// -----------------------------------------------------------------------------

template<typename T>
class EntityStateMachine
{
public:
	EntityStateMachine(T* pOwner)
		: mOwner(pOwner)
		, mCurrentState(nullptr)
		, mPreviousState(nullptr)
		, mGlobalState(nullptr)
	{}

	// use the methods to initialise the FSM
	void setCurrentState(StateInterface<T*> pState) { mCurrentState = pState; }
	void setPreviousState(StateInterface<T*> pState) { mPreviousState = pState; }
	void setGlobalState(StateInterface<T*> pState) { mGlobalState = pState; }

	// call to update the FSM
	void update() const 
	{
		if (mGlobalState)
		{
			mGlobalState->execute(mOwner);
		}

		if (mCurrentState)
		{
			mCurrentState->execute(mOwner);
		}
	}

	void changeState(StateInterface<T>* pNewState)
	{
		assert(pNewState && "EntityStateMachine::ChangeState() trying to change a null state");

		mPreviousState = mCurrentState;
		mCurrentState->exit(mOwner);
		mCurrentState = pNewState;
		mCurrentState->enter(mOwner);
	}

	void revertToPreviousState()
	{
		changeState(mPreviousState);
	}

	StateInterface<T>* getCurrentState() { return mCurrentState; }
	StateInterface<T>* getPreviousState() { return mPreviousState; }
	StateInterface<T>* getGlobalState() { return mGlobalState; }

	bool isInState(const StateInterface<T>& pState) const
	{
		return *mCurrentState == pState;
	}

private:
	T* mOwner;
	
	StateInterface<T>* mCurrentState;
	StateInterface<T>* mPreviousState;

	// this state logic is updated every time the FSM is updated
	StateInterface<T>* mGlobalState;

};

// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------
#endif // !EntityStateMachine_H