#ifndef TABLE_H
#define TABLE_H

#include "Customer.h"

class Table {
public:
    enum class OrderStatus { NotYetTaken, InKitchen, Served };
    Table();
    void DisplayOrder();
    void UpdateOrderStatus(OrderStatus status);
    void SetCustomer(Customer& customer);
    void DisplayCustomerEmotion();

private:
    OrderStatus currentOrderStatus;
    Customer* currentCustomer;
};

#endif // TABLE_H
