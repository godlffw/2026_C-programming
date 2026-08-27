#include <iomanip>
#include <iostream>

int main() {
    const int baseGold = 1000;
    int minionGold = 0;
    std::cin >> minionGold;
    int total = baseGold + minionGold;
    double avg = (double)total / 2.00;
    std::cout << "Total Gold: " << total << std::endl;

    std::cout << "Average GOld: " << std::fixed<< std::setprecision(2) << avg << std::endl;
    if (total >= 4000) {
        std::cout << "Item Purchase Available" << std::endl;
    }

    else {
        std::cout <<"More Gold Needed" << std::endl;
    }
    // TODO: Calculate totalGold and averageGold, then print the final status based on totalGold >= 4000.
    return 0;
}
