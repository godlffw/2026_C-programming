#pragma once

#include <iostream>

class OutputDevice {
public:
    OutputDevice() {
        std::cout << "OutputDevice constructor\n";
        // TODO: print "OutputDevice constructor"
    }

    virtual ~OutputDevice() {
        std::cout << "OutputDevice destructor\n";
        // TODO: print "OutputDevice destructor"
    }

    virtual void out() const = 0;
};
