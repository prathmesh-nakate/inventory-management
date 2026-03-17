# Inventory Management System
A simple C++ project to manage products and stock.

# Overview
A simple console-based Inventory Management System built in **C++**.
This project helps you manage products, track stock levels and generate reports.

## 🛠️ Built With

- **Language:** C++
- **Concepts:** OOP, File Handling, Structs, Vectors, Functions

## Status
Day 1: Initial setup

## ✨ Features

- 💾 Data saved to file (data persists after closing)
- ➕ Add new products
- 📋 Display all products in a table
- 🔍 Search product by ID
- ✏️ Update product details
- 🗑️ Delete a product
- 📦 Restock product (add quantity)
- 💰 Sell product (deduct quantity + show total)
- ⚠️ Low stock alert (quantity ≤ 5)
- 📊 Generate full inventory report

## 📁 Project Structure

```
inventory-management/
│
├── main.cpp          # Main source code
├── inventory.txt     # Auto-generated data file
└── README.md         # Project documentation
```

## 🚀 How to Run

### Step 1: Clone the Repository
```bash
git clone https://github.com/prathmesh-nakate/inventory-management/tree/main
cd inventory-management
```

### Step 2: Compile
```bash
g++ -o inventory main.cpp
```

### Step 3: Run
```bash
./inventory        # Linux / macOS
inventory.exe      # Windows
```

---

## 📷 Menu Preview

```
============================================================
            Inventory Management System
============================================================

------ Menu ------
1. Add Product
2. Display All Products
3. Search Product
4. Update Product
5. Delete Product
6. Restock Product
7. Sell Product
8. Low Stock Alert
9. Generate Report
0. Exit

Enter Your Choice :
```

---

## 📊 Sample Output

```
=================================================================
                       All Products
=================================================================
ID    Name                Category       Quantity  Price
=================================================================
1     Apple iPhone 15     Electronics    50        $999.99
2     Samsung TV 55"      Electronics    20        $749.99
3     Office Chair        Furniture      3         $199.99
=================================================================
Total Products : 3
```

---

## 💡 Concepts Used

| Concept        | Usage                              |
|----------------|------------------------------------|
| Struct         | Product blueprint                  |
| Vector         | Store list of products             |
| File Handling  | Save and load data from .txt file  |
| Functions      | Each feature in a separate function|
| Loops          | Menu loop and search loop          |
| iomanip        | Table formatting with setw()       |

---

## 📅 Development Log

| Day | What Was Added                        |
|-----|---------------------------------------|
| 1   | Initial setup and basic structure     |
| 2   | Added Product struct and vector       |
| 3   | Added menu system                     |
| 4   | Added display all products            |
| 5   | Added add product function            |
| 6   | Added search and update functions     |
| 7   | Added delete product function         |
| 8   | Added restock and sell functions      |
| 9   | Added file save and load              |
| 10  | Added low stock alert and report      |

---

## 👨‍💻 Author

- **Name:** Prathmesh Umesh Nakate
- **GitHub:** https://github.com/prathmesh-nakate

---

## 📜 License

This project is open source and available for learning purposes.

---

⭐ Star this repo if you found it helpful!