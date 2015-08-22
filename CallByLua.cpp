/*
 * CallByLua.cpp
 *
 *  Created on: Aug 21, 2015
 *      Author: root
 */
#include "CallByLua.h"
#include "TcpClientEx.h"
#include <string>
#include "Buffer.h"

using namespace Easy;

static int send(lua_State *L)
{
	TcpClientEx * client = (TcpClientEx*)lua_touserdata(L, lua_upvalueindex(1));

	if (!lua_isinteger(L, 1))
	{
		printf("send error \n");
	}
	client->coKey_ = lua_tonumber(L, 1);

	int fd = lua_tonumber(L, 2);

	std::string str = lua_tostring(L, 3);

	printf("fd %d str %s\n", fd, str.c_str());

	Buffer *buf;
	BUFFER_NEW_RETURN(buf, 1024, 1);
	*buf << str;
	client->send(fd, buf);

	return 1;
}

void CallByLua(TcpClientEx * client)
{
	lua_State *L = LUA_WRAPPER->luaState();
	lua_newtable(L);
	lua_pushlightuserdata(L,client);
	lua_pushcclosure(L,send,1);
	lua_setfield(L,-2,"Send");
	lua_setglobal(L, "Client");
}


