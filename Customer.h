#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <iostream>
#include <thread>

class Customer {
public:
    Customer();
    ~Customer();
    void StartDecreaseEmotion();
    void StopDecreaseEmotion();
    void SetEmotionToMax();
    int GetEmotion();

private:
    int emotionValue;
    float waitTime;
    bool isDecreasing;
    std::thread emotionThread;
};

#endif // CUSTOMER_H
