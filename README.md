# DinnerDashTugas
 
Restaurant Simulation System
This project simulates a simple restaurant management system in C++. It includes classes representing a Customer, Table, Order, Kitchen, and Waiter, and demonstrates how these components interact with each other to simulate the process of taking orders, preparing them in the kitchen, and serving them to customers.

Features
Customer Emotion Management:

The customer's emotion decreases over time while waiting.
The emotion resets when the order is served.
Order Handling:

The Waiter takes orders and sends them to the Kitchen.
The Kitchen prepares the order and notifies when it's ready.
Threading:

The project uses threading to handle the decrement of the customer's emotion over time.
Classes
Customer
Manages the emotion of a customer, including a method to decrease the emotion over time.
Methods:
StartDecreaseEmotion(): Starts a thread that decreases the emotion value every second.
StopDecreaseEmotion(): Stops the emotion-decreasing thread.
SetEmotionToMax(): Resets the emotion value to its maximum.
GetEmotion(): Returns the current emotion value.
Table
Tracks the order status and associates a customer with the table.
Methods:
DisplayOrder(): Displays the current order status.
UpdateOrderStatus(OrderStatus status): Updates the order status of the table.
SetCustomer(Customer& customer): Associates a customer with the table and starts decreasing their emotion.
DisplayCustomerEmotion(): Displays the current emotion of the customer.
Order
Represents an order that can be placed by a customer.
Methods:
RandomOrderName(): Randomly selects a dish name for the order.
displayOrder(): Displays the order details.
clearOrder(): Clears the order details.
Kitchen
Handles the preparation of orders.
Methods:
PrepareOrder(Order& order): Prepares the order and clears it after it's ready.
IsOrderReady(): Checks if the kitchen is ready for a new order.
Waiter
Manages interactions between the Customer, Table, and Kitchen.
Methods:
TakeOrderStatus(Table& table): Updates the table’s status to indicate that the order is in the kitchen.
DeliverOrder(Table& table, Customer& customer): Delivers the order and resets the customer's emotion.
AssignCustomerToTable(Customer& customer, Table& table): Assigns a customer to a table.
TakeOrder(Table& table): Takes an order and sends it to the kitchen for preparation.
DeliverOrderToCustomer(Table& table, Customer& customer): Delivers the prepared order to the customer.
How to Run
Clone this repository.
bash
Salin kode
git clone https://github.com/your-username/restaurant-simulation.git
Navigate to the project directory.
bash
Salin kode
cd restaurant-simulation
Compile the program.
bash
Salin kode
g++ -std=c++11 -pthread -o restaurant_simulation main.cpp
Run the executable.
bash
Salin kode
./restaurant_simulation
Example Output
bash
Salin kode
Assigning main order...
Order: Nasi Goreng
Order status: In Kitchen
Preparing order: Nasi Goreng
Emotion value decreased to: 4
Order: Nasi Goreng is ready!
Delivering order to customer.
Order status: Served
Customer emotion: 5
Future Improvements
Implement a graphical user interface (GUI) to visualize the restaurant simulation.
Add more detailed customer behavior, such as leaving if the wait is too long.
Expand the menu and allow customers to choose specific dishes.
Include multiple tables and allow the waiter to manage more complex scenarios
