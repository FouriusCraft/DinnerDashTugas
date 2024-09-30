#include "Kitchen.h"
#include <iostream>
#include <thread>
#include <chrono>

Kitchen::Kitchen() : orderInKitchen(nullptr) {}

void Kitchen::PrepareOrder(Order& order) {
    orderInKitchen = &order;
    std::cout << "Preparing order: " << order.getOrderName() << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(3));  // Simulate cooking time
    std::cout << "Order: " << order.getOrderName() << " is ready!" << std::endl;
    order.clearOrder();  // Clear the order after cooking
    orderInKitchen = nullptr;
}

bool Kitchen::IsOrderReady() const {
    return orderInKitchen == nullptr;
}
