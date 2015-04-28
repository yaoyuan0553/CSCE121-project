


#include "Scoreboard.h"

using namespace Graph_lib;


Scoreboard::Scoreboard(Point xy, int w, int h, const Record& rr):
	Window(xy, w, h, "Scoreboard"),
	file("Scoreboard.txt"), r(rr),
	background(Point(0,0),"pancakepro-hs.jpg"),
	rcds(5),			// Maximum only 5 records
	quit_button(Point(575,445),100,35," ",cb_quit),
	quit_bool(false)
{
	file >> rcds[0] >> rcds[1] >> rcds[2] >>
		rcds[3] >> rcds[4];			// read from file to assign every record
	file.close();				// close the file
	attach(background);			// attach background first
	text_records();
	attach(quit_button);
}

Scoreboard::~Scoreboard()
{
	for (int i=0; i < text_names.size(); ++i)
		delete text_names[i];
	for (int j=0; j < text_scores.size(); ++j)
		delete text_scores[j];
}

void Scoreboard::new_records()
// called by text_records()
{
	sort(rcds.begin(), rcds.end());		//sort records, low score to high score
	bool q = false;						//qualification for the scoreboard
	for (int i = 0; i < rcds.size(); ++i) {
		if (r > rcds[i])			// r is the new record awaiting for qualification checking
			q = true;
	}
	if (q == true) {
		rcds[0] = r;				// drop the lowest score
		ofstream ofs("Scoreboard.txt");
		ofs << rcds[0] << rcds[1] << rcds[2] <<			// save the new data
			rcds[3] << rcds[4];
		ofs.close();
		sort(rcds.begin(), rcds.end());		// re-sort the records
	}

}

void Scoreboard::text_records()
{
	new_records();
	for (int i = rcds.size()-1; i >= 0; --i){
		text_names.push_back(new Text(Point(x_max()/3,y_max()/4+60*(4-i)), rcds[i].name()));
		text_scores.push_back(new Text(Point(x_max()*2/3,y_max()/4+60*(4-i)),to_string(rcds[i].score())));
		text_names[4-i]->set_font(FL_BOLD);	text_scores[4-i]->set_font(FL_BOLD);
		text_names[4-i]->set_font_size(20);	text_scores[4-i]->set_font_size(20);
		attach(*text_names[4-i]);			//attach immediately after created
		attach(*text_scores[4-i]);
	}
}

bool Scoreboard::wait_for_button()
{
	show();
	quit_bool = false;

#if 1
	while(!quit_button_pushed()) Fl::wait();
	Fl::redraw();
#else
	Fl::run();

#endif
	return quit_bool;
}