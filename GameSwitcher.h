/*
 * GameSwitcher.h
 *
 *  Created on: Jan 10, 2015
 *      Author: root
 */

#ifndef GAMESTART_GAMESWITCHER_GAMESWITCHER_H_
#define GAMESTART_GAMESWITCHER_GAMESWITCHER_H_

#include "Thread.h"
#include <map>

class GameSwitcher : public Easy::EventBaseThread
{
private:
	GameSwitcher(void);
	virtual ~GameSwitcher(void);

public:
	static GameSwitcher* instance(void);
	static void destroy(void);

	int start(void);

private:
	virtual int signalCallBack(int sig);

private:
	static GameSwitcher* instance_;

	int index_;
};

#define GAME_SWITCHER GameSwitcher::instance()


#endif /* GAMESTART_GAMESWITCHER_GAMESWITCHER_H_ */
