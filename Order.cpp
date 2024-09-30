#include "Order.h"
#include <iostream>
#include <cstdlib>

Order::Order() : orderName("") {}

void Order::RandomOrderName() {
    std::string orderList[5] = { "Nasi Goreng", "Mie Goreng", "Ayam Goreng", "Sate Ayam", "Bakso" };
    orderName = orderList[rand() % 5];
}

bool Order::empty() const {
    return orderName.empty();
}

void Order::displayOrder() const {
    if (!empty()) {
        std::cout << "Order: " << orderName << std::endl;
    }
}

std::string Order::getOrderName() const {
    return orderName;
}

void Order::clearOrder() {
    orderName = "";
}
