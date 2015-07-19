#include "mainwindow.h"
#include <iostream>
#include <gtkmm/box.h>
#include "Card.h"
#include <gtkmm/table.h>
#include "validate.h"

using namespace std;

MainWindow::MainWindow() {
    tableView = new TableView(&deck);
    handView = new PlayerHandView(&deck);
    headerView = new HeaderView();
    scoreView = new ScoreBoardView();
		
	// Sets the border width of the window.
	set_border_width( 25 );
		
	// Set the look of the frame.
	frame.set_label_align( Gtk::ALIGN_LEFT, Gtk::ALIGN_TOP );
	frame.set_shadow_type( Gtk::SHADOW_ETCHED_OUT );
    
   
	// Add the frame to the window. Windows can only hold one widget, same for frames.
	add( frame );

	mainBox.pack_start(*headerView->getHeaderView());
    mainBox.pack_start(*tableView->getViewBox());
	mainBox.pack_start(*scoreView->getScoreBox());
	mainBox.pack_start(*handView->getViewBox());

    components.push_back(dynamic_cast<ViewComponent*>(tableView));
    components.push_back(dynamic_cast<ViewComponent*>(scoreView));
    components.push_back(dynamic_cast<ViewComponent*>(handView));

	// Add the horizontal box for laying out the images to the frame.
	frame.add(mainBox);

	// The final step is to display this newly created widget.
	show_all();

    // THIS SHOULD WORK BUT IS SEGFAULTING
    // for (int i = 0; i < components.size(); i++) {
    //     components[i]->setMainWindow(this);
    // }
    tableView->setMainWindow(this);
    handView->setMainWindow(this);
    headerView->setMainWindow(this);
    scoreView->setMainWindow(this);
}

MainWindow::~MainWindow() {
    delete tableView;
    delete handView;
    delete headerView;
}

void MainWindow::startGame(int seed) {
    cout << "hasn't failed yet" << endl;
    string choices = invitePlayers();
    gameLogic = new TableController(seed, components);
    cout << "hasn't failed yet" << endl;
    gameLogic->playGame(choices);
}

string MainWindow::invitePlayers() {
    string choices = "";
    for (int i = 0; i < 4; i++) {
        string title = "Choose Type: Player " + to_string(i + 1);
        char type;
        do {
            cout << "fail 1" << endl;
            PlayerSelectionDialog selection(*this, title);
            cout << "fail 2" << endl;
            type = selection.getChoice();
        } while (type == 'n');
        cout << "Type for : " << i << " is "<< type << endl;
        choices += type;
    }
    return choices;
}

void MainWindow::playerCommand(Command command) {
    try {
        gameLogic->playerCommand(command);
    } catch (Validate::PlayerQuitException &e) {
        // handle quit
    } catch (Validate::LegalPlayExistsException &e) {
        // tell user to use the right card
    } catch (Validate::IllegalPlayException &e) {
        command.type = DISCARD;
        playerCommand(command);
    } catch (Validate::PrintDeckException &e) {
    }
}
