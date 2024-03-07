CXX_FLAGS=

CPP_FILES=$(wildcard *.cpp)
BIN_FILES=$(patsubst %.cpp, %.exe, ${CPP_FILES})

all:$(BIN_FILES)
loaderupr:loader2022.cpp
	g++ loader2022.cpp -o loaderupr 
bnumupr:bnum.cpp
	g++ bnum.cpp -o bnumupr 
palupr:pal2022.cpp
	g++ pal2022.cpp  -o palupr 
teamsupr:teams2021.cpp
	g++ teams2021.cpp  -o teamsupr 
svetofarsupr:sfetofars2021.cpp
	g++ sfetofars2021.cpp  -o svetofarsupr
cutupr:cuts.cpp
	g++ cuts.cpp  -o cutupr 
beautifulupr:beautiful.cpp
	g++ beautiful.cpp -o beautifulupr 
balupr:ball.cpp
	g++ ball.cpp  -o balupr 
ballanceupr:ballance.cpp
	g++ ballance.cpp  -o ballanceupr 
sequenceupr:sequence.cpp
	g++ sequence.cpp  -o sequenceupr 
oddupr:odd-baven.cpp
	g++ odd-baven.cpp  -o oddupr
credupr:cred.cpp
	g++ cred.cpp  -o credupr
sheepupr:sheep.cpp
	g++ sheep.cpp  -o sheepupr
partyupr:party.cpp
	g++ party.cpp  -o partyupr
pairsupr:pairs.cpp
	g++ pairs.cpp  -o pairsupr
NOI-3.2016.E2.5upr:NOI-3.2016.E2.5r.cpp
	g++ NOI-3.2016.E2.5r.cpp  -o NOI-3.2016.E2.5upr
sequpr:seq.cpp
	g++ seq.cpp  -o sequpr
Eratostenupr:Eratosten.cpp
	g++ Eratosten.cpp  -o Eratostenupr
zad_za_Ganevaupr:Zad_za_Ganeva.cpp
	g++ Zad_za_Ganeva.cpp  -o zad_za_Ganevaupr
digits-3upr:digits-3.cpp
	g++ digits-3.cpp  -o digits-3upr
flowersupr:flowers.cpp
	g++ flowers.cpp  -o flowersupr
teacherupr:teacher.cpp
	g++ teacher.cpp  -o teacherupr
palindromesupr:palindromes.cpp
	g++ palindromes.cpp  -o palindromesupr
monoeupr:monoe.cpp
	g++ monoe.cpp  -o monoeupr
ISBNupr:ISBN.cpp
	g++ ISBN.cpp  -o ISBNupr
%.exe: %.cpp
	@echo Compiling $<
	g++ $(CXX_FLAGS) $< -g -o $@
%upr:%.cpp
	g++ $?  -o $@