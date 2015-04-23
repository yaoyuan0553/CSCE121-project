

#ifndef SPLASH_SCREEN_GUARD
#define SPLASH_SCREEN_GAURD 1

#include "GUI.h"
#include "std_lib_facilities_4.h"
#include "Window.h"


using namespace Graph_lib;

struct Splash_screen: Graph_lib::Window{

	Splash_screen(Point xy, int w, int h, const string& title);
	bool wait_for_button();
	bool continue_button_pushed()  { return continue_bool;}

private:
	
	bool continue_bool;			//indicates whether continue button is pushed
	void continue_pressed() { hide(); continue_bool = true;}

	Image background;

	Button continue_button;

};



#endif