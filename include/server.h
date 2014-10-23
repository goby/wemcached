#ifndef __WEMCACHED_CONFIG_H__
#define __WEMCACHED_CONFIG_H__

int serv();
int client(int port, int block_size, int session_count, int seconds);

#endif
