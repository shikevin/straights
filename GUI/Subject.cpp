#include "Subject.h"
using namespace std;

void Subject::subscribe(ViewComponent* newComponent) {
	myViewComponents.push_back(newComponent);
}

void Subject::notify() {
	for(int i = 0; i < myViewComponents.size(); i++) {
		myViewComponents[i]->updateView();
	}
}
