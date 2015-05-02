

#ifndef READY_SCREEN_GUARD
#define READY_SCREEN_GUARD

#include "PancakeStack.h"
#include "Graph.h"
#include "Window.h"
#include "GUI.h"
#include "std_lib_facilities_4.h"

using namespace Graph_lib;

struct Ready_screen: Graph_lib::Window{

	Ready_screen(Point xy, int w, int h, const string& title);


	bool wait_for_button();
	bool go_pushed() const { return go_bool;}

	PancakeStack::Difficulty difficulty_level() const { return d;}
	string player_name() { return name_box.get_string();}

	~Ready_screen();
	
private:
	// outputs
	bool go_bool;
	string name;
	PancakeStack::Difficulty d;

	In_box name_box;
	Out_box difficulty_out;		//display current difficulty level
	Button go_button;
	
	vector<Image*> background;	// all background images
	void get_images();		// initialize all image objects
	
	Menu level_menu1;		//first row
	Menu level_menu2;		//second row
	Menu level_menu3;		//third row
	void attach_levels();	//attach all level selectors


	void go_pressed();
	void set_difficulty(PancakeStack::Difficulty dd);		//control inversion of difficulty selector buttons

};



#endif
