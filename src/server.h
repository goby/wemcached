#ifndef _WEMCACHED_SERVER_H_
#define _WEMCACHED_SERVER_H_

int serv();
int client(int port, int block_size, int session_count, int seconds);

#endif
