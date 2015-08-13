/*
 * TcpClientEx.cpp
 *
 *  Created on: Aug 12, 2015
 *      Author: root
 */

#include "TcpClientEx.h"
#include "Buffer.h"
#include "stdio.h"

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

	Buffer *buf;
	BUFFER_NEW_RETURN(buf, 1024, -1);
	*buf << str << 123;
	this->send(fd, buf);

	return 0;
}


