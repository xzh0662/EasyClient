/*
 * TcpClientEx.h
 *
 *  Created on: Aug 12, 2015
 *      Author: root
 */

#ifndef TCPCLIENTEX_H_
#define TCPCLIENTEX_H_
#include "TcpClient.h"

using namespace Easy;

struct lua_State;

class TcpClientEx : public TcpClient
{
	typedef TcpClient super;
public:
	TcpClientEx(void);
	virtual ~TcpClientEx(void);

	virtual int send(int fd, Buffer *buffer);
	virtual int receive(int fd, Buffer *buffer);

	int callByLua(lua_State* L);

	int coKey_;
};


#endif /* TCPCLIENTEX_H_ */
