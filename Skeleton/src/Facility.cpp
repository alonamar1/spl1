#include "Facility.h"

        FacilityType::FacilityType(const string &name, const FacilityCategory category, const int price, const int lifeQuality_score, const int economy_score, const int environment_score):
         name(name), category(category), price(price), lifeQuality_score(lifeQuality_score), economy_score(economy_score), environment_score(environment_score) {}
        const string& FacilityType::getName() const 
        {
            return name;
        }
        int FacilityType::getCost() const 
        {
            return price;
        }
        int FacilityType::getLifeQualityScore() const
        {
            return lifeQuality_score;
        }
        int FacilityType::getEnvironmentScore() const
        {
            return environment_score;
        }
        int FacilityType::getEconomyScore() const
        {
            return economy_score;
        }
        FacilityCategory FacilityType::getCategory() const
        {
            return category;
        }

        Facility::Facility(const string &name, const string &settlementName, const FacilityCategory category, const int price, const int lifeQuality_score, const int economy_score, const int environment_score):
        FacilityType(name, category, price, lifeQuality_score, economy_score, environment_score), settlementName(settlementName), status(FacilityStatus::UNDER_CONSTRUCTIONS), timeLeft(price) {}
        Facility::Facility(FacilityType &type, const string &settlementName):
        FacilityType(type.getName(), type.getCategory(), type.getCost(), type.getLifeQualityScore(), type.getEconomyScore(), type.getEnvironmentScore()), settlementName(settlementName), status(FacilityStatus::UNDER_CONSTRUCTIONS), timeLeft(price) {}
        const string& Facility::getSettlementName() const
        {
            return settlementName;
        }
        const int Facility::getTimeLeft() const{
            return timeLeft;
        }
        FacilityStatus Facility::step(){
            timeLeft=timeLeft-1;
            if (timeLeft==0){
                setStatus(FacilityStatus::OPERATIONAL);
            }
            return status;
        }
        void Facility::setStatus(FacilityStatus status){
            Facility::status=status;
        }
        const FacilityStatus& Facility::getStatus() const{
            return status;
        }
        const string Facility::toString() const{
            
            string cat;
            string stat; 
            if (category==FacilityCategory::LIFE_QUALITY)
                cat="life quality";
            if (category==FacilityCategory::ECONOMY)
                cat="ecomony";
            if (category==FacilityCategory::ENVIRONMENT)
                cat="environment";
            if (status==FacilityStatus::UNDER_CONSTRUCTIONS)
                stat="under constractions";
            if (status==FacilityStatus::OPERATIONAL)
                stat="operational";

             return "facility name: "+  getName() + 
             " cagegory: " + cat + 
             " price: " +  std::to_string(price) + 
            " life quality score: " + std::to_string(lifeQuality_score) +
             " ecomony score: " + std::to_string(economy_score) +
            " environment score: "+ std::to_string(environment_score) + 
            " settlement name: " + getSettlementName() + 
            " status: " + stat + "time left: " + std::to_string(timeLeft);
            //ran
        }

    
        