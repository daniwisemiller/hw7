/********************************
Danielle Wisemiller 
04/13/2016
<checkers cc file with function 
implementations>
*********************************/
#include "checkers.h"
#include "game.h"
#include "colors.h"
#include <iostream>
#include <string>
#include <cctype>
#include <cstdlib>

using namespace std;

void Checkers::restart() 
{
	game::restart();
	int i;
	
	//RED ROWS************************************
	for(i = 0; i < 8; i+=2) 
	{ //row 0
		if(!board[0][i].is_occupied())
		 {
			board[0][i].change_occupied();
		}
		
		if(!board[0][i].red_or_black()) 
		{
			board[0][i].change_color();
		}
		
		if(board[0][i].is_king()) 
		{
			board[0][i].change_king();
		}
	}
	
	for(i = 1; i < 8; i+=2) 
	{ //row 1
		if(!board[1][i].is_occupied()) 
		{
			board[1][i].change_occupied();
		}
		
		if(!board[1][i].red_or_black())
		 {
			board[1][i].change_color();
		}
		
		if(board[1][i].is_king()) 
		{
			board[1][i].change_king();
		}
	}
	
	for(i = 0; i < 8; i+=2)
	 { //row 2
		if(!board[2][i].is_occupied()) 
		{
			board[2][i].change_occupied();
		}
		
		if(!board[2][i].red_or_black()) 
		{
			board[2][i].change_color();
		}
		
		if(board[2][i].is_king()) 
		{
			board[2][i].change_king();
		}
	}
	
	
	
	//******************NEUTRAL ROWS*******************//
	for(i = 0; i < 8; i++) 
	{ // row 3
		if(board[3][i].is_occupied())
		 {
			board[3][i].change_occupied();
		}

	}
	
	for(i = 0; i < 8; i++) 
	{ //row 4
		if(board[4][i].is_occupied()) 
		{
			board[4][i].change_occupied();
		}
	}
	
	//*********************BLACK ROWS********************//
	for(i = 1; i < 8; i+=2) 
	{ //row 5
		if(!board[5][i].is_occupied()) 
		{
			board[5][i].change_occupied();
		}
		
		if(board[5][i].red_or_black()) 
		{
			board[5][i].change_color();
		}
		
		if(board[5][i].is_king())
		{
			board[5][i].change_king();
		}
	}
	
	for(i = 0; i < 8; i+=2) { //row 6
		if(!board[6][i].is_occupied()) {
			board[6][i].change_occupied();
		}
		
		if(board[6][i].red_or_black()) {
			board[6][i].change_color();
		}
		
		if(board[6][i].is_king()) {
			board[6][i].change_king();
		}
	}
	
	for(i = 1; i < 8; i+=2) { //row 7
		if(!board[7][i].is_occupied()) {
			board[7][i].change_occupied();
		}
		
		if(board[7][i].red_or_black()) {
			board[7][i].change_color();
		}
		
		if(board[7][i].is_king()) {
			board[7][i].change_king();
		}
	}
}


void Checkers::display_status()const 
{
	int j, i;
	cout << "   0    1    2    3    4    5    6    7  " << endl;
	for(i = 0; i < 4; i++) 
	{
		
		//EVEN ROWS//
		cout << " ";
		for(j = 0; j < 4; j++){
			cout<<B_RED <<"     "<<RESET;
			cout<< B_BLACK<<"     "<<RESET;
		}	
		cout << endl;
		if(i == 0)
			cout << "A";
		else if(i == 1)
			cout << "C";
		else if(i == 2)
			cout << "E";
		else if(i == 3)
			cout << "G";
		for(j = 0; j < 4; j++)
		{
			cout<<B_RED<<"  "<<RESET;
			if(board[i+i][j*2].is_occupied() && board[i+i][j*2].is_king() && board[i+i][j*2].red_or_black()) 
			{
				cout << B_WHITE << 'K' << RESET;
			}
			else if(board[i+i][j*2].is_occupied() && board[i+i][j*2].is_king() && !board[i+i][j*2].red_or_black())
			{
				cout << B_BLACK << 'K' << RESET;
			}
			else if(board[i+i][j*2].is_occupied()) 
			{
				if(board[i+i][j*2].red_or_black()) 
				{
					cout << B_WHITE << " " << RESET;
				}
				else
				{
					cout << B_BLACK << " " << RESET;
				}

			}
			else if(!board[i+i][j*2+1].is_occupied()) 
			{	
				cout << B_RED << " " << RESET;	
			}
			cout << B_RED << "  " << RESET;
			cout << B_BLACK << "     " << RESET;
		}	
		cout << endl;
		cout << " ";
		for(j = 0; j < 4; j++){

			cout << B_RED << "     " << RESET;
			cout << B_BLACK << "     " << RESET;
		}	
		cout << endl;
		
		//ODD ROWS
		cout << " ";
		for(j = 0; j < 4; j++) 
		{
			cout << B_BLACK << "     " << RESET;
			cout << B_RED << "     " << RESET;
		}
		
		cout << endl;
		
		if(i == 0)
			cout << "B";
		else if(i == 1)
			cout << "D";
		else if(i == 2)
			cout << "F";
		else if(i == 3)
			cout << "H";
		for(j = 0; j < 4; j++) 
		{
			cout << B_BLACK << "     " << RESET;
			cout << B_RED << "  " << RESET;
			
			if(board[i+i+1][j*2 + 1].is_occupied() && board[i+i+1][j*2 + 1].is_king() && board[i+i+1][j*2 + 1].red_or_black())
			 {
				cout << B_WHITE << 'K' << RESET;
			}
			else if(board[i+i+1][j*2 + 1].is_occupied() && board[i+i+1][j*2 + 1].is_king() && !board[i+i+1][j*2 + 1].red_or_black()) 
			{
				cout << B_BLACK << 'K' << RESET;
			}
			else if(board[i+i+1][j*2 + 1].is_occupied()) 
			{
				
				if(board[i+i+1][j*2 + 1].red_or_black())
					cout << B_WHITE << " " << RESET;
				else
					cout << B_BLACK << " " << RESET;
				
			}
			else if(!board[i+i+1][j*2+1].is_occupied())
			{
				cout << B_RED << " " << RESET;	
			}
			
			cout << B_RED << "  " << RESET;
		}
		
		cout << endl;
		cout << " ";
		for(j = 0; j < 4; j++) 
		{
			cout << B_BLACK << "     " << RESET;
			cout << B_RED << "     " << RESET;
		}
		cout << endl;
	}
}

void Checkers::make_move(const string& move)
{
	
	static int jump2 = 0;
	
	string tmp;
	string dj, spot;
	bool jump = false;
	tmp = convert_move(move);
	
	int real_move = atoi(tmp.c_str());	
	int a = real_move / 1000;
	int b = (real_move / 100) % 10;
	int c = (real_move / 10) % 10;
	int d = real_move % 10;
	
	board[a][b].change_occupied();
	board[c][d].change_occupied();
	
	if(board[a][b].is_king())
	{
		if(!board[c][d].is_king())
			board[c][d].change_king();
	}
	else if(!board[a][b].is_king()) 
	{
		if(board[c][d].is_king())
			board[c][d].change_king();
	}

	if(c == a + 2 && d == b + 2) 
	{
		jump = true;
		board[a+1][b+1].change_occupied();		
	}
	else if(c == a - 2 && d == b + 2) 
	{
		jump = true;
		board[a-1][b+1].change_occupied();
	}
	else if(c == a - 2 && d == b - 2) 
	{
		jump = true;
		board[a-1][b-1].change_occupied();
	}
	else if(c == a + 2 && d == b - 2) 
	{
		jump = true;
		board[a+1][b-1].change_occupied();
	}
	/****************************HUMAN****************************/
	if(next_mover() == HUMAN) 
	{
		if(board[c][d].red_or_black())
			board[c][d].change_color();
		if(c == 0 && !board[c][d].is_king())
			board[c][d].change_king();
	}
	else
	{
		if(!board[c][d].red_or_black())
			board[c][d].change_color();
		if(c == 7 && !board[c][d].is_king())
			board[c][d].change_king();
	}
	
	/***********************DOUBLE JUMPS****************************/
	
	if(jump) 
	{
		if(next_mover() == HUMAN) 
		{
			if(board[c][d].is_king())
			{
				if(board[c+1][d+1].is_occupied() || board[c+1][d-1].is_occupied() || board[c-1][d+1].is_occupied() || board[c-1][d-1].is_occupied()) 
				{
					if(check_jump(c, d, c+1, d+1)|| check_jump(c, d, c+1, d-1) || check_jump(c, d, c-1, d+1) || check_jump(c, d, c-1, d-1))
					{
						if(!clone()) 
						{
							display_status();
							cout<<"DOUBLE JUMP AVAILABLE"<<endl<<endl;
						}
						spot = convert_back(c, d);
						dj = spot;
						dj += legal_moves(spot);
						++jump2;
						make_move(dj);
					}
				}
			}
			else if(board[c-1][d+1].is_occupied() || board[c-1][d-1].is_occupied()) 
			{
				if(check_jump(c, d, c-1, d+1)|| check_jump(c, d, c-1, d-1)) 
				{
					if(!clone()) 
					{
						display_status();
						cout<<"DOUBLE JUMP AVAILABLE"<<endl<<endl;				
					}
					spot = convert_back(c, d);
					dj = spot;
					dj += legal_moves(spot);
					++jump2;
					make_move(dj);
				}			
			}
		
	}
	/****************************COMPUTER****************************/
	else if(next_mover() == COMPUTER) 
	{
		if(board[c][d].is_king())
		{
			if(board[c-1][d+1].is_occupied() || board[c-1][d-1].is_occupied() || board[c+1][d+1].is_occupied() || board[c+1][d-1].is_occupied()) 
			{
				if(check_jump(c, d, c+1, d+1) || check_jump(c, d, c+1, d-1) || check_jump(c, d, c-1, d+1) || check_jump(c, d, c-1, d-1)) 
				{
					if(!clone()) 
					{
						display_status();
						cout<<"DOUBLE JUMP AVAILABLE"<<endl<<endl;
					}
					spot = convert_back(c, d);
					dj = spot;
					tmp = legal_moves(spot);
					dj += tmp.at(0);
					dj += tmp.at(1);
					++jump2;
					make_move(dj);
				}
			}
		}
		else if(board[c+1][d+1].is_occupied() || board[c+1][d-1].is_occupied()) 
		{
			if(check_jump(c, d, c+1, d+1) || check_jump(c, d, c+1, d-1)) 
			{
				if(!clone()) 
				{
					display_status();
					cout<<"DOUBLE JUMP AVAILABLE"<<endl<<endl;
				}
				spot = convert_back(c, d);
				dj = spot;
				tmp = legal_moves(spot);
				dj += tmp.at(0);
				dj += tmp.at(1);
				++jump2;
				make_move(dj);
			}			
		}
		
	}
}
	
	if(jump2 == 0) 
	{
		game::make_move(move);
	}
	else
	{
		--jump2;
	}
}

bool Checkers::is_legal(const string& move)const 
{
	string tmp;
	tmp = convert_move(move);
	int real_move = atoi(tmp.c_str());
	if(move.length() > 2) 
	{
		int a = real_move / 1000;
		int b = (real_move / 100) % 10;
		int c = (real_move / 10) % 10;
		int d = real_move % 10;
		if(a < 0 || b < 0 || c < 0 || d < 0) 
		{
			return false;
		}
		if(a > 7 || b > 7 || c > 7 || d > 7)
		{
			return false;
		}
		
		if(next_mover() == HUMAN) 
		{
			if(board[a][b].red_or_black() || !board[a][b].is_occupied())
				return false;
			
		}
		else if(next_mover() == COMPUTER) 
		{
			if(!board[a][b].red_or_black() || !board[a][b].is_occupied())
				return false;
		}
	}
	else
	{
		int a = real_move / 10;
		int b = real_move % 10;
		if(a < 0 || b < 0) 
			return false;
		if(a > 7 || b > 7)
			return false;
		if(next_mover() == HUMAN) 
		{
			if(board[a][b].red_or_black() || !board[a][b].is_occupied())
				return false;
			
		}
		else if(next_mover() == COMPUTER) 
		{
			if(!board[a][b].red_or_black() || !board[a][b].is_occupied())
				return false;
		}
	}
return true;	
}

string Checkers::get_user_move()const
 {
	string *a = new string;
	string answer = "";
	string end = "@@";
	string force[5];
	int j = -1;
	int ans;
	
	if(check_all_jumps(a)) {
		answer = *a;
		delete a;
		cout << "You have available jumps and must select one of the following pieces to move"<<endl<<endl<<endl;
		
		for(int i = 0; i < answer.length(); i++){ 
			if(i%2 ==0) {
				++j;
			}
			force[j]+=answer.at(i);
		}
		for(int u = 0; u<=j; u++) {
			cout << u+1 << ") " << force[u];
			if(u < j) {
				cout << "; ";	
			}else{
				cout << endl;	
			}
		}	
		do{
			do{
				cout << "(Hint: Select one of the options above \nex:( 1)E4 2)E2 enter either 1 or 2.): ";
				cin.clear();
				cin >> ans;
				answer = force[ans - 1];
			}while(!is_legal(answer) && ans > j + 1 );

			end = legal_moves(answer);
		}while(end == "@@");	
		
	}else{
		do{
			do{
				display_message("Enter the position of the piece you wish to move (ex: F5.): ");
				cin.clear();
				while(cin.peek() == '\n')
					cin.ignore();
				getline(cin, answer);
			}while(!is_legal(answer));
			
			end = legal_moves(answer);
		}while(end == "@@");
	}
	
	
	answer += end;
	return answer;
}

//********************************************************************************************************

string Checkers::legal_moves(const string& move)const {
	string tmp, end;
	string moves[4];
	string jumps[4];
	int possible, jump_possible, choice, tmpy, tmpx;
	bool jump = false;
	
	tmp = convert_move(move);
	int real_move = atoi(tmp.c_str());
	
	int y = real_move / 10;
	int x = real_move % 10;
	
	possible = 0;
	jump_possible = 0;
	
	if(next_mover() == HUMAN && !copy) {
		if(!board[y-1][x+1].is_occupied() && y-1>=0 && x+1<=7 && !jump) {
			tmpy = y-1;
			tmpx = x+1;
			++possible;
			end = convert_back(tmpy, tmpx);	
			moves[possible - 1] = end;	
		}else if(board[y-1][x+1].is_occupied()) {	
			tmpy = y-1;
			tmpx = x+1;
			if(check_jump(y, x, tmpy, tmpx)) {
				tmpy = y-2;
				tmpx = x+2;
				++jump_possible;
				end = convert_back(tmpy, tmpx);
				jumps[jump_possible - 1] = end;
				if(!jump)
					jump = true;
			}
		}
		if(!board[y-1][x-1].is_occupied() && y-1>=0 && x-1>=0 && !jump) {
			tmpy = y-1;
			tmpx = x-1;
			++possible;
			end = convert_back(tmpy, tmpx);	
			moves[possible - 1] = end;
		}else if(board[y-1][x-1].is_occupied()) {	
			tmpy = y-1;
			tmpx = x-1;
			if(check_jump(y, x, tmpy, tmpx)) {
				tmpy = y-2;
				tmpx = x-2;
				++jump_possible;
				end = convert_back(tmpy, tmpx);
			
				jumps[jump_possible - 1] = end;
				
				if(!jump)
					jump = true;
			}
		}
		if(board[y][x].is_king()) {	
			if(!board[y+1][x+1].is_occupied() && y+1<=7 && x+1<=7 && !jump) {
				tmpy = y+1;
				tmpx = x+1;
				++possible;
				end = convert_back(tmpy, tmpx);
				moves[possible - 1] = end;
			}else if(board[y+1][x+1].is_occupied()) {	
				tmpy = y+1;
				tmpx = x+1;
				if(check_jump(y, x, tmpy, tmpx)) {
					tmpy = y+2;
					tmpx = x+2;
					++jump_possible;
					end = convert_back(tmpy, tmpx);
					jumps[jump_possible - 1] = end;
					if(!jump)
						jump = true;
				}
			}
			if(!board[y+1][x-1].is_occupied() && y+1<=7 && x-1>=0 && !jump) {
				tmpy = y+1;
				tmpx = x-1;
				++possible;
				end = convert_back(tmpy, tmpx);
				moves[possible - 1] = end;
			}else if(board[y+1][x-1].is_occupied()) {	
				tmpy = y+1;
				tmpx = x-1;
				if(check_jump(y, x, tmpy, tmpx)) {
					tmpy = y+2;
					tmpx = x-2;
					++jump_possible;
					end = convert_back(tmpy, tmpx);
					jumps[jump_possible - 1] = end;
					if(!jump)
						jump = true;
				}
			}
		}
	}else if(next_mover() == HUMAN) {
		end = "";
		tmp = "";
		if(!board[y-1][x+1].is_occupied() && y-1>=0 && x+1<=7 && !jump) {
			tmpy = y-1;
			tmpx = x+1;
			++possible;
			end += convert_back(tmpy, tmpx);
		}else if(board[y-1][x+1].is_occupied()) {	
			tmpy = y-1;
			tmpx = x+1;
			if(check_jump(y, x, tmpy, tmpx)) {
				tmpy = y-2;
				tmpx = x+2;
				++jump_possible;
				tmp += convert_back(tmpy, tmpx);
				if(!jump)
					jump = true;
			}
		}	
		if(!board[y-1][x-1].is_occupied() && y-1>=0 && x-1>=0 && !jump) {
			tmpy = y-1;
			tmpx = x-1;
			++possible;
			end += convert_back(tmpy, tmpx);
		}else if(board[y-1][x-1].is_occupied()) {	
			tmpy = y-1;
			tmpx = x-1;
			if(check_jump(y, x, tmpy, tmpx)) {
				tmpy = y-2;
				tmpx = x-2;
				++jump_possible;
				tmp += convert_back(tmpy, tmpx);
				if(!jump)
					jump = true;
			}
		}
		if(board[y][x].is_king()) {
			if(!board[y+1][x+1].is_occupied() && y+1<=7 && x+1<=7 && !jump) {
				tmpy = y+1;
				tmpx = x+1;
				++possible;
				end += convert_back(tmpy, tmpx);
			}else if(board[y+1][x+1].is_occupied()) {	
				tmpy = y+1;
				tmpx = x+1;
				if(check_jump(y, x, tmpy, tmpx)) {
					tmpy = y+2;
					tmpx = x+2;
					++jump_possible;
					tmp += convert_back(tmpy, tmpx);
					if(!jump)
						jump = true;
				}
			}
			if(!board[y+1][x-1].is_occupied() && y+1<=7 && x-1>=0 && !jump) {
				tmpy = y+1;
				tmpx = x-1;
				++possible;
				end += convert_back(tmpy, tmpx);
			}else if(board[y+1][x-1].is_occupied()) {	
			tmpy = y+1;
			tmpx = x-1;
			if(check_jump(y, x, tmpy, tmpx)) {
					tmpy = y+2;
					tmpx = x-2;
					++jump_possible;
					tmp += convert_back(tmpy, tmpx);
					if(!jump)
						jump = true;
				}
			}
		}
	}else if(next_mover() == COMPUTER) {
		end = "";
		tmp = "";
		if(!board[y+1][x+1].is_occupied() && y+1<=7 && x+1<=7 && !jump) {
			tmpy = y+1;
			tmpx = x+1;
			++possible;
			end += convert_back(tmpy, tmpx);
		}else if(board[y+1][x+1].is_occupied()) {	
			tmpy = y+1;
			tmpx = x+1;
			if(check_jump(y, x, tmpy, tmpx)) {
				tmpy = y+2;
				tmpx = x+2;
				++jump_possible;
				tmp += convert_back(tmpy, tmpx);
				if(!jump)
					jump = true;
			}
		}	
		if(!board[y+1][x-1].is_occupied() && y+1<=7 && x-1>=0 && !jump) {
			tmpy = y+1;
			tmpx = x-1;
			++possible;
			end += convert_back(tmpy, tmpx);
		}else if(board[y+1][x-1].is_occupied()) {	
			tmpy = y+1;
			tmpx = x-1;
			if(check_jump(y, x, tmpy, tmpx)) {
				tmpy = y+2;
				tmpx = x-2;
				++jump_possible;
				tmp += convert_back(tmpy, tmpx);
				if(!jump)
					jump = true;
			}
		}
		if(board[y][x].is_king()) {
			if(!board[y-1][x+1].is_occupied() && y-1>=0 && x+1<=7 && !jump) {
				tmpy = y-1;
				tmpx = x+1;
				++possible;
				end += convert_back(tmpy, tmpx);
			}else if(board[y-1][x+1].is_occupied()) {	
				tmpy = y-1;
				tmpx = x+1;
				if(check_jump(y, x, tmpy, tmpx)) {
					tmpy = y-2;
					tmpx = x+2;
					++jump_possible;
					tmp += convert_back(tmpy, tmpx);
					if(!jump)
						jump = true;
				}
			}
			if(!board[y-1][x-1].is_occupied() && y-1>=0 && x-1>=0 && !jump) {
				tmpy = y-1;
				tmpx = x-1;
				++possible;
				end += convert_back(tmpy, tmpx);
			}else if(board[y-1][x-1].is_occupied()) {	
			tmpy = y-1;
			tmpx = x-1;
			if(check_jump(y, x, tmpy, tmpx)) {
					tmpy = y-2;
					tmpx = x-2;
					++jump_possible;
					tmp += convert_back(tmpy, tmpx);
					if(!jump)
						jump = true;
				}
			}
		}
	}
	
	if(next_mover() == HUMAN && !copy) {
		cout << "Possible moves: ";
		
		if(jump) {
			for(int i = 0; i < jump_possible; i++) {
				cout <<	i + 1 << ") " << jumps[i];
				if(i!= jump_possible - 1) {
					cout << "; ";	
				}
			}
			cout << endl;
		}else{
			for(int i = 0; i < possible; i++) {
				cout << i+1 << ") " << moves[i];
				if(i!= possible - 1){
					cout << "; ";
				}
			}
			cout << endl;
		}
		cout<<endl;
		cout << "Which move will you select?" << endl;
		cout << "(Hint: Enter the number before the 2 character move e.g. 1, 2, 3...etc) " << endl;
		cout << "(Hint: Enter any number that doesn't appear to reselect the piece you want to move): ";
		cin >> choice;

		if(jump){
			if(choice > jump_possible || choice < 1)
				return "@@";
			else
				return jumps[choice - 1];
		}else{
			if(choice > possible || choice < 1)
				return "@@";
			else
				return moves[choice - 1];
		}
	}else{
		if(jump) {
			return tmp;
		}else{
			return end;
		}
	}
}

bool Checkers::check_jump(int y, int x, int tempy, int tempx)const {
	int ydir, xdir;
	ydir = tempy - y;
	xdir = tempx - x;
	
	if(next_mover() == HUMAN) {
		if(board[tempy][tempx].red_or_black() && board[tempy][tempx].is_occupied()) {
			if(!board[tempy+ydir][tempx+xdir].is_occupied()) {
				if(tempy+ydir <= 7 && tempy+ydir >=0 && tempx +xdir <= 7 && tempx+xdir >= 0) {
					return true;
				}
			}
		}
	}else if(next_mover() == COMPUTER) {
		if(!board[tempy][tempx].red_or_black() && board[tempy][tempx].is_occupied()) {
			if(!board[tempy+ydir][tempx+xdir].is_occupied()) {
				if(tempy+ydir <= 7 && tempy+ydir >=0 && tempx +xdir <= 7 && tempx+xdir >= 0) {
					return true;
				}
			}
		}
	}
	
return false;
}

bool Checkers::is_game_over()const 
{ 
	string *junk = new string;
	
	if(check_all_moves(junk)){
		delete junk;
		return false;
	}else{
		delete junk;
		return true;
	}
}

bool Checkers::check_all_moves(string* force)const 
{
	bool jump = false;
	*force = "";
	
	if(check_all_jumps(force)) {
		return true;	
	}else{
		*force = "";
		
		for(int y = 0; y < 8; y++){
			for(int x = 0; x < 8; x++){
				if(y%2 == 0){
					if(x%2 == 0) {
						if(is_legal(convert_back(y, x))){
							if(next_mover() == HUMAN) {
								if(!board[y-1][x-1].is_occupied() && y-1 >=0 && x-1>=0){
									*force += convert_back(y,x);
									jump = true;
								}else if(!board[y-1][x+1].is_occupied() && y-1 >=0 && x+1<=7){
									*force += convert_back(y,x);
									jump = true;
									
								}else if(board[y][x].is_king()){
									if(!board[y+1][x-1].is_occupied() && y+1<=7 && x-1>=0){
										*force += convert_back(y,x);
										jump = true;
									}else if(!board[y+1][x+1].is_occupied() && y+1<=7 && x+1<=7){
										*force += convert_back(y,x);
										jump = true;
									}
								}
							}else{
								if(!board[y+1][x-1].is_occupied() && y+1<=7 && x-1>=0){
									*force += convert_back(y,x);
									jump = true;
								}else if(!board[y+1][x+1].is_occupied() && y+1<=7 && x+1<=7){
									*force += convert_back(y,x);
									jump = true;
								}else if(board[y][x].is_king()){
									if(!board[y-1][x-1].is_occupied() && y-1 >=0 && x-1>=0){
										*force += convert_back(y,x);
										jump = true;
									}else if(!board[y-1][x+1].is_occupied() && y-1 >=0 && x+1<=7){
										*force += convert_back(y,x);
										jump = true;
									}
								}
							}
						}
					}
				}else{
					if(x%2 == 1) {
						if(is_legal(convert_back(y, x))){
							if(next_mover() == HUMAN) {
								if(!board[y-1][x-1].is_occupied() && y-1 >=0 && x-1>=0){
									*force += convert_back(y,x);
									jump = true;
								}else if(!board[y-1][x+1].is_occupied() && y-1 >=0 && x+1<=7){
									*force += convert_back(y,x);
									jump = true;
									
								}else if(board[y][x].is_king()){
									if(!board[y+1][x-1].is_occupied() && y+1<=7 && x-1>=0){
										*force += convert_back(y,x);
										jump = true;
									}else if(!board[y+1][x+1].is_occupied() && y+1<=7 && x+1<=7){
										*force += convert_back(y,x);
										jump = true;
									}
								}
							}else{
								if(!board[y+1][x-1].is_occupied() && y+1<=7 && x-1>=0){
									*force += convert_back(y,x);
									jump = true;
								}else if(!board[y+1][x+1].is_occupied() && y+1<=7 && x+1<=7){
									*force += convert_back(y,x);
									jump = true;
								}else if(board[y][x].is_king()){
									if(!board[y-1][x-1].is_occupied() && y-1 >=0 && x-1>=0){
										*force += convert_back(y,x);
										jump = true;
									}else if(!board[y-1][x+1].is_occupied() && y-1 >=0 && x+1<=7){
										*force += convert_back(y,x);
										jump = true;
									}
								}
							}
						}
					}
				}
			}		
		}
	}
return jump;
}

bool Checkers::check_all_jumps(string* force)const 
{
	bool jump = false;
	*force = "";
	
	for(int y = 0; y < 8; y++){
		for(int x = 0; x < 8; x++){
			if(y%2 == 0){
				if(x%2 == 0) {
					if(is_legal(convert_back(y, x))){
						if(next_mover() == HUMAN) {
							if(board[y-1][x-1].is_occupied()){
								if(check_jump(y, x, y-1, x-1)) {
									*force += convert_back(y,x);
									jump = true;
								}
							}else if(board[y-1][x+1].is_occupied()){
								if(check_jump(y, x, y-1, x+1)){
									*force += convert_back(y,x);
									jump = true;
								}
							}else if(board[y][x].is_king()){
								if(board[y+1][x-1].is_occupied()){
									if(check_jump(y, x, y+1, x-1)){
										*force += convert_back(y,x);
										jump = true;
									}
								}else if(board[y+1][x+1].is_occupied()){
									if(check_jump(y, x, y+1, x+1)){
										*force += convert_back(y,x);
										jump = true;
									}
								}
							}
						}else{
							if(board[y+1][x-1].is_occupied()){
								if(check_jump(y, x, y+1, x-1)){
									*force += convert_back(y,x);
									jump = true;
								}
							}else if(board[y+1][x+1].is_occupied()){
								if(check_jump(y, x, y+1, x+1)){
									*force += convert_back(y,x);
									jump = true;
								}
							}else if(board[y][x].is_king()){
								if(board[y-1][x-1].is_occupied()){
									if(check_jump(y, x, y-1, x-1)) {
										*force += convert_back(y,x);
										jump = true;
									}
								}else if(board[y-1][x+1].is_occupied()){
									if(check_jump(y, x, y-1, x+1)){
										*force += convert_back(y,x);
										jump = true;
									}
								}
							}
						}
					}
				}
			}else{
				if(x%2 == 1) {
					if(is_legal(convert_back(y, x))){
						if(next_mover() == HUMAN) {
							if(board[y-1][x-1].is_occupied()){
								if(check_jump(y, x, y-1, x-1)) {
									*force += convert_back(y,x);
									jump = true;
								}
							}else if(board[y-1][x+1].is_occupied()){
								if(check_jump(y, x, y-1, x+1)){
									*force += convert_back(y,x);
									jump = true;
								}
							}else if(board[y][x].is_king()){
								if(board[y+1][x-1].is_occupied()){
									if(check_jump(y, x, y+1, x-1)){
										*force += convert_back(y,x);
										jump = true;
									}
								}else if(board[y+1][x+1].is_occupied()){
									if(check_jump(y, x, y+1, x+1)){
										*force += convert_back(y,x);
										jump = true;
									}
								}
							}
						}else{
							if(board[y+1][x-1].is_occupied()){
								if(check_jump(y, x, y+1, x-1)){
									*force += convert_back(y,x);
									jump = true;
								}
							}else if(board[y+1][x+1].is_occupied()){
								if(check_jump(y, x, y+1, x+1)){
									*force += convert_back(y,x);
									jump = true;
								}
							}else if(board[y][x].is_king()){
								if(board[y-1][x-1].is_occupied()){
									if(check_jump(y, x, y-1, x-1)) {
										*force += convert_back(y,x);
										jump = true;
									}
								}else if(board[y-1][x+1].is_occupied()){
									if(check_jump(y, x, y-1, x+1)){
										*force += convert_back(y,x);
										jump = true;
									}
								}
							}
						}
					}
				}
			}
		}		
	}
return jump;
}

 game::who Checkers::winning()const 
{
	int win;
	
	win = evaluate();

	if(win > 0) {
		return COMPUTER;	
	}else if(win < 0){
		return HUMAN;
	}else{
		return NEUTRAL;
	}
}

 game* Checkers::clone()const {
	Checkers *tmp = new Checkers(true);
	
	for(int y = 0; y < 8; y++) {
		for(int x = 0; x < 8; x++) {
			tmp -> board[y][x] = board[y][x];
		}
	}
	
return tmp;
}

void Checkers::compute_moves(queue<string>& moves) const {
	string *pieces = new string;
	string tmp_piece, all_moves, tmp_move;
	
	check_all_moves(pieces);
	for(int i = 0; i < pieces -> length(); i++) {
		if(i%2 == 0)
			tmp_piece = "";
		
		tmp_piece += pieces -> at(i);
		
		if(tmp_piece.length() == 2) {
			all_moves = legal_moves(tmp_piece);
			
			for(int j = 0; j < all_moves.length(); j++){
				if(j%2 == 0)
					tmp_move = "";
				
				tmp_move += all_moves.at(j);
				
				if(tmp_move.length() == 2) {
					moves.push(tmp_piece + tmp_move);	
				}
			}
		}
	}
	delete pieces;
}

int Checkers::evaluate()const 
{
	
	int value = 0;
	
	for(int y = 0; y < 8; y++)
	{
		for(int x = 0; x < 8; x++)
		{
			if(y%2 == 0)
			{
				if(x%2 == 0) 
				{
					if(board[y][x].is_occupied())
					{
						if(board[y][x].red_or_black()) 
						{
							++value;
							if(board[y][x].is_king()) 	
								++value;
						}
						else
						{
							--value;
							if(board[y][x].is_king())
								--value;
						}
					}
				}
			}
			else
			{
				if(x%2 == 1) 
				{
					if(board[y][x].is_occupied())
					{
						if(board[y][x].red_or_black()) 
						{
							++value;
							if(board[y][x].is_king()) 	
								++value;
						}
						else
						{
							--value;
							if(board[y][x].is_king())
								--value;
						}
					}
				}
			}
		}		
	}
	
return value;
}

string Checkers::convert_move(const string& move)const
{
	string tmp;
	int a = static_cast<int>(tolower(move.at(0)));
	int b = static_cast<int>(tolower(move.at(1)));
	
	
	switch(a)
	{
	case 97:
		tmp += '0';
		break;
	case 98: 
		tmp += '1';
		break;
	case 99:
		tmp += '2';
		break;
	case 100:
		tmp += '3';
		break;
	case 101:
		tmp += '4';
		break;
	case 102:
		tmp += '5';
		break;
	case 103:
		tmp += '6';
		break;
	case 104:
		tmp += '7';
		break;
	default:
		tmp += '@';
	}
	
	switch(b) 
	{
	case 48:
		tmp += '0';
		break;
	case 49: 
		tmp += '1';
		break;
	case 50:
		tmp += '2';
		break;
	case 51:
		tmp += '3';
		break;
	case 52:
		tmp += '4';
		break;
	case 53:
		tmp += '5';
		break;
	case 54:
		tmp += '6';
		break;
	case 55:
		tmp += '7';
		break;
	default:
		tmp += '@';
	}
	

	if(move.length() > 2) 
	{
		
		int c = static_cast<int>(tolower(move.at(2)));
		int d = static_cast<int>(tolower(move.at(3)));

		switch(c) 
		{
		case 97:
			tmp += '0';
			break;
		case 98: 
			tmp += '1';
			break;
		case 99:
			tmp += '2';
			break;
		case 100:
			tmp += '3';
			break;
		case 101:
			tmp += '4';
			break;
		case 102:
			tmp += '5';
			break;
		case 103:
			tmp += '6';
			break;
		case 104:
			tmp += '7';
			break;
		default:
			tmp += '@';
		}
	
		switch(d) 
		{
		case 48:
			tmp += '0';
			break;
		case 49: 
			tmp += '1';
			break;
		case 50:
			tmp += '2';
			break;
		case 51:
			tmp += '3';
			break;
		case 52:
			tmp += '4';
			break;
		case 53:
			tmp += '5';
			break;
		case 54:
			tmp += '6';
			break;
		case 55:
			tmp += '7';
			break;
		default:
			tmp += '@';
		}
	}
	
	return tmp;
}

string Checkers::convert_back(int y, int x)const 
{
	string tmp;
	
	switch(y) 
	{
	case 0:
		tmp += 'A';
		break;
	case 1: 
		tmp += 'B';
		break;
	case 2:
		tmp += 'C';
		break;
	case 3:
		tmp += 'D';
		break;
	case 4:
		tmp += 'E';
		break;
	case 5:
		tmp += 'F';
		break;
	case 6:
		tmp += 'G';
		break;
	case 7:
		tmp += 'H';
		break;
	default:
		tmp += '@';
	}
	
	switch(x) 
	{
	case 0:
		tmp += '0';
		break;
	case 1: 
		tmp += '1';
		break;
	case 2:
		tmp += '2';
		break;
	case 3:
		tmp += '3';
		break;
	case 4:
		tmp += '4';
		break;
	case 5:
		tmp += '5';
		break;
	case 6:
		tmp += '6';
		break;
	case 7:
		tmp += '7';
		break;
	default:
		tmp += '@';
	}

return tmp;
}


