/*
 * Game.h
 *
 *  Created on: 27 באפר׳ 2020
 *      Author: Omrii
 */

#ifndef GAME_H_
#define GAME_H_

#include "Board.h"
#include "string"
#include <cstdlib>
using namespace std;

class Game {
private:
	Board* board;
	int maxSize;
	int gameCnt;
	char whiteP;
	char blackP;

public:
	Game();
	void run();
	void getPlace(int* place);
	bool check_input1(string* str,int* place);
	int get_rotate();
	bool check_input2(string* str);


	~Game();

};

#endif /* GAME_H_ */
