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

    cout<<"\n====== Add New Product ======"<<endl;
    cout<<"\nEnter Product ID : ";
    cin>>p.id;

    for(const auto& product : products)
{
    if(product.id == p.id)   
    {
        cout<<"Error ! Product ID Already Exists."<<endl;
        return;
    }
}

    cout<<"Enter Name : ";
    cin.ignore();
    getline(cin, p.name);

    cout<<"Enter Category : ";
    getline(cin, p.category);
    
    cout<<"Enter Quantity : ";
    cin>>p.quantity;

    cout<<"Enter Price For 1 Piece : ";
    cin>>p.price;

    products.push_back(p);
    save_Products();

    cout<<endl<<"\nProduct Added Successfully !"<<endl;
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
                << " $" << fixed << setprecision(2) << p.price <<endl;
    }

    cout<<"======================================================================================"<<endl;
    cout<<"\nTotal Products : "<<products.size() <<endl;
} 

void search_Products()
{
    if(products.empty())
    {
        cout<<"\n No Products To Search !"<<endl;
        return;
    }

    int id;
    cout<<"\nEnter Product ID To Search : ";
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
            cout<<"Price :  $"<< fixed << setprecision(2) << p.price << endl;
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
    cout<<"\nEnter product ID To Update : ";
    cin>>id;

    bool found = false;
    for(auto& p : products)
    {
        if(p.id == id)
        {
            cout<<"\n Current Details : "<<endl;
            cout<<"\nName : "<<p.name<<endl;
            cout<<"Category : "<<p.category<<endl;
            cout<<"Quantity : "<<p.quantity<<endl;
            cout<<"Price : $"<<fixed<<setprecision(2)<<p.price<<endl;

            cout<<"\n Enter New Details : "<<endl;

            cout<<"\nEnter Name : ";
            cin.ignore();
            getline(cin, p.name);

            cout<<"Enter Category : ";
            getline(cin, p.category);

            cout<<"Enter Quantiity : ";
            cin>>p.quantity;

            cout<<"Enter Price For 1 Piece : ";
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

void delete_Products()
{
    if(products.empty())
    {
        cout<<"\n No Product To Delete !"<<endl;
        return;
    }

    int id;
    cout<<"\nEnter Product ID To Delete : ";
    cin>>id;

    bool found = false;
    for(size_t i = 0; i < products.size(); i++)
    {
        if(products[i].id == id)
        {
            cout<<"Delete Product : "<<products[i].name<<"? (y/n) : ";
            char confirm;

            if(confirm == 'y' || confirm == 'Y')
            {
                products.erase(products.begin() + i);
                save_Products();
                cout<<"\n Product Deleted Successfully !"<<endl;
            }
            else
            {
                cout<<"\n Product Deletion Cancelled !"<<endl;
            }
            found = true;
            break;
        }
    }
    if(!found)
    {
        cout<<"\n Product With ID"<<id<<" Not Found !"<<endl; 
    } 
}

void restock_Products()
{
    if(products.empty())
    {
        cout<<"\n No Product To Restock !"<<endl;
        return;
    }
    int id, qtr;
    cout<<"\nEnter Product ID To Restock : ";
    cin>>id;

    bool found = false;
    for(auto& p : products)
    {
        if(p.id == id)
        {
            cout<<"Current Stock : "<<p.quantity<<endl;

            cout<<"Add quantity : ";
            cin>>qtr;

            p.quantity += qtr;
            save_Products();

            cout<<"\n Restock Succesfully ! New Stock : "<<p.quantity<<endl;
            found = true;
            break;
        }
    }
    if(!found)
    {
        cout<<"\n Product With ID "<<id<<" Not Found !"<<endl;
    }
}

void sell_products()
{
    if(products.empty())
    {
        cout<<"\n No Product To Sell !"<<endl;
        return;
    }
    int id,qty;
    cout<<"\nEnter Product ID To Sell : ";
    cin>>id;

    bool found = false;
    for(auto& p : products)
    {
        if(p.id == id)
        {
            cout<<"\nProduct : "<<p.name<<endl;
            cout<<"Available Stock : "<<p.quantity<<endl;
            cout<<"Sell Quantity : ";
            cin>>qty;

            if(qty > p.quantity)
            {
                cout<<"\n Not Enough Stock Available !"<<endl;
                return;
            }

            p.quantity -= qty;
            double total = qty * p.price;
            save_Products();

            cout<<"\n============== Sale Receipt =============="<<endl;
            cout<<"\nUnits Sold : "<<qty<<endl;
            cout<<"Unit Price of one piece : $" << fixed << setprecision(2) << p.price << endl;
            cout<<"Total Price : $" << fixed << setprecision(2) << total << endl;
            found = true;
            break;
        }
    }
    if(!found)
    {
        cout<<"\nProduct With ID "<<id<<" Not Found !"<<endl;
    }
}

void lowstock_Alert()
{
    cout<<"\n =========== Low Stock Alert (Qty <= 10) ==========="<<endl;

    bool found = false;
    for(const auto& p : products)
    {
        if(p.quantity <= 10)
        {
            cout<<"\nId : "<<p.id<<endl;
            cout<<"Name : "<<p.name<<endl;
            cout<<"Stock : "<<p.quantity<<endl;

            found = true;
        }   
    }
    if(!found)
    {
        cout<<"\nAll Products Have Sufficient Stock !"<<endl;
    }
}

void generate_Report()
{
    if(products.empty())
    {
        cout<<"\n No Product in The System Yet !"<<endl;
        return;
    }

    double total_Value = 0;
    int    total_Items = 0;
    
    display_Products();

    for(const auto& p : products)
    {
        total_Value += p.quantity * p.price;
        total_Items += p.quantity;
    }

    cout<<"\n ============ Inventory Report ============"<<endl;
    cout<<"\nTotal Products : "<<products.size()<<endl;
    cout<<"Total Items    : "<<total_Items<<endl;
    cout<<"Total Value    : $"<<fixed<<setprecision(2)<<total_Value<<endl;

}

int main()
{
   
   load_Products();

    cout << "======================================================================" << endl;
    cout << "                     Inventory management System                      " << endl;
    cout << "======================================================================" << endl;

    while(true)
    {
        cout << "\n ------ Menu ------ "    << endl;
        cout << "\n1. Add Product"            << endl;
        cout << "2. Display All Products"   << endl;
        cout << "3. Search Product"         << endl;
        cout << "4. Update Product"         << endl;
        cout << "5. Delete Product"         << endl;
        cout << "6. Restock Product"        << endl;
        cout << "7. Sell Product"           << endl;
        cout << "8. Low Stock Alert"        << endl;
        cout << "9. Generate Report"        << endl;
        cout << "0. Exit"                   << endl;

        int choice;
        cout<<"\nEnter Your Choice : ";
        cin>>choice;

        switch(choice)
        {
            case 1 : add_Products();            break;
            case 2 : display_Products();        break;
            case 3 : search_Products();         break;
            case 4 : update_Products();         break;
            case 5 : delete_Products();         break;
            case 6 : restock_Products();        break;
            case 7 : sell_products();           break;
            case 8 : lowstock_Alert();          break;
            case 9 : generate_Report();         break;
            case 0 :
                cout<<"Thanks For Using Inventory Management System. Goodbye !"<<endl;
                return 0;

                default :
                    cout<<"\n Invalid Choice. Please Try Again."<<endl;
        }
    }

    return 0;
}
