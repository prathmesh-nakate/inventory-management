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

void load_Products()
{
    ifstream file("inventory.txt");
    if(!file.is_open())
        return;

    Product p;
    while(file >> p.id)
    {
        file.ignore();
        getline(file, p.name);
        getline(file, p.category);
        file >> p.quantity >> p.price;
        file.ignore();
        products.push_back(p);
    }
    file.close();
}

void save_Products()
{
    ofstream file("inventory.txt");
    for(const auto& p : products)
    {
        file << p.id <<endl;
        file << p.name <<endl;
        file << p.category <<endl;
        file << p.quantity << " " << p.price <<endl;
    }
    file.close();
}

int main()
{
    cout<<"Inventory management System"<<endl;
    return 0;
}
