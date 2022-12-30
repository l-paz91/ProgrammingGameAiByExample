
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
#include "Chapter2/MinersWife.h"

#include "std_lib_facilities.h"

// -----------------------------------------------------------------------------

void project1()
{
	Miner miner(PlayerEntities::eMINER_BOB);

	// simply run the miner through a few update calls
	for (int i = 0; i < 20; ++i)
	{
		miner.update();
		Sleep(500);
	}
}

// -----------------------------------------------------------------------------

void project2()
{
	Miner miner(PlayerEntities::eMINER_BOB);
	MinersWife elsa(PlayerEntities::eELSA);

	// simply run the miner through a few update calls
	for (int i = 0; i < 20; ++i)
	{
		//miner.update();
		elsa.update();
		Sleep(500);
	}
}

// -----------------------------------------------------------------------------

int main()
{
	project2();

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