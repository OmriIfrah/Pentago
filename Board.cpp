/*
 * Board.cpp
 *
 *  Created on: 25 באפר׳ 2020
 *      Author: Omrii
 */

#include "Board.h"
#include <cstdlib>

using namespace std;
Board::Board() {
	fullSize=6;
	littleSize=3;
	fillBoard();

}


void Board::fillBoard() //fill new board
{

	for(int i=0; i< fullSize; i++)
	{
		for (int j=0; j<fullSize; j++)
		{
			if(i<littleSize)
			{
				if(j < littleSize)
					fullBoard[i][j] = '-';
				else
					fullBoard[i][j] = '~';
			}
			else
			{
				if(j < littleSize)
					fullBoard[i][j] = '~';
				else
					fullBoard[i][j] = '-';
			}
		}

	}


}

void Board::printBoard() //print full board for place
{
	char first = 'A';
	int num = 6;
	for(int i=0; i< fullSize; i++)
	{
		cout<<num<<" ";
		num--;
		for (int j=0; j<fullSize; j++)
		{
			if(j== fullSize-1)
					cout<<fullBoard[i][j]<<endl;
			else
				cout<<fullBoard[i][j]<<" ";

		}
	}
	cout<<"  ";
	for(int i=0; i< fullSize; i++)
	{
		if(i== fullSize-1)
			cout<<first<<endl;
		else
			cout<<first<<" ";

		first++;
	}
	return;
}

void Board::viewBoard() //print board for rotate
{
	int num = 1;
	for(int i=0; i< fullSize; i++)
	{
		if(i == 1 || i == fullSize-2)
		{
			cout<<num<<" ";
			num++;
		}
		else
			cout<<"  ";
		for (int j=0; j<fullSize; j++)
		{
			if(j == fullSize -1 && i != 1 && i != fullSize-2)
				cout<<fullBoard[i][j]<<endl;
			else
				cout<<fullBoard[i][j]<<" ";
		}
		if(i == 1 || i == fullSize-2)
		{
			cout<<num<<endl;
			num++;
		}
	}
	return;
}

void Board::setPlace(char c,int *place)  //put char W or B in board
{
	fullBoard[place[1]][place[0]] = c;
}

int Board::getFullSize() const {
	return fullSize;
}

int Board::getLittleSize() const {
	return littleSize;
}

void Board::get_limit(int num,int* i,int* j,int* imax,int* jmax)
{
	if(num == 1) //board number 1
	{
		*i = 0;
		*j = 0;
		*imax =2;
		*jmax = 2;
	}
	else if(num == 2)	//board number 2
	{
		*i = 0;
		*j = 3;
		*imax =2;
		*jmax = 5;
	}
	else if(num == 3) //board number 3
	{
		*i = 3;
		*j = 0;
		*imax =5;
		*jmax =2;
	}
	else if(num == 4) //board number 4
	{
		*i = 3;
		*j = 3;
		*imax =5;
		*jmax =5;
	}
	return;
}



void Board::Lrotate(int num)
{
	int i,iFirst,jFirst,imax,j,jmax;
	char copy[3][3];
	int k=0,l=0;
	get_limit(num,&iFirst,&jFirst,&imax,&jmax); //get the small board limits for rotate by his number
	for(i= iFirst ; i<= imax; i++)
	{
		for(j= jmax ; j >= jFirst; j--)
		{
			copy[k][l] = fullBoard[i][j];
			k++;
		}
		k=0;
		l++;
	}
	l=0;
	k=0;
	for(i= iFirst ; i<= imax; i++)
	{
		for(j= jFirst ; j<= jmax; j++)
		{
			fullBoard[i][j] = copy[k][l];
			l++;
		}
		l=0;
		k++;
	}

	return;
}
void Board::Rrotate(int num)
{
	int i,iFirst,jFirst,imax,j,jmax;
		char copy[3][3];
		int k=2,l=2;
		get_limit(num,&iFirst,&jFirst,&imax,&jmax); //get the small board limits for rotate by his number
		for(i= iFirst ; i<= imax; i++)
		{
			for(j= jmax ; j >= jFirst; j--)
			{
				copy[k][l] = fullBoard[i][j];
				k--;
			}
			k=2;
			l--;
		}
		l=0;
		k=0;
		for(i= iFirst ; i<= imax; i++)
		{
			for(j= jFirst ; j<= jmax; j++)
			{
				fullBoard[i][j] = copy[k][l];
				l++;
			}
			l=0;
			k++;
		}

		return;

}

bool Board::winCheck(char c,int *place)
{
	if(rowCheck(c,place))
	{
		return true;
	}
	if(colCheck(c,place))
	{
		return true;
	}
	if(slantCheck(c,place))
	{
		return true;
	}
	return false;

}

bool Board::rowCheck(char c,int *place)
{
	int cnt=0;
	int a = place[0]; //place is the middle of row
	int b = place[1];

	while(a+1 < fullSize ) 	//go right in the row
	{
		++a;
		if(fullBoard[b][a] == c)
		{
			cnt++;
		}
		else break;

	}
	a = place[0];
	while(a-1 >= 0 ) 		//go left in the row
	{
		--a;
		if(fullBoard[b][a] == c)
		{
			cnt++;
		}
		else break;
	}
		if (cnt >=4)
			return true;
		return false;
}



bool Board::colCheck(char c,int *place)
{
	int cnt=0;
	int a = place[0]; //place is the middle of column
	int b = place[1];


	while(b+1 < fullSize ) //go down in col
	{
		++b;
		if(fullBoard[b][a] == c)
		{
			cnt++;
		}
		else break;
	}
	b = place[1];
	while(b-1 >= 0 ) 	//go up in col
	{
		--b;
		if(fullBoard[b][a] == c)
		{
			cnt++;
		}
		else break;
	}
	if (cnt >=4) //if have 5
		return true;
	return false;
}


bool Board::slantCheck(char c,int *place)
{
	int cnt=0;
	int a = place[0]; //place the middle of slant
	int b = place[1];

	while(a+1 < fullSize && b+1 < fullSize) //down and right slant
	{
		++a;
		++b;
		if(fullBoard[b][a] == c)
		{
			cnt++;
		}
		else break;

	}
	a = place[0];
	b = place[1];
	while(a-1 >= 0 && b-1 >= 0) //up and left slant
	{
		--a;
		--b;
		if(fullBoard[b][a] == c)
		{
			cnt++;
		}
		else break;
	}
	if (cnt >=4) //if have 5
			return true;

	cnt =0;  		//count=0 , because other slant
	a = place[0];
	b = place[1];
	while(a+1 < fullSize && b-1 >= 0) //down and left slant
	{
		++a;
		--b;
		if(fullBoard[b][a] == c)
		{
			cnt++;
		}
		else break;

	}
	a = place[0];
	b = place[1];
	while(a-1 >= 0 && b+1 < fullSize) //up and right slant
	{
		--a;
		++b;
		if(fullBoard[b][a] == c)
		{
			cnt++;
		}
		else break;

	}
	if (cnt >=4) //if have 5
		return true;
	return false;
}

bool Board::rorateWinCheck(int num){
	int place[2];
	char c;
	int flag = (-1);
	for(int i= 0 ; i< fullSize; i++)//check all board
	{
		for(int j= 0 ; j < fullSize ; j++)
		{
			place[0]= i;
			place[1]= j;
			c = fullBoard[place[1]][place[0]];
			if(c == 'W' )
			{
				if(winCheck(c,place))//if white win
				{
					flag = 1;
				}
			}
			if(c == 'B')
			{
				if(winCheck(c,place))//if black win
				{
					if(flag == 1)//if white win and black win
					{
						printBoard();
						cout<<"\nIt's a draw!"<<endl;
						exit(0);
					}

					else//if only black win
					{
						flag = 2;
					}
				}
			}

		}

	}
	if(flag==1)//if only white win
	{
		printBoard();
		cout<<"\nWhite wins!"<<endl;
		exit(0);
	}
	if(flag==2)//if only black win
	{
		printBoard();
		cout<<"\nBlack wins!"<<endl;
		exit(0);
	}
	return false;
}


bool Board::checkPos(int* place)//check if palace already taken
{
	if(fullBoard[place[1]][place[0]] == 'W' || fullBoard[place[1]][place[0]] == 'B')
		return true;

	return false;
}


Board::~Board() {
	// TODO Auto-generated destructor stub
}

