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

    // make an array of four toll booth lanes
    const int NUM_LANES = 4;
    deque<Car> tollLanes[NUM_LANES];

    // add two cars to each lane
for (int lane = 0; lane < NUM_LANES; lane++) {
    for (int i = 0; i < INITIAL_CARS; i++) {
        tollLanes[lane].push_back(Car());
    }
}

// display the initial queue
cout << "Initial queue:" << endl;

for (int lane = 0; lane < NUM_LANES; lane++) {
    cout << "Lane " << lane + 1 << ":" << endl;

    for (Car& car : tollLanes[lane]) {
        car.print();
    }
}

return 0;
}