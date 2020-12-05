RES=song1

IDIR=include
SDIR=src
LDIR=lib
ODIR=obj
BDIR=build

LIBS=-lrt -lm -lasound -ljack -lpthread
DEPS=
OBJ=\
    AudioInput.o \
    AudioOutput.o \
    Module.o \
    Context.o \
    PlaybackContext.o \

LIBS_GLOB=portaudio/lib/.libs/libportaudio.a
DEPS_GLOB=portaudio/include/portaudio.h

CC=g++
CFLAGS=-I$(IDIR) -std=c++20

_DEPS=$(patsubst %,$(IDIR)/%,$(DEPS))
_OBJ=$(patsubst %,$(ODIR)/%,$(OBJ))
_RES=$(BDIR)/$(RES)

portaudio/lib/.libs/libportaudio.a:
	@cd portaudio && ./configure && make

$(ODIR)/%.o: $(SDIR)/%.cpp $(DEPS) $(DEPS_GLOB)
	@$(CC) -c -o $@ $< $(CFLAGS)
	@echo compiled '$@'

$(_RES): $(_OBJ)
	@$(CC) -o $@ $^ $(CFLAGS) $(LIBS) $(LIBS_GLOB)
	@echo linked '$@'

.PHONY: run clean all default

run: $(_RES)
	@$(_RES)

clean:
	@rm -f -v $(ODIR)/*
	@cd portaudio && make clean

all: $(_RES)
