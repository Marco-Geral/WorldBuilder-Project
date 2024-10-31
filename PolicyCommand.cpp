#include "PolicyCommand.h"

/**
 * @brief Constructs a PolicyCommand with a specified building and policy type.
 * @param b Pointer to the BuildingComposite on which the policy will be enforced.
 * @param policy The type of policy to enforce.
 */
PolicyCommand::PolicyCommand(std::shared_ptr<BuildingComposite> district, std::shared_ptr<Government> government, const std::string& policyType, const std::string& updatedValue)
        : district(std::move(district)), government(std::move(government)), policyType(policyType), updatedValue(updatedValue) {}

/**
 * @brief Executes the policy command, enforcing the specified policy on the building.
 * @note The `enforcePolicy` method in BuildingComposite is not yet implemented.
 */
void PolicyCommand::execute() {
    // Update policy in BuildingComposite
    district->enforcePolicy(policyType, updatedValue);

    // If the policy being updated is "tax rate", update it in Government
    if (policyType == "tax rate") {
        government->setTaxRatePolicy(updatedValue);
    }
}