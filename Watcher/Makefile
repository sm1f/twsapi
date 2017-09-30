SOURCES=$(wildcard *.cpp)
OBJECTS=$(SOURCES:.cpp=.o)
DEPS=$(SOURCES:.cpp=.d)
BINS=twsWatcher

CFLAGS+=-MMD
CXXFLAGS+= -Wall  -g -O2 -MMD \
	-DHAVE_CONFIG_H -I. -I../.  -DDEBUG -D_GNU_SOURCE -I../PosixSocketClient/src \
        -I../Shared -DIB_USE_STD_STRING -Wextra -MT TestPosixSocketClient-PosixTestClient.o \
	-MD -MP -MF .deps/TestPosixSocketClient-PosixTestClient.Tpo


twsWatcher: $(OBJECTS)
	/bin/bash ../libtool  --tag=CXX   --mode=link g++ -Wall -Wextra -g -O2   -o $(BINS) PosixTestClient.o twsWatcher-Main.o ../PosixSocketClient/libtwsapi.la 	

# g++ -DHAVE_CONFIG_H -I. -I../.  -DDEBUG -D_GNU_SOURCE -I../PosixSocketClient/src -I../Shared -DIB_USE_STD_STRING -Wall -Wextra -g -O2 -MT TestPosixSocketClient-PosixTestClient.o -MD -MP -MF .deps/TestPosixSocketClient-PosixTestClient.Tpo -c -o TestPosixSocketClient-PosixTestClient.o `test -f 'PosixTestClient.cpp' || echo './'`PosixTestClient.cpp
all: $(BINS)

.PHONY: clean

clean:
	$(RM) $(OBJECTS) $(DEPS) $(BINS)

-include $(DEPS)
