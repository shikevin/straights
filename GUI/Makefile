CXX=g++
CXXFLAGS = -Wall -O -g `pkg-config gtkmm-2.4 --cflags --libs`
OBJS = deckGUI.o mainwindow.o main.o playerhandview.o ScoreBoardView.o Card.o tableview.o HeaderView.o
DEPENDS=$(OBJS:.o=.d)
EXEC = other
${EXEC}: $(OBJS)
	   $(CXX) $(OBJS) $(CXXFLAGS) -o $(EXEC)
-include $(DEPENDS)
clean:
	rm ${EXEC} ${OBJS} ${DEPENDS}
