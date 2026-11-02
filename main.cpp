// COMSC 210 | Lab 32 | Yeji Kim

#include <iostream>
#include <deque>
#include "Car.h"
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    srand(time(0));
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

    int time = 0;

while (!tollLane.empty()) {
    time++;

    int probability = rand() % 100 + 1;

    cout << "\nTime: " << time;

    if (probability <= 55) {
        // Front car pays and leaves.
        cout << " Operation: Car paid: ";
        tollLane.front().print();
        tollLane.pop_front();
    }
    else {
        // A new car joins the back.
        Car newCar;
        tollLane.push_back(newCar);

        cout << " Operation: Joined lane: ";
        newCar.print();
    }

    cout << "Queue:" << endl;

    if (tollLane.empty()) {
        cout << "    Empty" << endl;
    }
    else {
        for (Car& car : tollLane) {
            car.print();
        }
    }
}

    // exercise deque methods
    cout << "\nNumber of cars: " << tollLane.size() << endl;

    cout << "First car:" << endl;
    tollLane.front().print();

    cout << "Last car:" << endl;
    tollLane.back().print();

    return 0;
}