all:twsOrder twsWatcher

BINS:=twsOrder twsWatcher

SOURCES:=$(wildcard *.cpp)
MAIN_SOURCE:=$(wildcard *Main.cpp)

ALL_OBJECTS:=$(SOURCES:.cpp=.o)
MAIN_OBJS:=$(MAIN_SOURCE:.cpp=.o)
NON_MAIN_OBJECTS:=$(filter-out $(MAIN_OBJS), $(ALL_OBJECTS))


HEADERS=$(wildcard *.h)
DEPS=$(SOURCES:.cpp=.d)

CFLAGS+=-MMD
#CXXFLAGS+= -Wno-unused-parameter -Wall  -g -O2 -MMD -Wno-unused-variable \

CXXFLAGS+= -Wno-unused-parameter -Wall  -g -O2 -MMD -Wno-unused-variable -std=c++14 \
	-DHAVE_CONFIG_H -I. -I../.  -DDEBUG -D_GNU_SOURCE -I../PosixSocketClient/src \
        -I../Shared -DIB_USE_STD_STRING -Wextra \
	-MD -MP

twsWatcher: $(NON_MAIN_OBJECTS) $(HEADERS) twsWatcher-Main.o
	/bin/bash ../libtool  --tag=CXX   --mode=link g++ -Wall -Wextra -g -O2   -o twsWatcher $(NON_MAIN_OBJECTS) twsWatcher-Main.o ../PosixSocketClient/libtwsapi.la 	

twsOrder: $(NON_MAIN_OBJECTS) $(HEADERS) twsOrder-Main.o
	/bin/bash ../libtool  --tag=CXX   --mode=link g++ -Wall -Wextra -g -O2   -o twsOrder $(NON_MAIN_OBJECTS) twsOrder-Main.o ../PosixSocketClient/libtwsapi.la 	


# g++ -DHAVE_CONFIG_H -I. -I../.  -DDEBUG -D_GNU_SOURCE -I../PosixSocketClient/src -I../Shared -DIB_USE_STD_STRING -Wall -Wextra -g -O2 -MT TestPosixSocketClient-PosixTestClient.o -MD -MP -MF .deps/TestPosixSocketClient-PosixTestClient.Tpo -c -o TestPosixSocketClient-PosixTestClient.o `test -f 'PosixTestClient.cpp' || echo './'`PosixTestClient.cpp

.PHONY: clean

clean:
	$(RM) $(ALL_OBJECTS) $(DEPS) $(BINS)

-include $(DEPS)
