#include <iostream>

using namespace std;

/* 
Instructions are on the assignment page.

Example input:
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 0 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1

Evaluates to false, since for all x, for all y, for all z, is not satisfied (the one zero in the input string when x=2, y=0, z=3)

Example input: 
1 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0

Evaluates to true, since for all x, there exists a y, there exists a z is satisfied:
Characters 4-19 represents x=0, and there is the single 1 that satisfies it (when y=0 and z=1).
Characters 20-35 represents x=1, and there is the single 1 that satisfies it (when y=3 and z=2).
Characters 36-51 represents x=2, and there is the single 1 that satisfies it (when y=1 and z=3).
Characters 52-67 represents x=3, and there is the single 1 that satisfies it (when y=3 and z=1).
*/

bool quantificationalSolver(bool data[4][4][4], bool quants[3]) {
}

int main(int argc, char* argv[]) {
	bool data[4][4][4];
	bool quantifiers[3];
	for (int i = 0; i < 3; i++) cin >> quantifiers[i];
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			for (int k = 0; k < 4; k++)
				cin >> data[i][j][k];
	cout << quantificationalSolver(data, quantifiers) << endl;
	return 0;
}