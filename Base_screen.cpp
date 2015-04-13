
#include "Base_screen.h"


using namespace Graph_lib;

//initiate all private variables
Base_screen::Base_screen(Point xy, int w, int h, const string& title):
	Window(xy, w, h, title),
	//pcks(Point(w/2,h-50)),
	background(Point(0,0),"Nothing.jpg"),
	back_button(Point(x_max()-80,y_max()-30),70,20,"Back",
	[](Address, Address pw) { reference_to<Base_screen>(pw).back_pressed();}),
	start_button(Point(x_max()/2-50,y_max()/5+20),100,20,"New Game",
	[](Address, Address pw) {reference_to<Base_screen>(pw).start_pressed();}),
	help_button(Point(x_max()/2-50,y_max()*2/5+20),100,20,"Help",
	[](Address, Address pw) {reference_to<Base_screen>(pw).help_pressed();}),
	credits_button(Point(x_max()/2-50,y_max()*3/5+20),100,20,"Credits",
	[](Address, Address pw) {reference_to<Base_screen>(pw).credits_pressed();}),
	exit_button(Point(x_max()/2-50,y_max()*4/5+20),100,20,"Exit",
	[](Address, Address pw) {reference_to<Base_screen>(pw).exit_pressed();}),
	subtitle(Point(x_max()/2-50,y_max()/5),"Credits"),
	name1(Point(x_max()/2-50,y_max()*2/5),"Gerardo Vazquez"),
	name2(Point(x_max()/2-50,y_max()*3/5),"Will Tallent"),
	name3(Point(x_max()/2-50,y_max()*4/5),"Yuan Yao"),
	is_attached(false),
	start_pushed(false)

{   // attach all the buttons
	attach(start_button);
	attach(help_button);
	attach(credits_button);
	attach(exit_button);
	attach(back_button);
	// hide buttons aren't for main menu
	back_button.hide();
}



void Base_screen::main_show()
{
	start_button.show();
	help_button.show();
	credits_button.show();
	exit_button.show();
}

void Base_screen::main_hide()
{
	start_button.hide();
	help_button.hide();
	credits_button.hide();
	exit_button.hide();
}

void Base_screen::credits_show()
{
	back_button.show();
	attach(subtitle);
	attach(name1);
	attach(name2);
	attach(name3);
	credits_attached();
}

void Base_screen::other_hide()
{
	back_button.hide();
	if (is_attached)
	{
		detach(name1);
		detach(name2);
		detach(name3);
		detach(subtitle);
	}
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