#pragma once
#include "SelectionPolicy.h"

//NaiveSelection::NaiveSelection(): lastSelectedIndex(0) {}
NaiveSelection::NaiveSelection(int i): lastSelectedIndex(i) {}
const FacilityType& NaiveSelection::selectFacility(const vector<FacilityType>& facilitiesOptions) {

}
const string NaiveSelection::toString() const {
    return "Last Selected Index: " + std::to_string(lastSelectedIndex);
}

// Need to be change or not ???????? 
//NaiveSelection::~NaiveSelection() override = default