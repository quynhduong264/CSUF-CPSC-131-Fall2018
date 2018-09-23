#pragma once

#include <vector>
#include <iostream>
#include <fstream>
#include <stdexcept>
#include "GroceryItem.h"
using namespace std;

class GroceryInventory {
private:
    vector<GroceryItem> _inventory;
    float _taxRate;

public:
    GroceryInventory()
    {
      _taxRate = 0;
    }

    GroceryItem& getEntry(const string& n)
    {
      for (int i = 0; i < _inventory.size(); i++)
      {
        if (_inventory[i].getName() == n)
        {
          return _inventory[i];
        }
      }
      throw invalid_argument("Invalid Name");
    }
    void addEntry(const string& n, const int& q, const float& u, const bool& t)
    {
      GroceryItem g(n, q, u, t);
      _inventory.push_back(g);
    }
    void setTaxRate(const float& r)
    {
      _taxRate = r;
    }
    float getTaxRate() const
    {
      return _taxRate;
    }
    void createListFromFile(const string&);
    float calculateUnitRevenue() const;//unit price x quantity price
    float calculateTaxRevenue() const;//unit price x tax
    float calculateTotalRevenue() const;//tax + unit revenue

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

float GroceryInventory::calculateUnitRevenue() const
{
  float revenue;
  float temp;
  for (int i = 0; i < _inventory.size(); i++)
  {
    temp = _inventory[i].getUnitPrice() * _inventory[i].getQuantity();
    revenue += temp;
  }
  return revenue; 
}

float GroceryInventory::calculateTaxRevenue() const
{
  float taxRevenue = 0;
  float temp = 0;
  for (int i = 0; i < _inventory.size(); i++)
  {
    if (_inventory[i].isTaxable() == true)
    {
      temp = (_taxRate / 100) * _inventory[i].getUnitPrice() * _inventory[i].getQuantity();
      taxRevenue += temp;
    }
  }
  return taxRevenue;
}

float GroceryInventory::calculateTotalRevenue() const
{
  float total = 0;
  total = calculateUnitRevenue() + calculateTaxRevenue();
  return total;
}

