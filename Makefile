
SUBDIRS=src
INCLUDES+=-I$(CURDIR)/include
WEM_TRUNK=$(CURDIR)
APP=wemcached

export INCLUDES WEM_TRUNK APP

all:
	@mkdir -p ./build
	make -C $(SUBDIRS)

clean:
	make -C $(SUBDIRS) clean
