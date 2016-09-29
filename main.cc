/********************************
Danielle Wisemiller 
04/13/2016
<main file to run program>
*********************************/
#include "checkers.h"
#include "game.h"

using namespace std;

int main()
{
	cout<<"Black goes first (human player), and the human player alternates turns with \ncomputer from then on."<<endl;
    cout << "Press enter to begin...";
    cin.get();
	cout<<"Running checkers game..."<<endl;
	system("clear");
	Checkers instance;
	instance.play();
	
}
