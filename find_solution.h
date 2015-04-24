//find_solution.h

//Input: A vector<int> representing a stack of n pancakes numbered 1 to n in
//	any order, with the top pancake in element [0]; 2 <= n <= 9.

//Output: If the input argument is invalid, return nullptr;
//	otherwise, return a vector<int>*, where the vector<int> contains the
//	sequence of flips to put the stack of pancakes into order.  For example,
//	if the input is {4,1,2,3}, meaning the top pancake is 4, the output will
//	be a pointer to {4,3}, meaning flip the top 4 (giving {3,2,1,4}) and then
//	flip the top 3 (giving {1,2,3,4}).  The size of the vector is 2, which is
//	the minimum number of flips to put the pancakes in order.  This minimum is
//	to be used in the scoring function, and to determine when to stop the game
//	for too many flips.

#ifndef FIND_SOLUTION_GUARD
#define FIND_SOLUTION_GUARD 1

vector<int> *find_solution(const vector<int>& pancakes);

#endif