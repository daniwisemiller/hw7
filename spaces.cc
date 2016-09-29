/********************************
Danielle Wisemiller 
04/13/2016
<spaces cc file with function 
implementations>
*********************************/
#include "spaces.h"

void Spaces::change_color() 
{
	if(red_black == true)
		red_black = false;
	else
		red_black = true;
}
void Spaces::change_occupied() 
{
	if(occupied == true)
		occupied = false;
	else
		occupied = true;
}
void Spaces::change_king() 
{
	if(king == true)
		king = false;
	else
		king = true;
}

