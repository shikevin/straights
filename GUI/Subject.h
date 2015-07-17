#ifndef _SUBJECT_
#define _SUBJECT_

#include "Component.h"
#include <vector>


class Subject {
public:
    void subscribe(Component*);

protected:
    void notify();

private:
    std::vector<Component*> myViewComponents;
};

#endif
