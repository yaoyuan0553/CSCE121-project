

#include "Base_screen.h"



using namespace Graph_lib;

//initiate all private variables
Base_screen::Base_screen(Point xy, int w, int h, const string& title):
	Window(xy, w, h, title),
	//pcks(Point(w/2,h-50)),
	back_button(Point(555,455),100,25,"Back",
	[](Address, Address pw) { reference_to<Base_screen>(pw).back_pressed();}),
	start_button(Point(275,125),165,45,"New Game",
	[](Address, Address pw) {reference_to<Base_screen>(pw).start_pressed();}),
	hc_button(Point(275,225),165,45,"Credits/Help",
	[](Address, Address pw) {reference_to<Base_screen>(pw).hc_pressed();}),
	exit_button(Point(275,325),165,45,"Exit",
	[](Address, Address pw) {reference_to<Base_screen>(pw).exit_pressed();}),
	main_background(Point(0,0),"pancakepro-menu.jpg"),
	hc_background(Point(0,0),"pancakepro-credits.jpg"),
	start_pushed(false)

{   // attach hc_screen
	attach(back_button);
	attach(hc_background);
	// hide buttons aren't for main menu
}



void Base_screen::main_show()
{
	attach(start_button);
	attach(hc_button);
	attach(exit_button);
	attach(main_background);
}

void Base_screen::main_hide()
{
	detach(main_background);
	detach(start_button);
	detach(hc_button);
	detach(exit_button);
}

void Base_screen::hc_show()
{
	back_button.show();
	attach(hc_background);
}

void Base_screen::other_hide()
{
	back_button.hide();
	detach(hc_background);
}

bool Base_screen::wait_for_button()
{
	show();
	start_pushed = false;
#if 1
	while (!start_pushed) Fl::wait();
	Fl::redraw();
#else
	Fl::run();
#endif
	return start_pushed;
}