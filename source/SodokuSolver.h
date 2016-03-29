#ifndef SODOKUSOLVER_INCLUDED
#define SODOKUSOLVER_INCLUDED

#include <vector>
#include <array>

int answer();

class SodokuSolverClass
{
public:
	std::array<std::array<int, 9>,9> sodoku_grid;
	void initSodokuGrid();
};

#endif