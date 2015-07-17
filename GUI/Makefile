CXX=g++
CXXFLAGS = -Wall -O -g `pkg-config gtkmm-2.4 --cflags --libs`
<<<<<<< HEAD
OBJS = DeckGUI.o mainwindow.o main.o playerhandview.o ScoreBoardView.o HeaderView.o
EXEC = other

$(EXEC): $(OBJS)
	$(CXX) $(OBJS) $(CXXFLAGS) -o $(EXEC)

DeckGUI.o: DeckGUI.h DeckGUI.cc
mainwindow.o: mainwindow.h mainwindow.cc playerhandview.h HeaderView.h 
main.o: mainwindow.h main.cc
playerhandview.o: playerhandview.h playerhandview.cc
ScoreBoardView.o: ScoreBoardView.h ScoreBoardView.cpp
HeaderView.o: HeaderView.h HeaderView.cpp

=======
OBJS = DeckGUI.o mainwindow.o main.o playerhandview.o ScoreBoardView.o
DEPENDS=$(OBJS:.o=.d)
EXEC = other
${EXEC}: $(OBJS)
	   $(CXX) $(OBJS) $(CXXFLAGS) -o $(EXEC)
-include $(DEPENDS)
>>>>>>> 21ca15834ccd6b5372c93f35f438a97b4fc8434f
clean:
	rm ${EXEC} ${OBJS} ${DEPENDS}
