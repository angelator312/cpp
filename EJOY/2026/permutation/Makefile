# Configure CPP compilation flags
CXX_FLAGS=


CPP_FILES=$(wildcard *Grader.cpp)
BIN_FILES=$(patsubst %.cpp,%.exe,${CPP_FILES})

all: $(BIN_FILES)

%Grader.exe: %Grader.cpp %.cpp
	g++ $(CXX_FLAGS) $? -g -o $@

.PHONY: clean
clean:
	rm -f *.exe
