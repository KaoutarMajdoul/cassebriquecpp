CXX= g++


all : window


window: window.o test-piece.o  
	$(CXX) window.o test-piece.o -o window -lncurses




window.o: window.cpp window.h 
	$(CXX) -c window.cpp -lncurses



test-piece.o: test-piece.cpp window.h 
	$(CXX) -c test-piece.cpp -lncurses





	