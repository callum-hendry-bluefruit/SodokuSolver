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
	initaliseVectorInstance.initSodokuGrid();

	std::array<std::array<int, 9>, 9> example_array = { {
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		} };

	EXPECT_EQ(example_array, initaliseVectorInstance.sodoku_grid);
}