#ifndef __SUBJECT_H
#define __SUBJECT_H

#include "component.h"
#include <vector>

class ViewComponent;
class Subject {
public:
    void subscribe(ViewComponent*);

protected:
    void notify();
    std::vector<ViewComponent*> myViewComponents;

private:
};

#endif
