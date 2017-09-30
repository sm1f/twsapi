AM_CPPFLAGS = -DDEBUG -D_GNU_SOURCE
AM_CXXFLAGS = $(DEFAULT_CXXFLAGS)
AM_LDFLAGS =


noinst_PROGRAMS =
noinst_PROGRAMS += TwsWatcher
TwsWatcher_SOURCES =
TwsWatcher_SOURCES += PosixTestClient.cpp
TwsWatcher_SOURCES += Main.cpp
noinst_HEADERS =
noinst_HEADERS += PosixTestClient.h
EXTRA_TwsWatcher_SOURCES =
TwsWatcher_LDADD =
TwsWatcher_LDADD += $(top_builddir)/PosixSocketClient/libtwsapi.la
TwsWatcher_CPPFLAGS =
TwsWatcher_CPPFLAGS += $(AM_CPPFLAGS)
TwsWatcher_CPPFLAGS += -I$(top_srcdir)/PosixSocketClient/src
TwsWatcher_CPPFLAGS += -I$(top_srcdir)/Shared
TwsWatcher_LDFLAGS = $(AM_LDFLAGS)

CLEANFILES =
CLEANFILES += *.s
CLEANFILES += *.i

## Create preprocessor output (debugging purposes only)
.c.i:
	$(COMPILE) -E -o $@ $<
.cpp.i:
	$(CXXCOMPILE) -E -o $@ $<

## Create assembler output (debugging purposes only)
.c.s:
	$(COMPILE) -S -c $(cflags) $<
.cpp.s:
	$(CXXCOMPILE) -S -c $(cflags) $<

