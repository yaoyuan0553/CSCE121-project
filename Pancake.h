


#ifndef PANCAKE_GUARD
#define PANCAKE_GUARD 1


#include "Point.h"
#include "Graph.h"
#include "std_lib_facilities_4.h"


namespace Graph_lib
{
	//a piece of pancake made of a ellipse, two straight lines and an arc line
	struct Pancake: Shape{
		Pancake(Point p, int sz)		// center and size
		:w(30*sz), s(sz), h(10+sz) { add(Point(p.x-w,p.y-h)); }

		void draw_lines() const;
		Point center() const { return Point(point(0).x+w,point(0).y+h);}
		int size() const { return s;}
		//void set_side_color(Color c);

	private:
		int w;		//width (changed in ratio by size)
		int s;		//size
		int h;		//height
	};
}
#endif