// -----------------------------------------------------------------------------
#ifndef UniqueIdManager_H
#define UniqueIdManager_H
// -----------------------------------------------------------------------------

//--INCLUDES--//

// -----------------------------------------------------------------------------

class UniqueIdManager
{
public:
	UniqueIdManager(const UniqueIdManager&) = delete;
	void  operator=(const UniqueIdManager&) = delete;

	static int getUniqueID()
	{
		int& ref = getInstance().mNextValidID;
		return ++ref;
	}

private:
	UniqueIdManager() : mNextValidID(0) {}

	static UniqueIdManager& getInstance()
	{
		static UniqueIdManager instance;
		return instance;
	}

	int mNextValidID;
};

// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------
#endif // !UniqueIdManager_H