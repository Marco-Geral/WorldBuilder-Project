#include "Office.h"
#include <iostream>

Office::Office(int numEmployees, string businessType, int x, int y, const std::string& district, int quality)
    : CommercialBuildings(x, y, district, quality, businessType, 1), numEmployees(numEmployees) {
		this->construct();
	}
//int x, int y, const std::string& district, int quality, const std::string& business, int num
int Office::getNumEmployees() {
    return this->numEmployees;
}

std::string Office::getBuildingType() {
    return "Office";
}

double Office::getCost() {
    return 3000000;
}

double Office::getMaintenanceCost() {
    const double maintenanceRate = 0.02; // 2% of the cost per month
    return getCost() * maintenanceRate;
}

double Office::getEnergyConsumption() {
    // Assuming each employee consumes 300 kWh per month
    const double energyPerEmployee = 300.0;
    return energyPerEmployee * getNumEmployees();
}

double Office::getWaterConsumption() {
    // Assuming each employee uses 1500 liters of water per month
    const double waterPerEmployee = 1500.0;
    return waterPerEmployee * getNumEmployees();
}

void Office::construct() {
    std::cout << "Constructing an office building for " << numEmployees 
              << " employees " << std::endl;
}

void Office::demolish() {
    std::cout << "The office building is being demolished." << std::endl;
    numEmployees = 0;     // Reset number of employees to represent demolition
}

double Office::getArea() {
	return getX() * getY();
}

int Office::getOccupancy(){
	return 150;
}

void Office::upgrade(std::shared_ptr<BuildingComponent> building) {
    auto government = Government::getInstance();
    
    // Example resource requirements for upgrading
    const int requiredConcrete = 100;
    const int requiredSteel = 50;

    // Request resources from Government
    bool hasConcrete = government->useResource("Concrete", requiredConcrete);
    bool hasSteel = government->useResource("Steel", requiredSteel);

    if (hasConcrete && hasSteel) {
        // Perform upgrade logic if resources are available
        quality += 10;  // Example improvement in quality
        std::cout << "Estate upgraded successfully!" << std::endl;
    } else {
        std::cout << "Upgrade failed due to insufficient resources." << std::endl;
    }
}