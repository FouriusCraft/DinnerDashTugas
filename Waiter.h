#ifndef WAITER_H
#define WAITER_H

#include "Table.h"
#include "Kitchen.h"

class Waiter {
public:
    Waiter(Kitchen& kitchen);
    void TakeOrderStatus(Table& table);
    void DeliverOrder(Table& table, Customer& customer);
    void AssignCustomerToTable(Customer& customer, Table& table);
    void TakeOrder(Table& table);
    void DeliverOrderToCustomer(Table& table, Customer& customer);

private:
    Order orderMain;
    Order orderSecondary;
    Kitchen& kitchen;
};

#endif // WAITER_H
