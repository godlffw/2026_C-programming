#pragma once

#include "OutputDevice.h"

class Monitor : public OutputDevice {
public:
    Monitor():OutputDevice() {
        std::cout << "Monitor constructor\n";
        // TODO: print "Monitor constructor\n";
    }

    ~Monitor() override {
        std::cout << "Monitor destructor\n";
        // TODO: print "Monitor destructor"
    }

    void out() const override {
        std::cout << "Monitor rendering\n";
        // TODO: print "Monitor rendering"
    }
};
