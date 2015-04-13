



#ifndef BASE_SCREEN_GUARD
#define BASE_SCREEN_GUARD 1

#include "Window.h"
#include "Graph.h"
#include "PancakeStack.h"
#include "std_lib_facilities_4.h"
#include "GUI.h"


using namespace Graph_lib;

struct Base_screen: Graph_lib::Window{
	Base_screen(Point xy, int w, int h,	const string& title);

	//for credits screen
	Text subtitle;
	Text name1;
	Text name2;
	Text name3;
		
	bool wait_for_button();

	bool start_button_pushed() { return start_pushed;}	//indicates if a name is entered (optional)
													//and level is selected;
	//----------------------------------------------------------------------------

	//temporarily undefined due to the lack of 
	//support of universal initializer {} in VS2012


private:
	bool start_pushed;

	Image background;		//background 
	Button back_button;		//go back to main menu, not visible at main menu
		
	//buttons of main menu
	Button start_button;
	Button help_button;
	Button credits_button;
	Button exit_button;

	//----------------------------------------------------------------------------

	bool is_attached;		//check if the Texts for credits screen are attached
	//actions when buttons are pressed
	void back_pressed() { other_hide(); main_show();}
	void start_pressed() { hide(); start_pushed = true;}
	void exit_pressed() { hide();}
	void help_pressed() { }
	void credits_pressed() { main_hide(); credits_show();}

	void main_show();		//go back to main menu
	void main_hide();		//go to other screens
	void credits_show();	//credits screen
	void other_hide();		//hide everything else to go back to main menu
		
	void game_show();		//show game screen

	void credits_attached() { is_attached = true;}	
};


#endif