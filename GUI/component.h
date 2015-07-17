#ifndef __COMPONENT_H
#define __COMPONENT_H

class Component {
public:
	Component();
    virtual ~Component() {};
    virtual void updateView() = 0;
	
private:
};

#endif
