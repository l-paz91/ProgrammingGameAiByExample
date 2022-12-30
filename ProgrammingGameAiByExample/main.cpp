
// -----------------------------------------------------------------------------
// https://lptcp.blogspot.com/
// 
/*
	Chapter 2 - The West World Project

	

*/
// https://github.com/l-paz91/ProgrammingGameAiByExample
// -----------------------------------------------------------------------------

//--INCLUDES--//
#include "Chapter2/BaseGameEntityMkII.h"
#include "Chapter2/UniqueIdManager.h"

#include "std_lib_facilities.h"

// -----------------------------------------------------------------------------

void fct()
{
	for (int i = 0; i < 10; ++i)
	{
		int id = UniqueIdManager::getUniqueID();
		cout << "Id" << i << ": " << id << '\n';
	}

	BaseGameEntityMkII ref;
}

// -----------------------------------------------------------------------------

int main()
{
	fct();

	cout << "\n\n";
	cin.clear();
	cout << "Press any key to continue\n";
	_getch();
	_CrtDumpMemoryLeaks();
	return 0;
}

// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------