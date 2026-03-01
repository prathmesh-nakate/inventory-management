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

void display_Products()
{
    if(products.empty())
    {
        cout<<"\n No Products in The System Yet !"<<endl;
        return;
    }
    cout<<"\n ====================================================================================="<<endl;
    cout<<"                             All products                                               "<<endl;
    cout<<"\n ====================================================================================="<<endl;

    cout<< left << setw(6) << "ID"
                << setw(29) << "Name"
                << setw(15) << "Category"
                << setw(10) << "Quantity"
                << setw(10) << "Price" <<endl;


    cout<<"======================================================================================"<<endl;

    for(const auto& p : products)
    {
        cout<< left << setw(6) << p.id
                << setw(29) << p.name
                << setw(15) << p.category
                << setw(10) << p.quantity
                << "$" << fixed << setprecision(2) << p.price <<endl;
    }

    cout<<"======================================================================================"<<endl;
    cout<<"Total Products : "<<products.size() <<endl;
} 

void search_Products()
{
    if(products.empty())
    {
        cout<<"\n No Products To Search !"<<endl;
        return;
    }

    int id;
    cout<<"Enter Product ID To Search : ";
    cin>>id;

    bool found = false;
    for(const auto& p : products)
    {
        if(p.id == id)
        {
            cout<<"\n =========== Product Found =========== "<<endl;
            cout<<"ID : "<< p.id << endl;
            cout<<"Name : "<< p.name << endl;
            cout<<"Category : "<<p.category << endl;
            cout<<"Quantity : "<<p.quantity << endl;
            cout<<"Price : $"<< fixed << setprecision(2) << p.price << endl;
            found = true;
            break;
        }
    }
    if(!found)
    {
        cout<<"\n Product With ID "<<id<<" Not Found !"<<endl;
    }
}

void update_Products()
{
    if(products.empty())
    {
        cout<<"\n No Product To Update !"<<endl;
        return;
    }

    int id;
    cout<<"Enter product ID To Update : ";
    cin>>id;

    bool found = false;
    for(auto& p : products)
    {
        if(p.id == id)
        {
            cout<<"\n Current Details : "<<endl;
            cout<<"Name : "<<p.name<<endl;
            cout<<"Category : "<<p.category<<endl;
            cout<<"Quantity : "<<p.quantity<<endl;
            cout<<"Price : $"<<fixed<<setprecision(2)<<p.price<<endl;

            cout<<"\n Enter New Details : "<<endl;

            cout<<"Enter Name : ";
            cin.ignore();
            getline(cin, p.name);

            cout<<"Enter Category : ";
            getline(cin, p.category);

            cout<<"Enter Quantiity : ";
            cin>>p.quantity;

            cout<<"Enter Price : ";
            cin>>p.price;

            save_Products();
            {
                cout<<"\n Product Updated Succesfully !"<<endl;
                found = true;
                break;
            }
        }

        if(!found)
        {
            cout<<"\nProduct With ID "<<id<<" Not Found !"<<endl;
        }
    }
}

int main()
{
    cout<<"Inventory management System"<<endl;
    return 0;
}
