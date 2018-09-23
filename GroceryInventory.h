#pragma once

#include <vector>
#include <iostream>
#include <fstream>
#include <stdexcept>
#include "GroceryItem.h"
using namespace std;

class GroceryInventory {
private:
    vector<GroceryItem> _inventory; //vector called _inventory
    float _taxRate; 

public:
    GroceryInventory() //default constructor
    {
      _taxRate = 0;
    }

    GroceryItem& getEntry(const string& n) //This function get the item name from GroceryItem
    {
      for (int i = 0; i < _inventory.size(); i++)
      {
        if (_inventory[i].getName() == n) //If name is valid, return name
        {
          return _inventory[i];
        }
      }
      throw invalid_argument("Invalid Name"); //If the name is invalid, print Invalid Name
    }
    void addEntry(const string& n, const int& q, const float& u, const bool& t) //This function adding products into vector
    {
      GroceryItem g(n, q, u, t);
      _inventory.push_back(g);
    }
    void setTaxRate(const float& r) // set the Tax Rate
    {
      _taxRate = r;
    }
    float getTaxRate() const //get Tax Rate
    {
      return _taxRate;
    }
    void createListFromFile(const string&); 
    float calculateUnitRevenue() const; //This function calculate unit price x quantity price
    float calculateTaxRevenue() const; //This function calculate tax(7.75) x unit price x quantity price
    float calculateTotalRevenue() const; //This function calculate tax revenue + unit revenue

    GroceryItem& operator[](const int&);
};
  
void GroceryInventory::createListFromFile(const string& filename) {
    ifstream input_file(filename);

    if (input_file.is_open()) {
        cout << "Successfully opened file " << filename << endl;
        string name;
        int quantity;
        float unit_price;
        bool taxable;
        while (input_file >> name >> quantity >> unit_price >> taxable) {
            addEntry(name, quantity, unit_price, taxable);
        }
        input_file.close();
    } else {
        throw invalid_argument("Could not open file " + filename);
    }
}

float GroceryInventory::calculateUnitRevenue() const //This function calculate unit price x quantity price
{
  float revenue;
  float temp;
  for (int i = 0; i < _inventory.size(); i++) //loop through the _inventory vector
  {
    temp = _inventory[i].getUnitPrice() * _inventory[i].getQuantity(); //calcuate unit revenue
    revenue += temp;
  }
  return revenue; 
}

float GroceryInventory::calculateTaxRevenue() const //This function calculate tax(7.75) x unit price x quantity price
{
  float taxRevenue = 0;
  float temp = 0;
  for (int i = 0; i < _inventory.size(); i++) //loop through the +inventory vector
  {
    if (_inventory[i].isTaxable() == true) //If it is taxable = true (1) or else = false (0)
    {
      temp = (_taxRate / 100) * _inventory[i].getUnitPrice() * _inventory[i].getQuantity(); //calculate tax x unit x quantity
      taxRevenue += temp;
    }
  }
  return taxRevenue;
}

float GroceryInventory::calculateTotalRevenue() const //This function calculate tax revenue + unit revenue
{
  float total = 0;
  total = calculateUnitRevenue() + calculateTaxRevenue(); //calcuate total
  return total;
}

