// -----------------------------------------------------------------------------
#ifndef BaseGameEntity_H
#define BaseGameEntity_H
// -----------------------------------------------------------------------------

//--INCLUDES--//

// -----------------------------------------------------------------------------

// (LP) TO-DO: Create a class that tracks and produces IDs
// Also add an UpdateInterface

class BaseGameEntity
{
public:
	BaseGameEntity(int pID)
	{
		setID(pID);
	}

	virtual ~BaseGameEntity() {}

	// all entities must implement an update function
	virtual void update() = 0;	// (LP) I don't like abstract classes with members

	int getID() const { return mID; }


private:
	// every entity has a unique ID number
	int mID;

	// this is the next valid ID. Each time a BaseGameEntity is instantiated this
	// value is updated
	static int mNextValidID;	// (LP) I don't like this

	// this is called within the constructor to make sure the ID is set correctly.
	// It verifies that the value passed to the method is greater or equal to the
	// next valid ID, before setting the ID and incrementing the next valid ID.
	// (LP) there should be a class that assigns you a valid ID instead
	void setID(int pValue);

};

// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------
#endif // !BaseGameEntity_H