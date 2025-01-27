#ifndef WAREHOUSE_H
#define WAREHOUSE_H

#include "IndustrialBuildings.h"
#include <memory> // Include for smart pointers
#include "Government.h"
class Warehouse : public IndustrialBuildings { // Class name is retained as "Warehouse"

private:
    int storageCapacity; // Storage capacity of the warehouse

public:
    // Constructor that initializes the base class with additional parameters
    Warehouse(int x, int y, const std::string& district, int quality, int storageCapacity, int numWorkers);

    double getStorageCapacity();
    std::string getBuildingType();
    double getCost();
    double getMaintenanceCost();
    double getEnergyConsumption();
    double getWaterConsumption();
    void construct();
    void demolish();
    double getArea();
    void upgrade(std::shared_ptr<BuildingComponent> building); // Changed to smart pointer
    int getOccupancy();
};

#endif
