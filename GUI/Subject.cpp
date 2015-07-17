#include "Subject.cpp"
using namespace std;

Subject::subscribe(Component* newComponent) {
	myViewComponents.push_back(newComponent);
}

Subject::notify() {
	for(int i = 0; i < myViewComponents.size(); i++) {
		myViewComponents[i]->updateView();
	}
}