#ifndef ORDER_H
#define ORDER_H

#include <string>

class Order {
public:
    Order();
    void RandomOrderName();
    bool empty() const;
    void displayOrder() const;
    std::string getOrderName() const;
    void clearOrder();

private:
    std::string orderName;
};

#endif // ORDER_H
