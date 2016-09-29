/********************************
Danielle Wisemiller 
04/13/2016
<checkers h file with function 
declaration>
*********************************/
#include <iostream> 
#include <string>
#include <cstdlib>
#include "game.h"
#include "spaces.h"
#ifndef CHECKERS_H
#define CHECKERS_H

using namespace std;

class Checkers: public game
{
public:
	Checkers(bool c=false)
	{	
		game::restart(); 
		restart(); 
		copy = c;
	}		
	void display_status()const;
	void restart();
	bool is_legal(const string& move)const;
	bool is_game_over( )const;
	bool check_all_jumps(string* force)const; 
	bool check_all_moves(string* force)const;
	void make_move(const string& move);
	string get_user_move() const; 
	string legal_moves(const string& move)const;
	bool check_jump(int y, int x, int tmpy, int tmpx)const;
	void compute_moves(queue<string>& moves) const;
	int evaluate()const; 
	game::who winning()const;
	game* clone()const;
	
private:
	string convert_back(int y, int x)const;
	string convert_move(const string& move)const;
	
	Spaces board[8][8];
	bool copy;
};

#endif
	