CMP = g++
MAIN = invaderstest
CLASS = invaders
EXEC = invaderstest

$(EXEC): $(MAIN).o $(CLASS).o
	$(CMP) $(MAIN).o gfxnew_restrictive.o -lX11 -std=c++11 -o $(CLASS).o -o $(EXEC)

$(MAIN).o: $(CLASS).h $(MAIN).cpp
	$(CMP) -c $(MAIN).cpp -std=c++11 -o $(MAIN).o

$(CLASS).o: $(CLASS).h $(CLASS).cpp
	$(CMP) -c $(CLASS).cpp -std=c++11 -o $(CLASS).o

clean:
	rm $(EXEC)

