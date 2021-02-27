/*
 * Game.cpp
 *
 *  Created on: 27 באפר׳ 2020
 *      Author: Omrii
 */

#include "Game.h"
#include <cstdlib>
#include <sstream>
#include <iomanip>
#include <string>

Game::Game() {
	board = new Board; //make new board for game
	maxSize = 36;
	gameCnt = 0;		//cnt to know when board is full
	whiteP = 'W';
	blackP = 'B';

}
void Game::run()
{
	while(1)
	{
		int place[2];						//to save the place i want
		int num;							//to know what board to rotate
		board->printBoard();				//print board to place
		cout<<"\nWhite's placement move:"<<endl;
		getPlace(place);					//get where i want to put w
		board->setPlace(whiteP,place); 		//put w in place
		gameCnt++; 							//up the cnt of how much i played
		if(board->winCheck(whiteP,place)) 	//check if white win
		{
			board->printBoard();
			cout<<"\nWhite wins!"<<endl;
			break;
		}
		board->viewBoard();  				//print board to rotate
		cout<<"\nWhite's rotation move:"<<endl;
		num = get_rotate();
		if(gameCnt >= maxSize)				//if the board is full print its draw
		{
			board->printBoard();
			cout<<"\nIt's a draw!"<<endl;
			break;
		}
		board->rorateWinCheck(num);			//check if some one win after rotate

		board->printBoard();				//print full board to place
		cout<<"\nBlack's placement move:"<<endl;
		getPlace(place);
		board->setPlace(blackP,place);		//put B in place in board
		gameCnt++;
		if(board->winCheck(blackP,place))
		{
			board->printBoard();
			cout<<"\nBlack wins!"<<endl;
			break;
		}


		board->viewBoard();						//print board to rotate
		cout<<"\nBlack's rotation move:"<<endl;
		num= get_rotate();
		if(gameCnt >= maxSize)
		{
			board->printBoard();
			cout<<"\nIt's a draw!"<<endl;
			break;
		}
		board->rorateWinCheck(num); 			//check if some one win after rotate


	}
}
void Game::getPlace(int* place)
{
	bool check;
	string input;
	getline(cin,input);
		check = check_input1(&input,place);
		while(check == false)
		{
			cerr<<"Invalid placement move; the game awaits a valid move"<<endl;
			getline(cin,input);
			check = check_input1(&input,place);
		}

	return;
}
bool Game::check_input1(string* str,int* place)
{
	if((*str).size() != 2)
		return false;

	if(isalpha((*str)[0]) && isdigit((*str)[1]))
	{
		if(islower((*str)[0]))
		{
			(*str)[0] = toupper((*str)[0]);
		}
		if((*str)[0]<'A' || (*str)[0] >'F')
		{
			return false;
		}
		if((*str)[1]<'1' || (*str)[1] >'6')
		{
			return false;
		}
		place[0] = (*str)[0] - 'A';
		place[1] = (*str)[1] - '1';
		place[1] = 5 - place[1];
		if(board->checkPos(place))
		{
			return false;
		}
		return true;
	}
	return false;
}
int Game::get_rotate()
{
	bool check;
	string input;
		getline(cin,input);
		check = check_input2(&input);
		while(check == false)
		{
			cerr<<"Invalid rotation move; the game awaits a valid move"<<endl;
			getline(cin,input);
			check = check_input2(&input);
		}

		int num = input[0] - '0';
		if(input[1] == 'L')
			board->Lrotate(num);
		else
			board->Rrotate(num);

		return num;

}
bool Game::check_input2(string* str)
{
	if((*str).size() != 2)
		return false;


	if(isalpha((*str)[1]) && isdigit((*str)[0]))
	{
		if(islower((*str)[1]))
		{
			(*str)[1] = toupper((*str)[1]);
		}
		if((*str)[1] != 'R' && (*str)[1] != 'L')
		{
			return false;
		}
		if((*str)[0]<'1' || (*str)[0] >'4')
		{
			return false;
		}
		return true;
	}
	return false;

}


Game::~Game() {
	delete board;
}

