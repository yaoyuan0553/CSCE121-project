



#ifndef GAME_SCREEN_GUARD
#define GAME_SCREEN_GUARD 1


#include "PancakeStack.h"
#include "Graph.h"
#include "Window.h"
#include "GUI.h"
#include "std_lib_facilities_4.h"


using namespace Graph_lib;

struct Game_screen: Graph_lib::Window{

	Game_screen(Point xy, int w, int h, const string& title);

	bool wait_for_button();

	bool game_win() const { return win;}
	bool game_lose() const { return lose;}
	bool game_quit() const { return quit_pushed;}
	int player_score() const { return score;}
	string player_name()  { return name_box.get_string();}

private:
						
	//---------------------------------------------------------------------------
	// for win screen
	int steps;		//number of steps for the player to complete the game
	int score;		//player's final score
	Text congrats_text;
	Text gameover_text;

	Text final_score_text;
	Text step_text;
	Text score_text;
	//---------------------------------------------------------------------------
	// for game screen
	PancakeStack pcks;
	PancakeStack::Difficulty difficulty_level;

	Image background;

	bool quit_pushed;		// default false, true if pushed
	bool win;				// false as default, true if won
	bool lose;				// false as default, true if lost
		
	Button quit_button;
	vector<Button*> pancake_buttons;	// store pancake seletors

	//----------------------------------------------------------------------------
	// for ready screen
	In_box name_box;
	Out_box difficulty_out;		//display current difficulty level
	Button go_button;
		
	Menu level_menu1;		//first row
	Menu level_menu2;		//second row

	//----------------------------------------------------------------------------
	void attach_levels();	//attach all levels to the screen
	void get_buttons();		//initialize all buttons for game screen

	//----------------------------------------------------------------------------
	//control inversions

	void set_difficulty(PancakeStack::Difficulty dd);		//control inversion of difficulty selector buttons
	void go_pressed() { ready_hide(); game_show();}	// control inversion of go_button

	void quit_pressed() { hide(); quit_pushed = true; }
	void button_pressed(int i);		// actions for pancakes flip buttons
	void win_check();		// check if the player has won
	void score_calc();		// calculate player's final score

	void ready_show();		//show ready screen
	void ready_hide();		//hide ready screen
	void game_show();		//show game screen
	void game_hide();		//hide game screen
		

	static void cb_pancake0(Address, Address pw)
	{ reference_to<Game_screen>(pw).button_pressed(0); }
	static void cb_pancake1(Address, Address pw)
	{ reference_to<Game_screen>(pw).button_pressed(1); }
	static void cb_pancake2(Address, Address pw)
	{ reference_to<Game_screen>(pw).button_pressed(2); }
	static void cb_pancake3(Address, Address pw)
	{ reference_to<Game_screen>(pw).button_pressed(3); }
	static void cb_pancake4(Address, Address pw)
	{ reference_to<Game_screen>(pw).button_pressed(4); }
	static void cb_pancake5(Address, Address pw)
	{ reference_to<Game_screen>(pw).button_pressed(5); }
	static void cb_pancake6(Address, Address pw)
	{ reference_to<Game_screen>(pw).button_pressed(6); }
	static void cb_pancake7(Address, Address pw)
	{ reference_to<Game_screen>(pw).button_pressed(7); }
	static void cb_pancake8(Address, Address pw)
	{ reference_to<Game_screen>(pw).button_pressed(8); }
};


#endif