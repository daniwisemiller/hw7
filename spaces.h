/********************************
Danielle Wisemiller 
04/13/2016
<space h file with function declarations>
*********************************/
#include <cstdlib>
#include "colors.h"
#ifndef SPACES_H
#define SPACES_H

class Spaces 
{
	public:
		Spaces(bool occ = false, bool rorb = false, bool k = false)
			{occupied = occ; red_black = rorb; king = k;}
		bool is_occupied() const
			{return occupied;}
		bool red_or_black() const
			{return red_black;}
		bool is_king() const
			{return king;}
		void change_occupied();
		void change_color();
		void change_king();
	
private:
	bool occupied;
	//true = red; false = black
	bool red_black; 
	bool king;	
};
#endif
