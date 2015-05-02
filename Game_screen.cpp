

#include "Game_screen.h"

using namespace Graph_lib;

Game_screen::Game_screen(Point xy, int w, int h, const string& title, PancakeStack::Difficulty dd):
	Window(xy, w, h, title), pcks(Point(x_max()/2,y_max()-100)),
	quit_button(Point(0,0),x_max(),y_max()," ",
	[](Address, Address pw) { reference_to<Game_screen>(pw).quit_pressed();}),
	steps(0),
	score(0),
	win(false),
	lose(false),
	difficulty_level(dd),		
	congrats_text(Point(220, 100),"Congratulations, You Win!"),
	gameover_text(Point(270,100),"Game Over"),
	final_score_text(Point(280,y_max()/5+30), "Your final score: "+ to_string(score)),
	score_text(Point(550,75), "Current Score: "+ to_string(100*difficulty_level)),
	step_text(Point(50,75),"Steps: 0"),
	continue_text(Point(245,460),"Press anywhere to continue"),
	min_move_text(Point(230,150),"This could be done in: "),
	background(Point(0,0),"pancakepro-pan.jpg")
{
	step_text.set_font(FL_TIMES_BOLD);
	step_text.set_font_size(25);
	pcks.set_difficulty(difficulty_level);
	game_show();		// show all objects on game screen
	sorted_pcks();		// calculate the sorted vector of pancakes
	continue_text.set_font_size(20);	continue_text.set_font(FL_TIMES_BOLD);
	continue_text.set_color(Color::white);
	min_moves = pcks.min_flip();
}

Game_screen::~Game_screen()
{
	for (int i=0; i < pancake_buttons.size(); ++i) {
		delete pancake_buttons[i];
	}
}

void Game_screen::get_buttons()
{
	pancake_buttons.push_back(new Button(Point(x_max()/2-pcks.sizes()[0]*25,y_max()-87-21*0),
			pcks.sizes()[0]*25*2,10+pcks.sizes()[0]," ", cb_pancake0));
	pancake_buttons.push_back(new Button(Point(x_max()/2-pcks.sizes()[1]*25,y_max()-87-21*1),
			pcks.sizes()[1]*25*2,10+pcks.sizes()[1]," ", cb_pancake1));
	pancake_buttons.push_back(new Button(Point(x_max()/2-pcks.sizes()[2]*25,y_max()-87-21*2),
			pcks.sizes()[2]*25*2,10+pcks.sizes()[2]," ", cb_pancake2));
	pancake_buttons.push_back(new Button(Point(x_max()/2-pcks.sizes()[3]*25,y_max()-87-21*3),
			pcks.sizes()[3]*25*2,10+pcks.sizes()[3]," ", cb_pancake3));
	pancake_buttons.push_back(new Button(Point(x_max()/2-pcks.sizes()[4]*25,y_max()-87-21*4),
			pcks.sizes()[4]*25*2,10+pcks.sizes()[4]," ", cb_pancake4));
	pancake_buttons.push_back(new Button(Point(x_max()/2-pcks.sizes()[5]*25,y_max()-87-21*5),
			pcks.sizes()[5]*25*2,10+pcks.sizes()[5]," ", cb_pancake5));
	pancake_buttons.push_back(new Button(Point(x_max()/2-pcks.sizes()[6]*25,y_max()-87-21*6),
			pcks.sizes()[6]*25*2,10+pcks.sizes()[6]," ", cb_pancake6));
	pancake_buttons.push_back(new Button(Point(x_max()/2-pcks.sizes()[7]*25,y_max()-87-21*7),
			pcks.sizes()[7]*25*2,10+pcks.sizes()[7]," ", cb_pancake7));
	pancake_buttons.push_back(new Button(Point(x_max()/2-pcks.sizes()[8]*25,y_max()-87-21*8),
			pcks.sizes()[8]*25*2,10+pcks.sizes()[8]," ", cb_pancake8));
}

	
void Game_screen::button_pressed(int i)
// actions when pancake flip buttons are pressed
{
	pcks.flip(i);
	//re-position and adjust the widths/heights of all buttons
	// so that they will still fit underneath different pancakes
	for (int j = 0; j < pcks.total_pancakes(); ++j) 
	{
		detach(*pancake_buttons[j]);
		pancake_buttons[j]->loc = Point(x_max()/2-pcks.sizes()[j]*25,y_max()-87-21*j);
		pancake_buttons[j]->width = pcks.sizes()[j]*25*2;
		pancake_buttons[j]->height = pcks.sizes()[j]/2+15;
		attach(*pancake_buttons[j]);
	}
	++steps;		//step plus one
	step_text.set_label("Steps: "+ to_string(steps));
	score_calc();
	score_text.set_label("Current Score: " + to_string(score));
	redraw();
	win_check();	//check for win every time buttons are pressed
	if (win || lose) {
		attach(quit_button);
		final_score_text.set_label("Your Score: " + to_string(score));
		min_move_text.set_label("This could be done in " + to_string(min_moves) + " steps");
		min_move_text.set_font_size(20);	min_move_text.set_font(FL_TIMES_BOLD);
		attach(final_score_text); attach(continue_text); attach(min_move_text);
	}
}

void Game_screen::sorted_pcks()
{
	vector<int> original;	//store the original sizes() vector
	for (int i = 0; i < pcks.total_pancakes(); ++i)
		original.push_back(pcks.sizes()[i]);
	sorted = original;
	sort(sorted.begin(), sorted.end());		// ascending order (top to bottom)
	reverse(sorted.begin(),sorted.end());	// descending order (bottom to top, the way we want)
}

void Game_screen::win_check()
{
	vector<int> original;	//store the original sizes() vector
	for (int i = 0; i < pcks.total_pancakes(); ++i) {
		original.push_back(pcks.sizes()[i]);
	}
	if (original == sorted && score >= 0) {		// if true, player wins, then detach all pancake buttons
		for (int k = 0; k < pcks.total_pancakes(); ++k)
			detach(*pancake_buttons[k]);
		win = true;
		attach(congrats_text);
		congrats_text.set_font_size(20);
		congrats_text.set_font(FL_TIMES_BOLD);
	}
	else if (score < 0) {			// player loses when their score is below 0. detach all pancake buttons
		for (int k = 0; k < pcks.total_pancakes(); ++k)
			detach(*pancake_buttons[k]);
		lose = true;
		attach(gameover_text);
		gameover_text.set_font_size(20);
		gameover_text.set_font(FL_TIMES_BOLD);
	}
}

void Game_screen::score_calc()
{
	if (steps <= min_moves)
		score = 100*difficulty_level;
	else if (steps > min_moves)
		score = (100-10*(steps-min_moves))*difficulty_level;
}

void Game_screen::game_show()
{
	get_buttons();			// buttons can only be set after difficulty is set, since difficulty decides the size of buttons
	score_text.set_label("Current Score: "+ to_string(100*difficulty_level));
	for (int i = 0; i < pcks.total_pancakes(); ++i)
		attach(*pancake_buttons[i]);
	attach(background);
	attach(step_text);
	attach(score_text);
	attach(pcks);
}

bool Game_screen::wait_for_button()
{
	show();
	quit_pushed = false;
	win = false;
	lose = false;
#if 1
	while (!quit_pushed) Fl::wait();
	Fl::redraw();
#else
	Fl::run();
#endif
	return quit_pushed;
}