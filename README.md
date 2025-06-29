# 🛍️ **Online Store Application**

Welcome to the **Online Store Application**! This C++ program is designed to simulate an online store system, allowing you to manage customers, products, and their relationships dynamically. It combines practical programming with real-world data management to enhance your learning experience. 🚀

---

## 🌟 **Key Features**

### 💼 Customer Management
Add, update, or delete customer data using linked list operations.

### 🛒 Product Management
Manage product catalogs with seamless insertion, deletion, and search functionalities.

### 🔗 Relational Data Management
Create dynamic relationships between users and products to simulate purchases and interactions.

### 📊 Analytical Insights
Generate valuable insights such as:
  - Number of products purchased by a user.
  - Users associated with a specific product.

### ⚙️ Dynamic Data Structures
Utilizes **multi-linked lists** for effective data management:
  - **Single Linked List** for users.
  - **Double Linked List** for products.
  - **Relation List** for connections between users and products.

---

## 💻 **Technologies Used**

- **C++**: The primary language used for implementation.
- **Multi-Linked Lists**: For dynamic relationship and data management.
- **Text Files**: For persistent data storage.
- **Terminal-based Interface**: Simple yet functional for user interaction.

---

## 🚀 **Getting Started**

### 1️⃣ Clone the Repository
```bash
git clone https://github.com/Arfarzll/Online-Store-And-Customers.git
cd Online-Store-And-Customers
```

### 2️⃣ Compile the Program
Compile using a C++ compiler such as GCC:
```bash
g++ -o OnlineStore main.cpp SourceFile.cpp
./OnlineStore
```

### 3️⃣ Run the Application
Follow the interactive prompts to manage customers, products, and their relationships dynamically.

---

## 🗂️ **File Structure**

```plaintext
Online-Store-And-Customers/
├── .vscode/                           # VSCode configurations
├── .gitignore                         # Excluded files for version control
├── Header.h                           # Data structures and function prototypes
├── LICENSE                            # License for the repository
├── Online Store & Customers.cbp       # Code::Blocks project file
├── Online Store & Customers.depend    # Project dependencies
├── README.md                          # Project documentation
├── SourceFile.cpp                     # Implements core functionality
├── User & Barang.txt                  # Persistent user and product data
├── main.cpp                           # Program entry point and menu logic
```

---

## 📋 **Program Functionalities**

### Menu Options

The application offers the following features:

- Add User Data  
- Add Product Data  
- Display User List  
- Display Product List  
- Delete User Data  
- Delete Product Data  
- Add Product to User’s Purchases  
- Display Users and Their Purchases  
- Delete Connections Between Users and Products  
- Check User-Product Relationships  
- Display Users Who Have Purchased Items  
- Display Items Purchased by Users  
- Count Users for a Specific Product  
- Count Products Purchased by a User  
- List Products Not Purchased  
- List Users Who Have Not Made Purchases  
- Update Product for a User  
- Update User for a Product  
- Display Users Linked to a Product  
- Display Products Linked to a User  
- Exit

---

## 🛠️ **Example Usage**

### Adding a User
```cpp
infotypeUser newUser = {1, "Alice", "Jakarta"};
address_User user = createElmUser(newUser);
insertFirstUser(userList, user);
```

### Adding a Product
```cpp
infotypeBarang newProduct = {101, "Laptop", "Electronics"};
address_Barang product = createElmBarang(newProduct);
insertLastBarang(productList, product);
```

### Linking a User with a Product
```cpp
address_User user = findUser(userList, 1);
address_Barang product = findBarang(productList, 101);
address_Relasi relation = createElmRelasi();
connect(relationList, user, product, relation);
```

### Viewing Relationships
```cpp
showInfoRelation(userList, productList, relationList);
```

---

## 🖼️ **Program Interface**

Below is the initial menu displayed when the program starts:

```plaintext
+-------------------------------------------+
|                MENU UTAMA                 |
+-------------------------------------------+
| 1. Tambah Data User                       |
| 2. Tambah Data Barang                     |
| ...                                       |
| 20. Tampilkan Barang Tertentu             |
| 21. Exit                                  |
+-------------------------------------------+
>> Pilih Nomor Menu:
```

---

## 🔮 **Future Enhancements**

- **Database Integration**: Transition from text files to databases for scalability.
- **GUI Implementation**: Enhance user experience with a graphical interface.
- **Advanced Analytics**: Incorporate data visualization and deeper insights.

---


## 📝 **Acknowledgments**

Special thanks to my pathner who provided guidance throughout the development of this application. 🎉

---


> 🌟 **Feel Free to reach me!**
