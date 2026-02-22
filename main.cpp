#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>
#include<vector>

using namespace std;

struct Product
{
    int id;
    string name;
    string category;
    int quantity;
    double price;
};

vector<Product> products;

int main()
{
    cout<<"Inventory management System"<<endl;
    return 0;
}
