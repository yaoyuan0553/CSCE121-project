
/*	
	A Record is a user defined object that contains 2 basic
	objects, a string for name and an integer for score.
	It also has overloaded comparison and iostream operators 
	which make std::sort() able to sort a vector of Records
	as well as keep reading from and writing to a file simpler.
*/


#ifndef RECORD_GUARD
#define RECORD_GUARD 1


#include "std_lib_facilities_4.h"


namespace Graph_lib
{
	// a record contains a name and a score
	class Record{
		string n;		//name
		int s;			//score

	public:
		Record(): n("AAA"), s(0) { }		//default record
		Record(string nn, int ss): n(nn), s(ss) { }
		string name() const { return n;}
		int score() const { return s;}

		string string_record() const;
		
		// overload > and < operators for std::sort() function to work
		// only compare score values
		bool operator>(const Record& r1) const;
		bool operator<(const Record& r1) const;
	};

	ostream& operator<<(ostream& os, const Record& r);

	istream& operator>>(istream& is, Record& rr);

}

#endif