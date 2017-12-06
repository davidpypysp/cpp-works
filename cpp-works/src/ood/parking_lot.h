/*
n levels, each level has m rows of spots and each row has k spots.
So each level has m x k spots.

The parking lot can park motorcycles, cars and buses

The parking lot has motorcycle spots, compact spots, and large spots

Each row, motorcycle spots id is in range [0,k/4)(0 is included, k/4 is not included), 
compact spots id is in range [k/4,k3/4) and large spots id is in range [k3/4,k].

A motorcycle can park in any spot

A car park in single compact spot or large spot

A bus can park in five large spots that are consecutive and within same row.
it can not park in small spots

*/

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;


// enum type for Vehicle
enum class VehicleSize {
    Motorcycle,
    Compact,
    Large,
    Default
};

class Vehicle {
public:
    virtual VehicleSize size() {
        return VehicleSize::Default;
    }
};

class Bus: public Vehicle {
public:
    VehicleSize size() {
        return VehicleSize::Large;
    }
};

class Car: public Vehicle {
public:
    VehicleSize size() {
        return VehicleSize::Compact;
    }
};

class Motorcycle: public Vehicle {
public:
    VehicleSize size() {
        return VehicleSize::Motorcycle;
    }
};


class Level {
private: 
    vector<Vehicle*> motoSpots;
    vector<Vehicle*> compactSpots;
    vector<Vehicle*> largeSpots;
    unordered_map<Vehicle*, unordered_map<VehicleSize, int>> vehicle2spot;

public: 
    Level(int num_rows, int spots_per_row) {
        int motoSpotSize = spots_per_row / 4;
        motoSpots.resize(motoSpotSize);

        int compactSpotSize = spots_per_row * 3 / 4 - motoSpotSize;
        compactSpots.resize(compactSpotSize);

        int largeSpotSize = spots_per_row - spots_per_row * 3 / 4 + 1;
        largeSpots.resize(largeSpotSize);
    }

    int canParkVehicle(Vehicle *vehicle, VehicleSize size, int num) {
        if(size == VehicleSize::Motorcycle) {
            for(int i = 0; i < motoSpots.size(); i++) {
                if(compactSpots[i] == nullptr) {
                    return i;
                }
            }
            return -1;
        }
        else if(size == VehicleSize::Compact) {
            for(int i = 0; i < compactSpots.size(); i++) {
                if(compactSpots[i] == nullptr) {
                    return i;
                }
            }
            return -1;
        }
        else {
            for(int i = 0; i < largeSpots.size(); i++) {
                if(largeSpots[i] == nullptr) {
                    bool flag = true;
                    for(int j = i; j < i + num; j++) {
                        if(largeSpots[i] != nullptr) {
                            flag = false;
                            break;
                        }
                    }
                    if(flag) {
                        return i;
                    }
                }

            }
            return -1;
        }
    }


    void parkVehicle(Vehicle* vehicle, VehicleSize parkSpotType, int index, int num) {
        if(parkSpotType == VehicleSize::Motorcycle) {
            motoSpots[index] = vehicle;
        }
        else if(parkSpotType == VehicleSize::Compact) {
            compactSpots[index] = vehicle;
        }
        else {
            for(int i = index; i < index + num; i++) {
                largeSpots[i] = vehicle;
            }
        }
        vehicle2spot[vehicle][parkSpotType] = index;
    }

    void unParkVehicle(Vehicle *vehicle) {
        unordered_map<VehicleSize, int> spot = vehicle2spot[vehicle];
        VehicleSize size = vehicle->size();
        int index = spot[size];
        if(size == VehicleSize::Motorcycle) {
            motoSpots[index] = nullptr;
        }
        else if(size == VehicleSize::Compact) {
            compactSpots[index] = nullptr;
        }
        else {
            for(int i = index; i < largeSpots.size(); i++) {
                if(largeSpots[i] == vehicle) {
                    largeSpots[i] = nullptr;
                }
                else {
                    break;
                }
            }
        }
    }

};


class ParkingLot {
private: 
    vector<Level*> levels;
    unordered_map<Vehicle*, Level*> vehicle2level;

public: 
    ParkingLot(int n, int num_rows, int spots_per_row) {
        for(int i = 0; i < n; i++) {
            Level *level = new Level(num_rows, spots_per_row);
            levels.push_back(level);
        }
    }


    bool parkVehicle(Vehicle &vehicle) {
        VehicleSize size = vehicle.size();
        if(size == VehicleSize::Motorcycle) {
            cout << "Moto" << endl;
            if(!parkInMotoSpot(vehicle)) {
                if(!parkInCompactSpot(vehicle)) {
                    return parkInLargeSpot(vehicle, 1);
                }
            }
        }
        else if(size == VehicleSize::Compact) {
            cout << "Compact" << endl;
            if(!parkInCompactSpot(vehicle)) {
                return parkInLargeSpot(vehicle, 1);
            }
        }
        else if(size == VehicleSize::Large) {
            cout << "Bus" << endl;
            return parkInLargeSpot(vehicle, 5);
        }
        else {
            return false;
        }
    }


    bool parkInMotoSpot(Vehicle &vehicle) {
        for(int i = 0; i < levels.size(); i++) {
            int index = levels[i]->canParkVehicle(&vehicle, VehicleSize::Motorcycle, 1);
            if(index != -1) {
                levels[i]->parkVehicle(&vehicle, VehicleSize::Motorcycle, index, 1);
                vehicle2level[&vehicle] = levels[i];
                return true;
            }
        }
        return false;
    }

    bool parkInCompactSpot(Vehicle &vehicle) {
        for(int i = 0; i < levels.size(); i++) {
            int index = levels[i]->canParkVehicle(&vehicle, VehicleSize::Compact, 1);
            cout << index << endl;
            if(index != -1) {
                levels[i]->parkVehicle(&vehicle, VehicleSize::Compact, index, 1);
                vehicle2level[&vehicle] = levels[i];
                return true;
            }
            return false;
        }
    }

    bool parkInLargeSpot(Vehicle &vehicle, int num) {
        for(int i = 0; i < levels.size(); i++) {
            int index = levels[i]->canParkVehicle(&vehicle, VehicleSize::Large, num);
            if(index != -1) {
                levels[i]->parkVehicle(&vehicle, VehicleSize::Large, index, num);
                vehicle2level[&vehicle] = levels[i];
                return true;
            }
        }
        return false;
    }

    void unParkVehicle(Vehicle &vehicle) {
        Level *level = vehicle2level[&vehicle];
        if(level) {
            level->unParkVehicle(&vehicle);
        }
    }

};



