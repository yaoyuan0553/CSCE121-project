

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

{   // attach all the buttons
	attach(start_button);
	attach(hc_button);
	attach(exit_button);
	attach(back_button);
	// hide buttons aren't for main menu
	back_button.hide();
}



void Base_screen::main_show()
{
	start_button.show();
	hc_button.show();
	exit_button.show();
	attach(main_background);
}

void Base_screen::main_hide()
{
	detach(main_background);
	start_button.hide();
	hc_button.hide();
	exit_button.hide();
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
	main_show();
	start_pushed = false;
#if 1
	while (!start_pushed) Fl::wait();
	Fl::redraw();
#else
	Fl::run();
#endif
	return start_pushed;
}