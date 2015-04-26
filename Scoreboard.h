
/* 
	Scoreboard is a Window taking Record values from Game_screen
	then display them in Text form. It first reads the saved 
	Records from "Scoreboard.txt", then compare them with the new
	Record value it received from Game_screen and decide on whether
	it should replace the lowest score or not. At last it writes to
	the txt file and save it.
*/


#ifndef SCOREBOARD_GUARD
#define SCOREBOARD_GUARD 1

#include "Window.h"
#include "std_lib_facilities_4.h"
#include "Graph.h"
#include "GUI.h"
#include "Record.h"



using namespace Graph_lib;

struct Scoreboard: Graph_lib::Window{

	Scoreboard(Point xy, int w, int h, const Record& rr);

	bool wait_for_button();
	bool quit_button_pushed() { return quit_bool;}

	~Scoreboard();		// destructor, deallocate memory for all Text objects.

private:
	vector<Text*> text_names;		// names stored in Text
	vector<Text*> text_scores;		// scores stored in Text
	vector<Record> rcds;			// records
	Record r;						// the new record;

	Image background;
	ifstream file;

	Button quit_button;			// a button with the same size as the screen and quit once pressed
	bool quit_bool;
	void quit_pressed() { hide(); quit_bool = true;}

	void new_records();			// determines if the new record is a high score and re-arrange in order
	void text_records();		// convert the records to Text's and attach them

	static void cb_quit(Address, Address pw)
	{ reference_to<Scoreboard>(pw).quit_pressed(); } 

};


#endif