# Mini Inventory Manager in C

This is my first C programming project.

The program is a simple inventory management system built using the C programming language.

## Features

- Add a new product
- Show all products
- Search for a product by ID
- Update product information
- Delete a product
- Prevent duplicate product IDs
- Validate price and quantity
- Prevent empty product names
- Save products to a file
- Load products automatically when the program starts

## Concepts Used

This project helped me practice:

- Structures (`struct`)
- Pointers
- Double pointers
- Dynamic memory allocation
- `malloc` / `realloc` / `free`
- File handling
- Functions
- Loops
- Conditions
- Arrays
- Strings
- Input validation

## Project Structure

```text
mini-inventory-manager-c/
│
├── main.c
├── product.c
├── product.h
└── README.md
```

The program also creates:

```text
inventory.txt
```

to save product data.

## Compile

Using GCC:

```bash
gcc main.c product.c -o inventory
```

On Windows:

```bash
gcc main.c product.c -o inventory.exe
```

## Run

Windows:

```bash
./inventory.exe
```

Linux / macOS:

```bash
./inventory
```

## Menu

```text
1. Add Product
2. Show Products
3. Search Product
4. Update Product
5. Delete Product
6. Exit
```

## Example Product

```text
ID: 101
Name: Keyboard
Price: 250.00
Quantity: 5
```

## Author

Mohamed Amin

## Note

This is my first programming project in C and represents the beginning of my programming journey.