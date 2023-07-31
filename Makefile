CC=g++
CFLAGS=-Wall -pedantic
TARGET=.

SRC=./src
SOURCES=$(wildcard $(SRC)/*.cpp)

OBJ=./obj
OBJECTS=$(patsubst $(SRC)/%.cpp,$(OBJ)/%.o,$(SOURCES))

EXEC=game-of-life

QTVER=6.5.2
QTDIR=$(HOME)/Qt/$(QTVER)/gcc_64

INCLUDES=-I$(QTDIR)/include -I$(QTDIR)/include/QtGui -I$(QTDIR)/include/QtCore -I$(QTDIR)/include/QtWidgets -Iinc

LIBS=-L$(QTDIR)/lib -lQt6Core -lQt6Gui -lQt6Widgets

DEFS=-DQT_CORE_LIB -DQT_GUI_LIB -DQT_WIDGETS_LIB -DQT_NO_VERSION_TAGGING

__start__: $(TARGET)/$(EXEC)
	$(TARGET)/$(EXEC)

all: $(TARGET)/$(EXEC)

$(TARGET)/$(EXEC): $(OBJECTS)
	$(CC) $(CFLAGS) $(DEFS) $(LIBS) -o $(TARGET)/$(EXEC) $(OBJECTS)

$(OBJ):
	mkdir -p $(OBJ)

$(OBJ)/%.o: $(SRC)/%.cpp | $(OBJ)
	$(CC) -c $(CFLAGS) $(DEFS) $(INCLUDES) -o $@ $<

.PHONY: clean again

clean:
	rm -f $(OBJ)/*.o $(TARGET)/$(EXEC)

again: clean
	$(MAKE) all