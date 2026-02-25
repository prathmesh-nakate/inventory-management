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

void add_Products()
{
    Product p;

    cout<<"====== Add New Product ======"<<endl;
    cout<<"Enter Product ID : ";
    cin>>p.id;

    for(const auto& product : products)
    {
        cout<<"Error ! Product ID Already Exists."<<endl;
        return;
    }

    cout<<"Enter Name : ";
    cin.ignore();
    getline(cin, p.name);

    cout<<"Enter Category : ";
    getline(cin, p.category);
    
    cout<<"Enter Quantity : ";
    cin>>p.quantity;

    cout<<"Enter Price : ";
    cin>>p.price;

    products.push_back(p);
    save_Products();

    cout<<endl<<"Product Added Successfully !"<<endl;
}

int main()
{
    cout<<"Inventory management System"<<endl;
    return 0;
}
