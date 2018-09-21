#pragma once

#include <string>
using namespace std;

class GroceryItem 
{
  private:
    string _name;
    int _quantity;
    float _unitPrice;
    bool _taxable;

  public:
    GroceryItem(); //default constructor
    GroceryItem(const string&, const int&, const float&, const bool&); //overloaded construtor
    //accessor functions
    string getName() const;
    void setName(const string&);
    int getQuantity() const;
    void setQuantity(const int&);
    float getUnitPrice() const;
    void setUnitPrice(const float&);
    bool isTaxable() const;
    void setTaxable(const bool&);
};

GroceryItem::GroceryItem() //default constructor
{
  _name = " ";
  _quantity = 0;
  _unitPrice = 0;
  _taxable = 0;
}

GroceryItem::GroceryItem(const string& name, const int& quan, const float& unit, const bool& tax) //overloaded constructure
{
  _name = name;
  _quantity = quan;
  _unitPrice = unit;
  _taxable = tax;
}

//Accessor Functions
string GroceryItem::getName() const
{
  return _name;
}
int GroceryItem::getQuantity() const
{
  return _quantity;
}
float GroceryItem::getUnitPrice() const
{
  return _unitPrice;
}
bool GroceryItem::isTaxable() const
{
  return _taxable;
}
