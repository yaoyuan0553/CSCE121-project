

#include "Game_screen.h"

using namespace Graph_lib;

Game_screen::Game_screen(Point xy, int w, int h, const string& title):
	Window(xy, w, h, title), pcks(Point(x_max()/2,y_max()-100)),
	quit_button(Point(x_max()-80,y_max()-30),70,20,"Quit",
	[](Address, Address pw) { reference_to<Game_screen>(pw).quit_pressed();}),
	go_button(Point(x_max()/2-75,y_max()*4/5),150,50,"Go!",
	[](Address, Address pw) {reference_to<Game_screen>(pw).go_pressed();}),
	name_box(Point(x_max()/2-100,y_max()/5),200,100,"Please enter your name:"),
	difficulty_out(Point(x_max()/2-100,y_max()*2/5),100,50, "Difficulty level:"),
	level_menu1(Point(50,y_max()*3/5),150,20,Menu::horizontal,"Difficulty Levels"),
	level_menu2(Point(50,y_max()*3/5+20),150,20,Menu::horizontal, "Difficulty Levels"),
	steps(0),
	score(0),
	win(false),
	lose(false),
	difficulty_level(PancakeStack::Difficulty::medium),		//default difficulty level
	congrats_text(Point(x_max()/5, y_max()/5),"Congratualations, You Win!"),
	score_text(Point(x_max()/5+30,y_max()/5+30), "Your score: "+ to_string(score)),
	background(Point(0,0),"pancakepro-pan.jpg")
{
	pcks.set_difficulty(difficulty_level);
	attach(pcks);
	attach(quit_button);
	attach(go_button);
	attach(name_box);
	attach(difficulty_out);
	attach_levels();		//create and attach level_menu1/2 's buttons
	game_hide();		// show ready screen contents first
}

void Game_screen::attach_levels()
{
		
	level_menu1.attach(new Button(Point(0,0),0,0,"noob(2)",
		[](Address, Address pw){reference_to<Game_screen>(pw).set_difficulty(PancakeStack::Difficulty::noob);}));
	level_menu1.attach(new Button(Point(0,0),0,0,"easy(3)",
		[](Address, Address pw){reference_to<Game_screen>(pw).set_difficulty(PancakeStack::Difficulty::easy);}));
	level_menu1.attach(new Button(Point(0,0),0,0,"medium(4)",
		[](Address, Address pw){reference_to<Game_screen>(pw).set_difficulty(PancakeStack::Difficulty::medium);}));
	level_menu1.attach(new Button(Point(0,0),0,0,"hard(5)",
		[](Address, Address pw){reference_to<Game_screen>(pw).set_difficulty(PancakeStack::Difficulty::hard);}));
	level_menu2.attach(new Button(Point(0,0),0,0,"advanced(6)",
		[](Address, Address pw){reference_to<Game_screen>(pw).set_difficulty(PancakeStack::Difficulty::advanced);}));
	level_menu2.attach(new Button(Point(0,0),0,0,"expert(7)",
		[](Address, Address pw){reference_to<Game_screen>(pw).set_difficulty(PancakeStack::Difficulty::expert);}));
	level_menu2.attach(new Button(Point(0,0),0,0,"extreme(8)",
		[](Address, Address pw){reference_to<Game_screen>(pw).set_difficulty(PancakeStack::Difficulty::extreme);}));
	level_menu2.attach(new Button(Point(0,0),0,0,"Chuck Norris(9)",
		[](Address, Address pw){reference_to<Game_screen>(pw).set_difficulty(PancakeStack::Difficulty::chuck_norris);}));
	attach(level_menu1);
	attach(level_menu2);
}

void Game_screen::get_buttons()
{
	int i = 0;
	pancake_buttons.push_back(new Button(Point(x_max()/2-pcks.sizes()[i]*25,y_max()-87-21*i),
			pcks.sizes()[i]*25*2,10+pcks.sizes()[i]," ", cb_pancake0));
	++i;		// 1
	pancake_buttons.push_back(new Button(Point(x_max()/2-pcks.sizes()[i]*25,y_max()-87-21*i),
			pcks.sizes()[i]*25*2,10+pcks.sizes()[i]," ", cb_pancake1));
	++i;		// 2
	pancake_buttons.push_back(new Button(Point(x_max()/2-pcks.sizes()[i]*25,y_max()-87-21*i),
			pcks.sizes()[i]*25*2,10+pcks.sizes()[i]," ", cb_pancake2));
	++i;		// 3
	pancake_buttons.push_back(new Button(Point(x_max()/2-pcks.sizes()[i]*25,y_max()-87-21*i),
			pcks.sizes()[i]*25*2,10+pcks.sizes()[i]," ", cb_pancake3));
	++i;		// 4
	pancake_buttons.push_back(new Button(Point(x_max()/2-pcks.sizes()[i]*25,y_max()-87-21*i),
			pcks.sizes()[i]*25*2,10+pcks.sizes()[i]," ", cb_pancake4));
	++i;		// 5
	pancake_buttons.push_back(new Button(Point(x_max()/2-pcks.sizes()[i]*25,y_max()-87-21*i),
			pcks.sizes()[i]*25*2,10+pcks.sizes()[i]," ", cb_pancake5));
	++i;		// 6
	pancake_buttons.push_back(new Button(Point(x_max()/2-pcks.sizes()[i]*25,y_max()-87-21*i),
			pcks.sizes()[i]*25*2,10+pcks.sizes()[i]," ", cb_pancake6));
	++i;		// 7
	pancake_buttons.push_back(new Button(Point(x_max()/2-pcks.sizes()[i]*25,y_max()-87-21*i),
			pcks.sizes()[i]*25*2,10+pcks.sizes()[i]," ", cb_pancake7));
	++i;		// 8
	pancake_buttons.push_back(new Button(Point(x_max()/2-pcks.sizes()[i]*25,y_max()-87-21*i),
			pcks.sizes()[i]*25*2,10+pcks.sizes()[i]," ", cb_pancake8));
	/*
	for (int i = 0; i < pcks.sizes().size(); ++i)
	{
		pancake_buttons.push_back(
			new Button(Point(x_max()/2-pcks.sizes()[i]*25,y_max()-100-21*i),
			pcks.sizes()[i]*25*2,10+pcks.sizes()[i]," ",
			[](Address, Address pw) { reference_to<Game_screen>(pw).button_pressed(i);}));
	}
	*/
}

void Game_screen::set_difficulty(PancakeStack::Difficulty d)
{
	difficulty_level = d;
	pcks.set_difficulty(difficulty_level);
	stringstream ss;
	ss << d;
	difficulty_out.put(ss.str());
	get_buttons();			// buttons can only be set after difficulty is set, since difficulty decides the size of buttons
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
		pancake_buttons[j]->height = pcks.sizes()[j]+10;
		attach(*pancake_buttons[j]);
	}
	redraw();
	++steps;		//step plus one
	win_check();	//check for win every time buttons are pressed
}

void Game_screen::win_check()
{
	vector<int> original;	//store the original sizes() vector
	vector<int> sorted;		//store sizes in another vector avoiding direct changes to sizes()
	for (int i = 0; i < pcks.total_pancakes(); ++i)
		original.push_back(pcks.sizes()[i]);
	sorted = original;
	sort(sorted.begin(), sorted.end());		// ascending order (top to bottom)
	reverse(sorted.begin(),sorted.end());	// descending order (bottom to top, the way we want)
	if (original == sorted) {		// if true, player wins, then detach all pancake buttons
		for (int k = 0; k < pcks.total_pancakes(); ++k)
			detach(*pancake_buttons[k]);
		attach(congrats_text);
		congrats_text.set_font_size(20);
		congrats_text.set_font(FL_TIMES_BOLD);
		score_text.set_label("Your Score: " + to_string(score));
		attach(score_text);
		win = true;
	}
}

void Game_screen::ready_show()
{
	go_button.show();
	difficulty_out.show();
	name_box.show();
	level_menu1.show();
	level_menu2.show();
}

void Game_screen::ready_hide()
{
	go_button.hide();
	difficulty_out.hide();
	name_box.hide();
	level_menu1.hide();
	level_menu2.hide();
}

void Game_screen::game_show()
{
	for (int i = 0; i < pcks.total_pancakes(); ++i)
		attach(*pancake_buttons[i]);
	quit_button.show();
	attach(background);
	attach(pcks);
}

void Game_screen::game_hide()
{
	quit_button.hide();
	detach(pcks);
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