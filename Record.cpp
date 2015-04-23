

#include "Record.h"


namespace Graph_lib
{
	bool Record::operator>(const Record& r1) const
	{
		return score() > r1.score();
	}

	bool Record::operator<(const Record& r1) const
	{
		return score() < r1.score();
	}

	string Record::string_record() const
	{
		ostringstream ost;
		ost << n << "\t" << s;
		return ost.str();
	}

	ostream& operator<<(ostream& os, const Record& r)
	{
		return os << r.name() << " , " << r.score() << endl;
		// output format is "Name , Score"
	}

	istream& operator>>(istream& is, Record& rr)
	{
		string name;
		int score;
		char ch1;
		is >> name >> ch1 >> score;		// i.e. Tom , 100
		if (!is) return is;
		if (ch1 != ',')
			is.clear(ios_base::failbit);

		rr = Record(name, score);
		return is;
	}

}