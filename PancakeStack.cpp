

#include "Point.h"
#include "Graph.h"
#include "PancakeStack.h"
#include "std_lib_facilities_4.h"


namespace Graph_lib
{
	bool PancakeStack::is_sorted()
	{
		vector<int> temp(s.begin(),s.begin()+n);		//temporary vector to store shuffled nums
		vector<int> orig = temp;				// original part of sizes, up to n numbers of it
		sort(temp.begin(),temp.end());			// sort and reverse temp
		reverse(temp.begin(),temp.end());		// reverse because a "perfect" stack is from the greatest to smallest
		if (orig == temp)
			return true;
		return false;
	}

	void PancakeStack::get_size()
	{
		s.clear();		//clear sizes to ensure it's empty everytime it's called
		vector<int> nums;
		for (int i = 1; i <= 9; ++i)
			nums.push_back(i);
		//make the random number different every time rand() is called
		random_shuffle(nums.begin(), nums.end());
		for (int i = 0; i < nums.size(); ++i)
		{
			s.push_back(nums[i]);				//s is sizes
		}
		if (is_sorted())
			get_size();
	}

	void PancakeStack::stack_pancake()
	// stack pancakes from bottom to top
	{
		get_size();
		if (p.size() != 0) {
			for (int i = 0; i < p.size(); ++i)
			{
				delete p[i];		//delete every Pancake object p[i] points to, preventing memory leak
			}
			p.clear();				//clear the vector preparing for a new stack
		}
		for (int i = 0; i < n; ++i)
		{
			p.push_back(new Pancake(Point(c.x,c.y),s[i]));	//create the pancakes at one same center
			p[i]->move(0,-21*i);		//move each pancake 21 pixels up from the previous one
		}
	}

	void PancakeStack::set_difficulty(Difficulty d)
	{
		n = d;		//n is difficulty
		stack_pancake();		//restack
	}
	
	void PancakeStack::draw_lines() const
	{
		for (int i=0; i < p.size(); ++i)
		{
			p[i]->draw_lines();			//use pancake's drawlines to draw each one
		}
	}

	void PancakeStack::flip(int pn)
	/* pn is a number from 0 to 9. The bottom pancake is 0 with
	an increment of 1 going up in order */
	{
		int d = p.size()-1-pn;		//difference/2
		for (int i = p.size()-1; i >= pn; --i)
		{
			p[i]->move(0,21*(d-2*(p.size()-1-i)));
		}
		reverse(p.begin()+pn, p.begin()+p.size());
		// reverse the order of pointers so it can still be drawn from bottom to top
		reverse(s.begin()+pn, s.begin()+p.size());	//reverse size vector as well for later use
	}
}