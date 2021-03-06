


#include "PancakeStack.h"
#include "Base_screen.h"
#include "Ready_screen.h"
#include "Game_screen.h"
#include "Splash_screen.h"
#include "Scoreboard.h"
#include "find_solution.h"

using namespace Graph_lib;

const int xmax = 700;
const int xmid = 700/2;
const int ymax = 500;

void game_assembler()		//assemble all the windows together
{
	Splash_screen win0(Point(100,100),xmax,ymax,"Pancakepro");
	win0.wait_for_button();
	Base_screen win1(Point(100,100),xmax,ymax,"Main Menu");

	if (win0.continue_button_pushed())
	{
		win1.wait_for_button();
		if (win1.start_button_pushed())
		{
			win1.hide();
			Ready_screen winr(Point(100,100),xmax,ymax,"Ready");
			winr.wait_for_button();
			if (winr.go_pushed())
			{
				PancakeStack::Difficulty d = winr.difficulty_level();
				string name = winr.player_name();
				Game_screen win2(Point(100,100),xmax,ymax,"Game",d);
				win2.wait_for_button();
				if (win2.game_quit())
				{
					int score = win2.player_score();
					Scoreboard win3(Point(100,100),xmax,ymax, Record(name,score));
					win3.wait_for_button();
					if (win3.quit_button_pushed())
					{
						game_assembler();		//recursion, go back to splash screen
					}
				}
			}
		}
	}
}

int main()
try{
	srand(time(0));
	game_assembler();

}
catch(exception& e){
	cerr << "exception: " << e.what() << endl;
	return 1;
}
catch(...){
	cerr << "Some exception" << endl;
	return 2;
}