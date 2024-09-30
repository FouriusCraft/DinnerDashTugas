#include "Table.h"
#include <iostream>

Table::Table() : currentOrderStatus(OrderStatus::NotYetTaken), currentCustomer(nullptr) {}

void Table::DisplayOrder() {
    switch (currentOrderStatus) {
        case OrderStatus::NotYetTaken:
            std::cout << "Order status: Not Yet Taken" << std::endl;
        break;
        case OrderStatus::InKitchen:
            std::cout << "Order status: In Kitchen" << std::endl;
        break;
        case OrderStatus::Served:
            std::cout << "Order status: Served" << std::endl;
        break;
    }
}

void Table::UpdateOrderStatus(OrderStatus status) {
    currentOrderStatus = status;
    DisplayOrder();
}

void Table::SetCustomer(Customer& customer) {
    currentCustomer = &customer;
    if (currentCustomer) {
        currentCustomer->StartDecreaseEmotion();
        DisplayCustomerEmotion();
    }
}

void Table::DisplayCustomerEmotion() {
    if (currentCustomer) {
        std::cout << "Customer emotion: " << currentCustomer->GetEmotion() << std::endl;
    } else {
        std::cout << "No customer assigned to the table." << std::endl;
    }
}
