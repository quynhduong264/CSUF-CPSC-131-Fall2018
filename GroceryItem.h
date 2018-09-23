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
    GroceryItem() //default constructor
    {
      _name = " ";
      _quantity = 0;
      _unitPrice = 0;
      _taxable = 0;
    } 
    
    GroceryItem(const string& n, const int& q, const float& u, const bool& t) //overloaded construtor
    {
      _name = n;
      _quantity = q;
      _unitPrice = u;
      _taxable = t;
    }
    
    //accessor functions
    void setName(const string& n)
    {
      _name = n;
    }
    string getName() const
    {
      return _name;
    }
    void setQuantity(const int& q)
    {
      _quantity = q;
    }
    int getQuantity() const
    {
      return _quantity;
    }
    void setUnitPrice(const float& u)
    {
      _unitPrice = u;
    }
    float getUnitPrice() const
    {
      return _unitPrice;
    }
    void setTaxable(const bool& t)
    {
      _taxable = t;
    }
    bool isTaxable() const
    {
      return _taxable;
    }
};
