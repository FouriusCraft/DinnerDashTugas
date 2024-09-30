#ifndef KITCHEN_H
#define KITCHEN_H

#include "Order.h"

class Kitchen {
public:
    Kitchen();
    void PrepareOrder(Order& order);
    bool IsOrderReady() const;

private:
    Order* orderInKitchen;
};

#endif // KITCHEN_H
