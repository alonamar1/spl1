#include "Facility.h"

FacilityType::FacilityType(const string &name, const FacilityCategory category, const int price, const int lifeQuality_score, const int economy_score, const int environment_score)
: name(name), category(category), price(price), lifeQuality_score(lifeQuality_score), economy_score(economy_score), environment_score(environment_score) {}

const string& FacilityType::getName() const {
    return name;
}
int FacilityType::getCost() const {
    return price;
}
int FacilityType::getLifeQualityScore() const {
    return lifeQuality_score;
}
int FacilityType::getEnvironmentScore() const {
    return environment_score;
}
int FacilityType::getEconomyScore() const {
    return economy_score;
}
FacilityCategory FacilityType::getCategory() const {
    return category;
}

Facility::Facility(const string &name, const string &settlementName, const FacilityCategory category, const int price, const int lifeQuality_score, const int economy_score, const int environment_score)
: FacilityType(name, category, price, lifeQuality_score, economy_score, environment_score), settlementName(settlementName), status(FacilityStatus::UNDER_CONSTRUCTIONS), timeLeft(price)  {}

Facility::Facility(FacilityType &type, const string &settlementName) 
: FacilityType(type.getName(), type.getCategory(), type.getCost(), type.getLifeQualityScore(), type.getEconomyScore(), type.getEnvironmentScore()), settlementName(settlementName), status(FacilityStatus::UNDER_CONSTRUCTIONS), timeLeft(type.getCost()) {}

const string& Facility::getSettlementName() const {
    return settlementName;
}
const int Facility::getTimeLeft() const {
    return timeLeft;
}
FacilityStatus Facility::step() {
    timeLeft--;
    if (timeLeft == 0) {
        Facility::setStatus(FacilityStatus::OPERATIONAL);
    }
    return getStatus();
}
void Facility::setStatus(FacilityStatus status) {
    Facility::status = status;
}
const FacilityStatus& Facility::getStatus() const {
    return status;
}
const string Facility::toString() const {
    string cat;
    string stat;
    if (getCategory() == FacilityCategory::LIFE_QUALITY)
        cat = "Life Quality";
    if (getCategory() == FacilityCategory::ECONOMY)
        cat = "Economy";
    if (getCategory() == FacilityCategory::ENVIRONMENT)
        cat = "Environment";
    if (getStatus() == FacilityStatus::OPERATIONAL)
        stat = "Operational";
    if (getStatus() == FacilityStatus::UNDER_CONSTRUCTIONS)
        stat = "Under Construction";
    //return "Facility Name: " + name + ", Settlement Name: " + settlementName + ", Category: " + FacilityCategory:: + ", "
    return   "Facility: " + getName() 
             + "\nCategory: " + cat
             + "\nCost: " + std::to_string(getCost()) 
             + "\nLife Quality Score: " + std::to_string(getLifeQualityScore())
             + "\nEconomy Score: " + std::to_string(getEconomyScore())
             + "\nEnvironment Score: " + std::to_string(getEnvironmentScore())
             + "\nSettlement: " + settlementName
             + "\nStatus: " + stat
             + "\nTime Left: " + std::to_string(timeLeft);

}




