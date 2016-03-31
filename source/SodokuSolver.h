#ifndef SODOKUSOLVER_INCLUDED
#define SODOKUSOLVER_INCLUDED

#include <vector>
#include <array>
#include <cassert>
#include <iostream>

int answer();

class SodokuSolverClass
{
public:
	void m_boot();

	std::array<std::array<int, 9>,9> m_sodoku_grid;

	void m_initSodokuGrid();
	void m_mock_read_csv(std::array<std::array<int, 9>, 9>);

	void m_init_or_reset_possible_number_array();
	std::array<int, 9> m_possible_numbers;

	void m_remove_possible_numbers_by_row(int);
	void m_remove_possible_numbers_by_column(int);
};



#endif