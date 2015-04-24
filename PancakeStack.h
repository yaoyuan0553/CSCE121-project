

#ifndef PANCAKESTACK_GUARD
#define PANCAKESTACK_GUARD 1


#include "Point.h"
#include "Graph.h"
#include "Pancake.h"
#include "std_lib_facilities_4.h"
#include "find_solution.h"

namespace Graph_lib
{
	struct PancakeStack: Shape{
		
		//set each difficulty level correspond to the number of pancakes
		enum Difficulty: unsigned char {
			noob = 2,
			easy = 3,
			medium = 4,
			hard = 5,
			advanced = 6,
			expert = 7,
			extreme = 8,
			chuck_norris = 9
		};

		PancakeStack(Point cc): 
			c(cc), n(advanced) { stack_pancake();}

		void set_difficulty(Difficulty d);

		void draw_lines() const;

		void flip(int pn);		// flip according to pancake numbers

		vector<int> sizes() const {return s;}
		vector<int> fixed_sizes() const;		//for find_solution
		int total_pancakes() const {return n;}

		int min_flip();		// minimum moves to complete a pancake game

	private:
		Point c;				//center of the first pancake (bottom one)
		vector<int> s;			//size (horizontal edge) of pancake(ellipse) assigned by get_size()
		vector<Pancake*> p;		//store pointers to Pancakes since Shape prevents copying
		int n;					//number of pancakes (difficulty)
		void get_size();		//assign w a size value
		void stack_pancake();
		bool is_sorted();		//checks if a stack is already a "perfect" stack before game starts, if true, re-shuffle until false
	};
}

#endif