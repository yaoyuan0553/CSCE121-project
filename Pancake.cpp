

#include "Point.h"
#include "Graph.h"
#include "Pancake.h"
#include "std_lib_facilities_4.h"


namespace Graph_lib
{
	void Pancake::draw_lines() const
	{
		// fill (a pancake is prefilled)
		fl_color(236,162,77);		//fill brown-ish yellow
		fl_pie(point(0).x,point(0).y,w+w-1,h+h-1,0,360);
		fl_color(255,242,164);		//fill light yellow
		for (int i = 1; i < 20; ++i)
		// fill the color of the side of the pancake
		{
			fl_arc(point(0).x,point(0).y+i,w+w,h+h,180,360);
		}
		fl_color(color().as_int());		// reset color

		if (color().visibility()) {
			fl_color(color().as_int());		// by default black
			fl_arc(point(0).x,point(0).y,w+w,h+h,0,180);

			fl_color(180,83,38);			// brown-ish color
			fl_arc(point(0).x,point(0).y,w+w,h+h,180,360);

			fl_color(color().as_int());		// by default black
			fl_arc(point(0).x,point(0).y+20,w+w,h+h,180,360);

			// the two straight down lines for the height of the 'cylindrical' shaped pancakes
			fl_line(point(0).x,point(0).y+h,point(0).x,point(0).y+h+20);
			fl_line(point(0).x+w+w,point(0).y+h,point(0).x+w+w,point(0).y+h+20);
		}
	}
}