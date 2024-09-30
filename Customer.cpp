#include "Customer.h"
#include <chrono>

Customer::Customer() : emotionValue(5), waitTime(0.0f), isDecreasing(false) {}

Customer::~Customer() {
    StopDecreaseEmotion();
}

void Customer::StartDecreaseEmotion() {
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

void Customer::StopDecreaseEmotion() {
    isDecreasing = false;
    if (emotionThread.joinable()) {
        emotionThread.join();
    }
}

void Customer::SetEmotionToMax() {
    emotionValue = 5;
}

int Customer::GetEmotion() {
    return emotionValue;
}
