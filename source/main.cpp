#include <iostream>
#include <string>

#include "SodokuSolver.h"

using namespace ::std;

int main()
{
	string s;

	SodokuSolverClass startUpProgram;

	std::array<std::array<int, 9>, 9> mock_csv = { {
		{ 1, 0, 0, /**/ 0, 0, 7, /**/ 0, 9, 0 },
		{ 0, 3, 0, /**/ 0, 2, 0, /**/ 0, 0, 8 },
		{ 0, 0, 9, /**/ 6, 0, 0, /**/ 5, 0, 0 },

		{ 0, 0, 5, /**/ 3, 0, 0, /**/ 9, 0, 0 },
		{ 0, 1, 0, /**/ 0, 8, 0, /**/ 0, 0, 0 },
		{ 6, 0, 0, /**/ 0, 0, 4, /**/ 0, 0, 2 },

		{ 3, 0, 0, /**/ 0, 0, 0, /**/ 0, 1, 0 },
		{ 0, 4, 0, /**/ 0, 0, 0, /**/ 0, 0, 0 },
		{ 0, 0, 7, /**/ 0, 0, 0, /**/ 3, 0, 7 },
		} };

	startUpProgram.m_boot(true, mock_csv, false);

	cin >> s;
	return 0;
}