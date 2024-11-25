#include "Settlement.h"

        Settlement::Settlement(const string &name, SettlementType type): name(name), type(type){} 
        const string& Settlement::getName() const
        {
                return name;   
        }
        SettlementType Settlement::getType() const
        {
                return type;
        }
        const string Settlement::toString() const
        {
                if (type==SettlementType::VILLAGE)
                return "Settlement name is: " + name + " ,Settlement type is: Village";
                if (type==SettlementType::CITY)
                return "Settlement name is: " + name + " ,Settlement type is: City";
                if (type==SettlementType::METROPOLIS)
                return "Settlement name is: " + name + " ,Settlement type is: Metropolis";
        }
        
