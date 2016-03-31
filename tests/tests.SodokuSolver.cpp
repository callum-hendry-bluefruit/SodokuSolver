#include "..\source\SodokuSolver.h"
#include "gtest/gtest.h"
#include <cassert>
#include <iostream>

TEST(testHiker, answer_test)
{
	EXPECT_EQ(42, answer());
}

TEST(testSodokuSolver, initalise_a_9x9_2d_vector)
{
	SodokuSolverClass initaliseVectorInstance;
	initaliseVectorInstance.m_initSodokuGrid();

	std::array<std::array<int, 9>, 9> example_array = { {
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		} };

	EXPECT_EQ(example_array, initaliseVectorInstance.m_sodoku_grid);
}

TEST(testSodokuSolver, set_m_sodoku_grid_to_mock_CSV_file)
{
	SodokuSolverClass readMockCSV;

	std::array<std::array<int, 9>, 9> example_CSV_file = { {
		{ 0, 0, 7, 0, 0, 1, 3, 0, 0 },
		{ 3, 0, 0, 0, 5, 0, 6, 0, 0 },
		{ 5, 0, 8, 0, 3, 0, 0, 0, 4 },
		{ 0, 8, 0, 0, 6, 0, 9, 0, 0 },
		{ 7, 0, 0, 0, 0, 0, 0, 0, 6 },
		{ 0, 0, 4, 0, 1, 0, 0, 7, 0 },
		{ 2, 0, 0, 0, 8, 0, 4, 0, 3 },
		{ 0, 0, 6, 0, 7, 0, 0, 0, 8 },
		{ 0, 0, 5, 9, 0, 0, 7, 0, 0 },
		} };

	readMockCSV.m_mock_read_csv(example_CSV_file);

	EXPECT_EQ(example_CSV_file, readMockCSV.m_sodoku_grid);
}

TEST(testSodokuSolver, initalise_or_reset_values_of_possible_number_array)
{
	SodokuSolverClass initOrResetPossibleNumberArray;
	initOrResetPossibleNumberArray.m_init_or_reset_possible_number_array();

	std::array<int, 9> expected_possible_numbers_array = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	EXPECT_EQ(expected_possible_numbers_array, initOrResetPossibleNumberArray.m_possible_numbers);
}

TEST(testSodokuSolver, remove_numbers_from_array_based_on_first_row_of_m_sodoku_grid_after_copying_CSV_values)
{
	SodokuSolverClass removeNumbers;

	std::array<std::array<int, 9>, 9> example_CSV_file = { {
		{ 0, 0, 7, 0, 0, 1, 3, 0, 0 },
		{ 3, 0, 0, 0, 5, 0, 6, 0, 0 },
		{ 5, 0, 8, 0, 3, 0, 0, 0, 4 },
		{ 0, 8, 0, 0, 6, 0, 9, 0, 0 },
		{ 7, 0, 0, 0, 0, 0, 0, 0, 6 },
		{ 0, 0, 4, 0, 1, 0, 0, 7, 0 },
		{ 2, 0, 0, 0, 8, 0, 4, 0, 3 },
		{ 0, 0, 6, 0, 7, 0, 0, 0, 8 },
		{ 0, 0, 5, 9, 0, 0, 7, 0, 0 },
		} };

	std::array<int, 9> expected_possible_numbers_array = { 0, 2, 0, 4, 5, 6, 0, 8, 9 };

	removeNumbers.m_initSodokuGrid();
	removeNumbers.m_mock_read_csv(example_CSV_file);
	removeNumbers.m_init_or_reset_possible_number_array();
	removeNumbers.m_remove_possible_numbers_by_row(0);

	EXPECT_EQ(expected_possible_numbers_array, removeNumbers.m_possible_numbers);
}

TEST(testSodokuSolver, remove_numbers_from_array_based_on_first_column_of_m_sodoku_grid_after_copying_CSV_values)
{
	SodokuSolverClass removeNumbers;

	std::array<std::array<int, 9>, 9> example_CSV_file = { {
		{ 0, 0, 7, 0, 0, 1, 3, 0, 0 },
		{ 3, 0, 0, 0, 5, 0, 6, 0, 0 },
		{ 5, 0, 8, 0, 3, 0, 0, 0, 4 },
		{ 0, 8, 0, 0, 6, 0, 9, 0, 0 },
		{ 7, 0, 0, 0, 0, 0, 0, 0, 6 },
		{ 0, 0, 4, 0, 1, 0, 0, 7, 0 },
		{ 2, 0, 0, 0, 8, 0, 4, 0, 3 },
		{ 0, 0, 6, 0, 7, 0, 0, 0, 8 },
		{ 0, 0, 5, 9, 0, 0, 7, 0, 0 },
		} };

	std::array<int, 9> expected_possible_numbers_array = { 1, 0, 0, 4, 0, 6, 0, 8, 9 };

	removeNumbers.m_initSodokuGrid();
	removeNumbers.m_mock_read_csv(example_CSV_file);
	removeNumbers.m_init_or_reset_possible_number_array();
	removeNumbers.m_remove_possible_numbers_by_column(0);

	EXPECT_EQ(expected_possible_numbers_array, removeNumbers.m_possible_numbers);
}

TEST(testSodokuSolver, remove_numbers_from_array_based_on_first_row_and_column_of_sodoku_grid)
{
	SodokuSolverClass removeNumbers;

	std::array<std::array<int, 9>, 9> example_CSV_file = { {
		{ 0, 0, 7, 0, 0, 1, 3, 0, 0 },
		{ 3, 0, 0, 0, 5, 0, 6, 0, 0 },
		{ 5, 0, 8, 0, 3, 0, 0, 0, 4 },
		{ 0, 8, 0, 0, 6, 0, 9, 0, 0 },
		{ 7, 0, 0, 0, 0, 0, 0, 0, 6 },
		{ 0, 0, 4, 0, 1, 0, 0, 7, 0 },
		{ 2, 0, 0, 0, 8, 0, 4, 0, 3 },
		{ 0, 0, 6, 0, 7, 0, 0, 0, 8 },
		{ 0, 0, 5, 9, 0, 0, 7, 0, 0 },
		} };

	std::array<int, 9> expected_possible_numbers_array = { 0, 0, 0, 4, 0, 6, 0, 8, 9 };

	removeNumbers.m_initSodokuGrid();
	removeNumbers.m_mock_read_csv(example_CSV_file);

	removeNumbers.m_init_or_reset_possible_number_array();
	removeNumbers.m_remove_possible_numbers_by_row(0);
	removeNumbers.m_remove_possible_numbers_by_column(0);

	EXPECT_EQ(expected_possible_numbers_array, removeNumbers.m_possible_numbers);
}

TEST(testSodokuSolver, remove_possible_numbers_based_on_3x3_grids_in_sodoku_grid)
{
	SodokuSolverClass removeNumbers;

	std::array<std::array<int, 9>, 9> example_CSV_file = { {
		{ 0, 0, 7, 0, 0, 1, 3, 0, 0 },
		{ 3, 0, 0, 0, 5, 0, 6, 0, 0 },
		{ 5, 0, 8, 0, 3, 0, 0, 0, 4 },
		{ 0, 8, 0, 0, 6, 0, 9, 0, 0 },
		{ 7, 0, 0, 0, 0, 0, 0, 0, 6 },
		{ 0, 0, 4, 0, 1, 0, 0, 7, 0 },
		{ 2, 0, 0, 0, 8, 0, 4, 0, 3 },
		{ 0, 0, 6, 0, 7, 0, 0, 0, 8 },
		{ 0, 0, 5, 9, 0, 0, 7, 0, 0 },
		} };

	std::array<int, 9> expected_possible_numbers_array = { 0, 0, 0, 4, 0, 6, 0, 0, 9 };

	EXPECT_EQ(expected_possible_numbers_array, removeNumbers.m_possible_numbers);
}