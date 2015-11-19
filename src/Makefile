
CFLAGS += -g -Wall
CLIBS += -l:libevent.a -lrt

SRCS += client.c
SRCS += config.c
SRCS += daemon.c
SRCS += echo_server.c
SRCS += wemcached.c

OBJECTS = $(SRCS:.c=.o)

.c.o:
	$(CC) -c $(CFLAGS) $<

$(APP): $(OBJECTS)
	$(CC) $(OBJECTS)  -o $@  $(CLIBS)

all: $(SRCS) $(APP)

clean:
	@rm -f $(OBJECTS) $(APP)
