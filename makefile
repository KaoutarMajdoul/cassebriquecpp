CXX= g++


all : jeu


JeuCB.o : JeuCB.cpp window.h niveau1.h niveau2.h niveau3.h initball.o
	$(CXX) -c JeuCB.cpp -lncurses


window.o: window.cpp window.h
	$(CXX) -c window.cpp -lncurses

niveau1.o : niveau1.cpp niveau1.h
		$(CXX) -c niveau1.cpp -lncurses

niveau2.o : niveau2.cpp niveau2.h
	$(CXX) -c niveau2.cpp -lncurses

niveau3.o : niveau3.cpp niveau3.h
		$(CXX) -c niveau3.cpp -lncurses


initball.o : initball.cpp initball.h
	$(CXX) -c initball.cpp -lncurses


jeu: window.o  JeuCB.o niveau1.o niveau2.o niveau3.o initball.o
		$(CXX) JeuCB.o window.o niveau1.o niveau2.o niveau3.o initball.o -o jeu -lncurses
