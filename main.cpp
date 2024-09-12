#include <iostream>
#include <chrono>
#include <thread>
#include <cstdlib>
#include <ctime>

class Customer; // Forward declaration

class Customer {
public:
    Customer() : emotionValue(5), waitTime(0.0f), isDecreasing(false) {}

    ~Customer() {
        StopDecreaseEmotion();
    }

    void StartDecreaseEmotion() {
        isDecreasing = true;
        emotionThread = std::thread([this]() {
            while (isDecreasing) {
                std::this_thread::sleep_for(std::chrono::seconds(1));
                if (emotionValue > 0) {
                    emotionValue--;
                    std::cout << "Emotion value decreased to: " << emotionValue << std::endl;
                }
            }
        });
    }

    void StopDecreaseEmotion() {
        isDecreasing = false;
        if (emotionThread.joinable()) {
            emotionThread.join();
        }
    }

    void SetEmotionToMax() {
        emotionValue = 5;
    }

    int GetEmotion() {
        return emotionValue;
    }

private:
    int emotionValue;
    float waitTime;
    bool isDecreasing;
    std::thread emotionThread;
};

class Table {
public:
    enum class OrderStatus { NotYetTaken, InKitchen, Served };
    Table() : currentOrderStatus(OrderStatus::NotYetTaken), currentCustomer(nullptr) {}

    void DisplayOrder() {
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

    void UpdateOrderStatus(OrderStatus status) {
        currentOrderStatus = status;
        DisplayOrder();
    }

    void SetCustomer(Customer& customer) {
        currentCustomer = &customer;
        if (currentCustomer) {
            currentCustomer->StartDecreaseEmotion();  // Start decreasing customer emotion when they are seated.
            DisplayCustomerEmotion();
        }
    }

    void DisplayCustomerEmotion() {
        if (currentCustomer) {
            std::cout << "Customer emotion: " << currentCustomer->GetEmotion() << std::endl;
        }
        else {
            std::cout << "No customer assigned to the table." << std::endl;
        }
    }

private:
    OrderStatus currentOrderStatus;
    Customer* currentCustomer;
};

class Order {
public:
    Order() : orderName("") {}

    void RandomOrderName() {
        std::string orderList[5] = { "Nasi Goreng", "Mie Goreng", "Ayam Goreng", "Sate Ayam", "Bakso" };
        orderName = orderList[rand() % 5];
    }

    bool empty() const {
        return orderName.empty();
    }

    void displayOrder() const {
        if (!empty()) {
            std::cout << "Order: " << orderName << std::endl;
        }
    }

    std::string getOrderName() const {
        return orderName;
    }

    void clearOrder() {
        orderName = "";
    }

private:
    std::string orderName;
};


class Kitchen {
public:
    Kitchen() : orderInKitchen(nullptr) {}

    void PrepareOrder(Order& order) {
        orderInKitchen = &order;
        std::cout << "Preparing order: " << order.getOrderName() << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(3));  // Simulate cooking time
        std::cout << "Order: " << order.getOrderName() << " is ready!" << std::endl;
        order.clearOrder();  // Clear the order after cooking
        orderInKitchen = nullptr;
    }

    bool IsOrderReady() const {
        return orderInKitchen == nullptr;
    }

private:
    Order* orderInKitchen;
};

class Waiter {
public:
    Waiter(Kitchen& kitchen) : kitchen(kitchen) {}

    void TakeOrderStatus(Table& table) {
        table.UpdateOrderStatus(Table::OrderStatus::InKitchen);
    }

    void DeliverOrder(Table& table, Customer& customer) {
        table.UpdateOrderStatus(Table::OrderStatus::Served);
        customer.SetEmotionToMax();
    }

    void AssignCustomerToTable(Customer& customer, Table& table) {
        table.SetCustomer(customer);
    }

    void TakeOrder(Table& table) {
        if (orderMain.empty()) {
            std::cout << "Assigning main order...\n";
            orderMain.RandomOrderName();
            orderMain.displayOrder();
            TakeOrderStatus(table);  // Update table status to "InKitchen"
            kitchen.PrepareOrder(orderMain);  // Send order to kitchen
        }
        else if (orderSecondary.empty()) {
            std::cout << "Assigning secondary order...\n";
            orderSecondary.RandomOrderName();
            orderSecondary.displayOrder();
        }
        else {
            std::cout << "Both orders are full." << std::endl;
        }
    }

    void DeliverOrderToCustomer(Table& table, Customer& customer) {
        if (!kitchen.IsOrderReady()) {
            std::cout << "Order is still being prepared in the kitchen!" << std::endl;
        } else {
            std::cout << "Delivering order to customer." << std::endl;
            DeliverOrder(table, customer);
        }
    }

private:
    Order orderMain;
    Order orderSecondary;
    Kitchen& kitchen;
};

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