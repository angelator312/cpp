CXX_FLAGS=#-DEVAL -std=c++17 -O2 -pipe -static -s

CPP_FILES=$(wildcard *.cpp)
BIN_FILES=$(patsubst %.cpp, %.exe, ${CPP_FILES})

all:$(BIN_FILES)
%.exe: %.cpp
	@echo Compiling $<
	g++ $(CXX_FLAGS) $< -g -o $@
%upr:%.cpp
	g++ $?  -o $@