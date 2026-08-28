#pragma once

#include "Monitor.h"

class LCD_Monitor : public Monitor {
public:
    LCD_Monitor() : Monitor() {
        std::cout <<"LCD_Monitor constructor\n";
        // TODO: print "LCD_Monitor constructor"
    }

    ~LCD_Monitor() override {
        std::cout << "LCD_Monitor destructor\n";
        // TODO: print "LCD_Monitor destructor\n";
    }

    void out() const override {
        std::cout << "LCD_Monitor rendering\n";
        // TODO: print "LCD_Monitor rendering"
    }
};
