/*
 * Board.h
 *
 *  Created on: 25 באפר׳ 2020
 *      Author: Omrii
 */

#ifndef BOARD_H_
#define BOARD_H_

#include <iostream>

class Board {
public:
	Board();
	~Board();
	void fillBoard();
	void printBoard();
	void viewBoard();
	int getFullSize() const;
	int getLittleSize() const;
	void setPlace(char c,int *place);
	bool winCheck(char c,int *place);
	void get_limit(int num,int* i,int* j,int* imax,int* jmax);
	void Lrotate(int num);
	void Rrotate(int num);
	bool rowCheck(char c,int *place);
	bool colCheck(char c,int *place);
	bool slantCheck(char c,int *place);
	bool rorateWinCheck(int num);
	bool checkPos(int* place);


private:
	int fullSize;
	int littleSize;
	char fullBoard[6][6];
};
#endif /* BOARD_H_ */
