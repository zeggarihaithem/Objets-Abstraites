CPP=g++ --std=c++11
CFLAGS= -Wall

all : objetAbstraites

objetAbstraites : main.o ObjetAbst.o ObjetAtomique.o ObjetCompose.o
	$(CPP) $(CFLAGS) -o $@ $^

main.o : main.cpp
	$(CPP) $(CFLAGS) -c $<

ObjetCompose.o : ObjetCompose.cpp ObjetCompose.hpp
	$(CPP) $(CFLAGS) -c $<

ObjetAtomique.o : ObjetAtomique.cpp ObjetAtomique.hpp
	$(CPP) $(CFLAGS) -c $<

ObjetAbst.o : ObjetAbst.cpp ObjetAbst.hpp
	$(CPP) $(CFLAGS) -c $<

clean :
	rm *.o

test: all
	./objetAbstraites