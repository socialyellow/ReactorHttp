#include "Channel.h"
#include <stdlib.h>
#include <stdio.h>
struct Channel* channelInit(int fd, int events, handleFunc readFunc,
	handleFunc writeFunc, handleFunc destroyFunc, void* arg)
{
	//printf("111111\n");
	struct Channel* channel = (struct Channel*)malloc(sizeof(struct Channel));
	//printf("222222\n");
	channel->arg = arg;
	channel->fd = fd;
	channel->events = events;
	channel->readCallback = readFunc;
	channel->writeCallback = writeFunc;
	channel->destroyCallback = destroyFunc;
	return channel;
}

void writeEventEnable(struct Channel* channel, bool flag)
{
	if (flag)
	{
		channel->events |= WriteEvent;
	}
	else
	{
		channel->events = channel->events & ~WriteEvent;
	}
}

bool isWriteEventEnable(struct Channel* channel)
{
	return channel->events & WriteEvent;
}
