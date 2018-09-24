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
    GroceryItem() //This is a default constructor
    {
      _name = " ";
      _quantity = 0;
      _unitPrice = 0;
      _taxable = 0;
    } 
    
    GroceryItem(const string& n, const int& q, const float& u, const bool& t) //This is an overloaded construtor
    {
      _name = n;
      _quantity = q;
      _unitPrice = u;
      _taxable = t;
    }
    
    //These are accessor functions
    void setName(const string& n) //set name
    {
      _name = n;
    }
    string getName() const //get name
    {
      return _name;
    }
    void setQuantity(const int& q) //set quantity
    {
      _quantity = q;
    }
    int getQuantity() const //get quantity
    {
      return _quantity;
    }
    void setUnitPrice(const float& u) //set unit price
    {
      _unitPrice = u;
    }
    float getUnitPrice() const //get unit price
    {
      return _unitPrice;
    }
    void setTaxable(const bool& t) //set tax
    {
      _taxable = t;
    }
    bool isTaxable() const //get tax
    {
      return _taxable;
    }
};
