#ifndef _SUBJECT_
#define _SUBJECT_

#include "component.h"
#include <vector>

class ViewComponent;

class Subject {
public:
    void subscribe(ViewComponent*);

protected:
    void notify();

private:
    std::vector<ViewComponent*> myViewComponents;
};

#endif
