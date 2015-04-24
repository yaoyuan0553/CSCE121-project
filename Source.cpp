


#include "PancakeStack.h"
#include "Base_screen.h"
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
			Game_screen win2(Point(100,100),xmax,ymax,"Game");
			win2.wait_for_button();
			if (win2.game_quit())
			{
				string name = win2.player_name();
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

void print_vector(const vector<int>& v)
{
	for (int i = 0; i < v.size(); ++i)
	{
		cout << ' ' << v[i] << endl;
	}
	cout << "----------------------------------------------------\n";
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