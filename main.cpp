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
    const int NUM_LANES = 4;
    const int SIMULATION_TIME = 20;

    // make an array of four toll booth lanes
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

// run the simulation for 20 time periods
for (int time = 1; time <= SIMULATION_TIME; time++) {
    cout << "\nTime: " << time << endl;

    // process each lane
    for (int lane = 0; lane < NUM_LANES; lane++) {
        int probability = rand() % 100 + 1;

        if (tollLanes[lane].empty()) {
            // empty lane: 50% chance a new car joins
            if (probability <= 50) {
                cout << "Lane: " << lane + 1 << " No operation" << endl;
            }
            else {
                Car newCar;
                tollLanes[lane].push_back(newCar);

                cout << "Lane: " << lane + 1 << " Joined: ";
                newCar.print();
            }
        }
        else {
            // occupied lane: 50% chance to pay or join
            if (probability <= 50) {
                cout << "Lane: " << lane + 1 << " Paid: ";
                tollLanes[lane].front().print();
                tollLanes[lane].pop_front();
            }
            else {
                Car newCar;
                tollLanes[lane].push_back(newCar);

                cout << "Lane: " << lane + 1 << " Joined: ";
                newCar.print();
            }
        }
    }

    // display all lane queues after processing every lane
    for (int lane = 0; lane < NUM_LANES; lane++) {
        cout << "Lane " << lane + 1 << " Queue:" << endl;

        if (tollLanes[lane].empty()) {
            cout << "    empty" << endl;
        }
        else {
            for (Car& car : tollLanes[lane]) {
                car.print();
            }
        }
    }
}
}