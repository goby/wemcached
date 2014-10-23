AUTOMAKE_OPTIONS = foreign subdir-objects
noinst_PROGRAMS	 = wemcached

wemcached_SORUCES = \
	echo_server.c   \
	daemon.c        \
	config.c		\
	client.c		\
	wemcached.c

wemcached_LDADD = echo_server.o daemon.o config.o client.o
# wemcached_HEADERS = config.h
LIBS=-levent
