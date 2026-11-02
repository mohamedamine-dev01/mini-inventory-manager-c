#ifndef PRODUCT_H
#define PRODUCT_H
typedef struct
{
    int ID;
    char name[51];
    float price;
    int Quantity;
}Product;
void addProduct(Product *p);
void printProduct(const Product *p);
int findProductByID(const Product *products, int count, int id);

void saveProducts(Product *products, int count);
void loadProducts(Product **products, int *count);

void deleteProduct(Product *products, int *count, int index);
void deleteProductByID(Product *products, int *count);

void updateProduct(Product *products, int count);
void searchProduct(Product *products, int count);
void showProducts(Product *products, int count);
void addNewProduct(Product **products, int *count);
#endif



