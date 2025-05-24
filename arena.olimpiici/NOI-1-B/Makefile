CXX_FLAGS=-O2 -std=c++17

CPP_FILES=$(wildcard *.cpp)
BIN_FILES=$(patsubst %.cpp, %.exe, ${CPP_FILES})

all:$(BIN_FILES)
%.exe: %.cpp
	@echo Compiling $<
	g++ $(CXX_FLAGS) $< -g -o $@
%upr:%.cpp
	g++ $?  -o $@