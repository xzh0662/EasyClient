/*
 * main.cpp
 *
 *  Created on: Aug 12, 2015
 *      Author: root
 */

#include "TcpClientEx.h"
#include "InetAddr.h"
#include "Buffer.h"
#include <stdio.h>
#include "GameSwitcher.h"
#include "LuaWrapper.h"
#include "CallByLua.h"

int main(int argc, char **argv)
{

	InetAddr addr("127.0.0.1", 1234);
	TcpClientEx *client = new TcpClientEx();
	client->eventBase(GAME_SWITCHER->eventBase());
	client->connect(addr);
	CallByLua(client);
	LUA_WRAPPER->path("./Script/?.lua");
	LUA_WRAPPER->doString("require \"ClientMain\"");
	GAME_SWITCHER->start();
	/*
	client->eventBase(GAME_SWITCHER->eventBase());
	client->connect(addr);
	Buffer *buf;
	std::string str = "test";
	BUFFER_NEW_RETURN(buf, 1024, -1);
	*buf << str << 123;
	client->send(-1, buf);

	GAME_SWITCHER->start();
	*/

	return 0;
}


