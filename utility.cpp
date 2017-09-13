#include "utility.h"
#include <iostream>
using std::cout;
using std::endl;
using std::cin;
using std::flush;

bool user_says_yes()
{
	int c;
	bool initial_reponse = true;

	do {
		if (initial_reponse)
			cout << "(y,n)? " << flush;
		else
			cout << "Respond with either y or n: " << flush;

		do{
			c = cin.get();
		} while (c == '\n' || c == ' ' || c == '\t');

		initial_reponse = false;
	} while (c != 'Y' && c != 'y' && c != 'n' && c != 'N');

	return (c == 'y' || c == 'Y');
}
