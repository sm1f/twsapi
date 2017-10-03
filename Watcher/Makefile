
SOURCES=$(wildcard *.cpp)
OBJECTS=$(SOURCES:.cpp=.o)
HEADERS=$(wildcard *.h)
DEPS=$(SOURCES:.cpp=.d)
BINS=twsWatcher

CFLAGS+=-MMD
#CXXFLAGS+= -Wno-unused-parameter -Wall  -g -O2 -MMD -Wno-unused-variable \

CXXFLAGS+= -Wno-unused-parameter -Wall  -g -O2 -MMD -Wno-unused-variable \
	-DHAVE_CONFIG_H -I. -I../.  -DDEBUG -D_GNU_SOURCE -I../PosixSocketClient/src \
        -I../Shared -DIB_USE_STD_STRING -Wextra -MT TestPosixSocketClient-PosixTestClient.o \
	-MD -MP -MF .deps/TestPosixSocketClient-PosixTestClient.Tpo


twsWatcher: $(OBJECTS) $(HEADERS)
	/bin/bash ../libtool  --tag=CXX   --mode=link g++ -Wall -Wextra -g -O2   -o $(BINS) $(OBJECTS) ../PosixSocketClient/libtwsapi.la 	
#	/bin/bash ../libtool  --tag=CXX   --mode=link g++ -Wall -Wextra -g -O2 -Wno-unused-variable   -o $(BINS) $(OBJECTS) ../PosixSocketClient/libtwsapi.la 	

# g++ -DHAVE_CONFIG_H -I. -I../.  -DDEBUG -D_GNU_SOURCE -I../PosixSocketClient/src -I../Shared -DIB_USE_STD_STRING -Wall -Wextra -g -O2 -MT TestPosixSocketClient-PosixTestClient.o -MD -MP -MF .deps/TestPosixSocketClient-PosixTestClient.Tpo -c -o TestPosixSocketClient-PosixTestClient.o `test -f 'PosixTestClient.cpp' || echo './'`PosixTestClient.cpp
all: $(BINS)

.PHONY: clean

clean:
	$(RM) $(OBJECTS) $(DEPS) $(BINS)

-include $(DEPS)
