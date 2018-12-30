CXX= g++


all : jeu

# window.o: window.cpp window.h
# 	$(CXX) -c window.cpp -lncurses

JeuCB.o : JeuCB.cpp
	$(CXX) -c JeuCB.cpp -lncurses


jeu: JeuCB.o
		$(CXX) JeuCB.o -o jeu -lncurses
