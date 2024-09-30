#include "Waiter.h"
#include <iostream>

Waiter::Waiter(Kitchen& kitchen) : kitchen(kitchen) {}

void Waiter::TakeOrderStatus(Table& table) {
    table.UpdateOrderStatus(Table::OrderStatus::InKitchen);
}

void Waiter::DeliverOrder(Table& table, Customer& customer) {
    table.UpdateOrderStatus(Table::OrderStatus::Served);
    customer.SetEmotionToMax();
}

void Waiter::AssignCustomerToTable(Customer& customer, Table& table) {
    table.SetCustomer(customer);
}

void Waiter::TakeOrder(Table& table) {
    if (orderMain.empty()) {
        std::cout << "Assigning main order...\n";
        orderMain.RandomOrderName();
        orderMain.displayOrder();
        TakeOrderStatus(table);
        kitchen.PrepareOrder(orderMain);
    } else if (orderSecondary.empty()) {
        std::cout << "Assigning secondary order...\n";
        orderSecondary.RandomOrderName();
        orderSecondary.displayOrder();
    } else {
        std::cout << "Both orders are full." << std::endl;
    }
}

void Waiter::DeliverOrderToCustomer(Table& table, Customer& customer) {
    if (!kitchen.IsOrderReady()) {
        std::cout << "Order is still being prepared in the kitchen!" << std::endl;
    } else {
        std::cout << "Delivering order to customer." << std::endl;
        DeliverOrder(table, customer);
    }
}
