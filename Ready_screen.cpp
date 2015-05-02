

#include "Ready_screen.h"

using namespace Graph_lib;

Ready_screen::Ready_screen(Point xy, int w, int h, const string& title):
	Window(xy,w,h,title),
	go_bool(false),
	go_button(Point(417,192),156,35,"Go!",
	[](Address, Address pw) {reference_to<Ready_screen>(pw).go_pressed();}),
	name_box(Point(336,70),243,51,"Please enter your name:"),
	difficulty_out(Point(336,190),42,43, "Difficulty level:"),
	level_menu1(Point(105,347),161,33,Menu::horizontal,"Difficulty Levels"),
	level_menu2(Point(105,391),161,33,Menu::horizontal, "Difficulty Levels"),
	level_menu3(Point(186,438),162,33,Menu::horizontal, "Difficulty levels"),
	d(PancakeStack::Difficulty::medium)			//default medium level
{
	get_images();
	attach(go_button);
	attach(name_box);
	attach(difficulty_out);
	attach_levels();		//create and attach level_menu1/2 's buttons
}

Ready_screen::~Ready_screen()
{
	for (int i = 0; i < background.size(); ++i)
		delete background[i];
}

void Ready_screen::attach_levels()
{
		
	level_menu1.attach(new Button(Point(0,0),0,0,"noob(2)",
		[](Address, Address pw){reference_to<Ready_screen>(pw).set_difficulty(PancakeStack::Difficulty::noob);}));
	level_menu1.attach(new Button(Point(0,0),0,0,"easy(3)",
		[](Address, Address pw){reference_to<Ready_screen>(pw).set_difficulty(PancakeStack::Difficulty::easy);}));
	level_menu1.attach(new Button(Point(0,0),0,0,"medium(4)",
		[](Address, Address pw){reference_to<Ready_screen>(pw).set_difficulty(PancakeStack::Difficulty::medium);}));
	level_menu2.attach(new Button(Point(0,0),0,0,"hard(5)",
		[](Address, Address pw){reference_to<Ready_screen>(pw).set_difficulty(PancakeStack::Difficulty::hard);}));
	level_menu2.attach(new Button(Point(0,0),0,0,"advanced(6)",
		[](Address, Address pw){reference_to<Ready_screen>(pw).set_difficulty(PancakeStack::Difficulty::advanced);}));
	level_menu2.attach(new Button(Point(0,0),0,0,"expert(7)",
		[](Address, Address pw){reference_to<Ready_screen>(pw).set_difficulty(PancakeStack::Difficulty::expert);}));
	level_menu3.attach(new Button(Point(0,0),0,0,"extreme(8)",
		[](Address, Address pw){reference_to<Ready_screen>(pw).set_difficulty(PancakeStack::Difficulty::extreme);}));
	level_menu3.attach(new Button(Point(0,0),0,0,"Chuck Norris(9)",
		[](Address, Address pw){reference_to<Ready_screen>(pw).set_difficulty(PancakeStack::Difficulty::chuck_norris);}));
	attach(level_menu1);
	attach(level_menu2);
	attach(level_menu3);
}

void Ready_screen::get_images()
{
	background.push_back(new Image(Point(0,0),"gamestart-00.jpg"));
	background.push_back(new Image(Point(336,0),"gamestart-336x.jpg"));
	background.push_back(new Image(Point(336,120),"gamestart-336x120.jpg"));
	background.push_back(new Image(Point(336,232),"gamestart-336x233.jpg"));
	background.push_back(new Image(Point(378,188),"gamestart-380x190.jpg"));
	background.push_back(new Image(Point(578,70),"gamestart-578x70.jpg"));
	//attach all of them
	for (int i = 0; i < background.size(); ++i)
		attach(*background[i]);
}

void Ready_screen::set_difficulty(PancakeStack::Difficulty dd)
{
	d = dd;
	stringstream ss;
	ss << dd;
	difficulty_out.put(ss.str());
}

void Ready_screen::go_pressed()
{
	hide();
	go_bool = true;
}

bool Ready_screen::wait_for_button()
{
	show();
	go_bool = false;

#if 1
	while (!go_bool) Fl::wait();
	Fl::redraw();

#else
	Fl::run();
#endif
	return go_bool;
}

