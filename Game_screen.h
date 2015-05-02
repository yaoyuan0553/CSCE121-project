



#ifndef GAME_SCREEN_GUARD
#define GAME_SCREEN_GUARD 1


#include "PancakeStack.h"
#include "Graph.h"
#include "Window.h"
#include "GUI.h"
#include "std_lib_facilities_4.h"


using namespace Graph_lib;

struct Game_screen: Graph_lib::Window{

	Game_screen(Point xy, int w, int h, const string& title, PancakeStack::Difficulty dd);
	~Game_screen();		// deletes all pancake flipping buttons after out of scope

	bool wait_for_button();

	bool game_win() const { return win;}
	bool game_lose() const { return lose;}
	bool game_quit() const { return quit_pushed;}
	int player_score() const { return score;}

private:
						
	//---------------------------------------------------------------------------
	// for win screen
	vector<int> sorted;

	int steps;		//number of steps for the player to complete the game
	int score;		//player's final score
	int min_moves;

	Text congrats_text;
	Text gameover_text;

	Text final_score_text;
	Text step_text;
	Text score_text;
	Text continue_text;
	Text min_move_text;
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
	void get_buttons();		//initialize all buttons for game screen

	//----------------------------------------------------------------------------
	//control inversions

	void set_difficulty(PancakeStack::Difficulty dd);		//control inversion of difficulty selector buttons

	void quit_pressed() { hide(); quit_pushed = true; }
	void button_pressed(int i);		// actions for pancakes flip buttons
	void win_check();		// check if the player has won
	void score_calc();		// calculate player's final score

	void game_show();		//show game screen
	
	void sorted_pcks();		// order of sorted pancakes

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