

#include "Splash_screen.h"

using namespace Graph_lib;

Splash_screen::Splash_screen(Point xy, int w, int h, const string& title):
	Window(xy, w, h, title),
	background(Point(0,0),"pancakepro.jpg"),
	continue_button(Point(0,0),x_max(),y_max()," ",
	[](Address, Address pw){reference_to<Splash_screen>(pw).continue_pressed();}),
	continue_bool(false)
{
	attach(background);
	attach(continue_button);
}

bool Splash_screen::wait_for_button()
{
	show();
	continue_bool = false;

#if 1
	while (!continue_button_pushed())
		Fl::wait();
	Fl::redraw();

#else
	Fl::run();

#endif
	return continue_bool;
}