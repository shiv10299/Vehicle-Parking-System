#include <iostream>
#include <vector>
#include <ctime>
#include <iomanip>
using namespace std;

struct Vehicle {
    string driverName;
    string vehicleNumber;
    string parkingSlot;
    time_t entryTime;
};

vector<Vehicle> parkingLot;

// Function to get the current time
string getCurrentTime() {
    time_t now = time(0);
    char* dt = ctime(&now);
    return string(dt);
}

// Function to add vehicle to the parking lot
void addVehicle() {
    Vehicle vehicle;
    cout << "Enter Driver's Name: ";
    cin >> vehicle.driverName;
    cout << "Enter Vehicle Number: ";
    cin >> vehicle.vehicleNumber;
    cout << "Enter Parking Slot: ";
    cin >> vehicle.parkingSlot;
    
    vehicle.entryTime = time(0);  // Store current time as entry time
    
    parkingLot.push_back(vehicle);
    cout << "Vehicle parked successfully!\n";
}

// Function to remove vehicle from parking lot
void removeVehicle() {
    string vehicleNumber;
    cout << "Enter Vehicle Number to remove: ";
    cin >> vehicleNumber;

    bool found = false;
    for (size_t i = 0; i < parkingLot.size(); ++i) {
        if (parkingLot[i].vehicleNumber == vehicleNumber) {
            found = true;
            cout << "Vehicle with number " << vehicleNumber << " removed from parking.\n";
            parkingLot.erase(parkingLot.begin() + i);
            break;
        }
    }
    if (!found) {
        cout << "Vehicle not found in parking lot.\n";
    }
}

// Function to display all parked vehicles
void displayParkedVehicles() {
    cout << setw(15) << "Driver Name" << setw(20) << "Vehicle Number" 
         << setw(15) << "Parking Slot" << setw(25) << "Entry Time\n";
    cout << string(75, '-') << "\n";

    for (const auto& vehicle : parkingLot) {
        cout << setw(15) << vehicle.driverName 
             << setw(20) << vehicle.vehicleNumber 
             << setw(15) << vehicle.parkingSlot 
             << setw(25) << getCurrentTime();  // Print the entry time
    }
}

int main() {
    int choice;
    do {
        cout << "\n--- Vehicle Parking System ---\n";
        cout << "1. Park Vehicle\n";
        cout << "2. Remove Vehicle\n";
        cout << "3. Display Parked Vehicles\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addVehicle();
                break;
            case 2:
                removeVehicle();
                break;
            case 3:
                displayParkedVehicles();
                break;
            case 4:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 4);

    return 0;
}
