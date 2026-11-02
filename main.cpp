// COMSC 210 | Lab 32 | Yeji Kim

#include <iostream>
#include <deque>
#include "Car.h"

using namespace std;

int main() {
    const int INITIAL_CARS = 2;

    // make the toll booth queue
    deque<Car> tollLane;

    // add two cars to the back of the queue
    for (int i = 0; i < INITIAL_CARS; i++) {
        tollLane.push_back(Car());
    }

    // display the initial queue
    cout << "Initial queue:" << endl;

    for (Car& car : tollLane) {
        car.print();
    }

    // exercise deque methods
    cout << "\nNumber of cars: " << tollLane.size() << endl;

    cout << "First car:" << endl;
    tollLane.front().print();

    cout << "Last car:" << endl;
    tollLane.back().print();

    return 0;
}