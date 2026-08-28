#pragma once

#include "Monitor.h"

class LED_Monitor : public Monitor {
public:
    LED_Monitor():Monitor() {
        std::cout << "LED_Monitor constructor\n";
        // TODO: print "LED_Monitor constructor"
    }

    ~LED_Monitor() override {
        std::cout << "LED_Monitor destructor\n";
        // TODO: print "LED_Monitor destructor"
    }

    void out() const override {
        std::cout << "LED_Monitor rendering\n";
        // TODO: print "LED_Monitor rendering"
    }
};
