
#include "std_lib_facilities_4.h"
#include "Base_screen.h"
#include "Game_screen.h"
#include "PancakeStack.h"


using namespace Graph_lib;

const int xmax = 700;
const int ymax = 500;
const int xmid = xmax/2;


int main()
try{
	srand(time(0));
	Base_screen win1(Point(100,100),700,500,"test1");
	win1.subtitle.set_font(FL_TIMES_BOLD);
	win1.subtitle.set_font_size(20);
	const int xmid = 700/2;
	const int ymax = 500;
	//PancakeStack pck(Point(xmid,ymax-50));
	//win1.attach(pck);
	win1.wait_for_button();
	Game_screen win2(Point(100,100),700,500,"test2");
	if (win1.start_button_pushed())
	{
		win1.hide();
		win2.wait_for_button();
	}

}
catch(exception& e){
	cerr << "exception: " << e.what() << endl;
	return 1;
}
catch(...){
	cerr << "Some exception" << endl;
	return 2;
}