/*
 * GameSwitcher.cpp
 *
 *  Created on: Jan 10, 2015
 *      Author: root
 */

#include <string>

#include "GameSwitcher.h"
#include "stdio.h"

GameSwitcher::GameSwitcher(void)
	: index_(-1)
{
}

GameSwitcher::~GameSwitcher(void)
{

}

GameSwitcher* GameSwitcher::instance_ = 0;

GameSwitcher* GameSwitcher::instance(void)
{
    if (instance_ == 0)
    {
        instance_ = new GameSwitcher();
    }
    return instance_;
}

void GameSwitcher::destroy(void)
{
    if (instance_ != 0)
    {
        delete instance_;
        instance_ = 0;
    }
}

int GameSwitcher::start(void)
{
	printf("GameSwitcher::start \n");

	this->registeSignal(SIGINT);

	return this->startSignalLoop();
}

int GameSwitcher::signalCallBack(int sig)
{
	printf("GameSwitcher::signalCallBack sig=%d\n", sig);

	return Easy::EventBaseThread::signalCallBack(sig);;

}
