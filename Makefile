# GENERIC MAKEFILE FOR GTK PROJECT

# PROPERTIES
PROG=fidolio
CXX=g++
CXXFLAGS=`pkg-config --cflags gtkmm-4.0` -Iinclude/ -std=c++17 -g
LIBS=`pkg-config --libs gtkmm-4.0`
SRCS=$(wildcard src/*.cc)
OBJS=$(SRCS:.cc=.o)
BIN=bin/
RES=rsc/
OBJ=obj/

# RULES
.SUFFIXES: .o .cc

.cc.o:
	$(CXX) -c $(CXXFLAGS) -o $(subst src/,obj/,$@) $<

all: $(PROG)

$(PROG): $(OBJS)
	$(CXX) -o $(BIN)$(PROG) $(subst src/,obj/,$(OBJS)) $(LIBS) 

clean:
	rm -fR $(OBJ)* $(BIN)* 

install:
	rm -rf /usr/local/share/fidolio
	mkdir /usr/local/share/fidolio
	cp bin/fidolio /usr/local/share/fidolio/fidolio
	cp rsc/fidolio.png rsc/fidolio.svg /usr/local/share/fidolio/
	cp -f rsc/fidolio.desktop /usr/share/applications/fidolio.desktop

uninstall:
	rm -rf /usr/local/share/fidolio
	rm -f /usr/share/applications/fidolio.desktop

