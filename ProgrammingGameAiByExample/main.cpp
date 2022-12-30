
// -----------------------------------------------------------------------------
// https://lptcp.blogspot.com/
// 
/*
	Chapter 2 - The West World Project

	

*/
// https://github.com/l-paz91/ProgrammingGameAiByExample
// -----------------------------------------------------------------------------

//--INCLUDES--//
#include <windows.h>

#include "Chapter2/Miner.h"

#include "std_lib_facilities.h"

// -----------------------------------------------------------------------------

void fct()
{
	Miner miner(PlayerEntities::eMINER_BOB);

	// simply run the miner through a few update calls
	for (int i = 0; i < 20; ++i)
	{
		miner.update();
		Sleep(800);
	}
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