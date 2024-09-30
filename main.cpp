#include <iostream>
#include <ctime>
#include <cstdlib>
#include "Waiter.h"

int main() {
    srand(static_cast<unsigned>(time(0)));

    Kitchen kitchen;
    Table table;
    Customer customer;
    Waiter waiter(kitchen);

    waiter.AssignCustomerToTable(customer, table);
    waiter.TakeOrder(table);  // Take first order
    waiter.TakeOrder(table);  // Take second order (if any)
    waiter.DeliverOrderToCustomer(table, customer);  // Deliver the order to the customer

    std::this_thread::sleep_for(std::chrono::seconds(6));  // Allow some time for emotion decrease

    customer.StopDecreaseEmotion();  // Stop decreasing emotion when done
    return 0;
}
