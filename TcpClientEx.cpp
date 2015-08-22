/*
 * TcpClientEx.cpp
 *
 *  Created on: Aug 12, 2015
 *      Author: root
 */

#include "TcpClientEx.h"
#include "Buffer.h"
#include "stdio.h"
#include "LuaWrapper.h"

TcpClientEx::TcpClientEx(void)
{

}

TcpClientEx::~TcpClientEx(void)
{

}

int TcpClientEx::send(int fd, Buffer *buffer)
{
	return super::send(fd, buffer);
}

int TcpClientEx::receive(int fd, Buffer *buffer)
{
	if (super::receive(fd, buffer))
	{
		return -1;
	}

	std::string str;
	*buffer >> str;
	printf("TcpClientEx::receive %s \n", str.c_str());

	lua_State *L = LUA_WRAPPER->luaState();

	lua_getglobal(L, "Net");
	lua_pushstring(L, "Receive");
	lua_gettable(L, -2);
	lua_pushinteger(L, this->coKey_);
	lua_pushinteger(L, fd);
	lua_pushstring(L, str.c_str());
	if (lua_pcall(L, 3, 0, 0) != LUA_OK)
	{
		fprintf(stderr,"%s\n",lua_tostring(L,-1));
	}
//	Buffer *buf;
//	BUFFER_NEW_RETURN(buf, 1024, -1);
//	*buf << str << 123;
//	this->send(fd, buf);

	return 0;
}

int TcpClientEx::callByLua(lua_State* L)
{
	return 0;
}


