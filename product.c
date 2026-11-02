#include <stdio.h>
#include "product.h"
#include <string.h>
#include <stdlib.h>

void addProduct(Product *p)
{
    
    do
    {
        printf("Enter price: ");
        scanf("%f", &p->price);
        if (p->price < 0)
        {
            printf("Price cannot be negative.\n");
        }
        
    } while (p->price < 0);
    
    do
    {
        printf("Enter Quantuty: ");
        scanf("%d", &p->Quantity);
        if (p->Quantity < 0)
        {
            printf("Quantity cannot be negative.\n");
        }
        
    } while (p->Quantity < 0);
    
    getchar();
    do
    {
        printf("ENter Name: ");
        fgets(p->name, sizeof(p->name), stdin);
        p->name[strcspn(p->name, "\n")] = '\0';

        if (strlen(p->name) == 0)
        {
            printf("Name cannot be empy.\n");
        }
        
    } while (strlen(p->name) == 0);
    


}

void saveProducts(Product *products, int count)
{
    FILE *file;
    file = fopen("inventory.txt", "w");
    if (file == NULL)
    {
        printf("Error opening file. \n");
        return;
    }
    for (int i = 0; i < count; i++)
    {
        fprintf(file, "%d|%s|%.2f|%d\n", products[i].ID,products[i].name, products[i].price, products[i].Quantity);
    }
    fclose(file);
    printf("Products saved successfully.\n");
    
}

void loadProducts(Product **products, int *count)
{
    FILE *file = fopen("inventory.txt", "r");
    if (file == NULL)
    {
        return;
    }
    while (1)
    {
        Product *temp = realloc(*products, (*count + 1) * sizeof(Product));
        if (temp == NULL)
        {
            printf("Memory allocation failed. \n");
            fclose(file);
            return;
        }
        *products = temp;
        int result = fscanf(
            file,
            "%d|%[^|]|%f|%d",
            &(*products)[*count].ID,
            (*products)[*count].name,
            &(*products)[*count].price,
            &(*products)[*count].Quantity
        );
        if (result != 4)
        {
            break;
        }
        (*count)++;
    }
    fclose(file);
    
}

int findProductByID(const Product *products, int count, int id)
{
    for (int i = 0; i < count; i++)
    {
        if (products[i].ID == id)
        {
            return i;
        }
       
    }
    return -1;
}

void deleteProduct(Product *products, int *count, int index)
{
    for (int i = index; i < *count - 1; i++)
    {
        products[i] = products[i + 1];
    }
    (*count)--;
    printf("Product delet successfuly!\n");
}

void updateProduct(Product *products, int count)
{
    int id;
    int index;
    printf("Enter product ID to update: ");
    scanf("%d", &id);
    index = findProductByID(products, count, id);
    if (index == -1)
    {
        printf("Product nit found.\n");
        return;
    }
    getchar();
    do
    {
        printf("Enter Name: ");
        fgets(products[index].name, sizeof(products[index].name), stdin);
        products[index].name[strcspn(products[index].name, "\n")] = '\0';
        if (strlen(products[index].name) == 0)
        {
            printf("Name cannot be empty.\n");
        }
        
    } while (strlen(products[index].name) == 0);
    do
    {
        printf("New price: ");
        scanf("%f", &products[index].price);
        if (products[index].price < 0)
        {
            printf("Price cznnot be negative. \n");

        }
    } while (products[index].price < 0);
    
    do
{
    printf("New quantity: ");
    scanf("%d", &products[index].Quantity);

    if (products[index].Quantity < 0)
    {
        printf("Quantity cannot be negative.\n");
    }

} while (products[index].Quantity < 0);

printf("Product updated successfully!\n");
    
}

void searchProduct(Product *products, int count)
{
    int id;
    int index;

    printf("ID: ");
    scanf("%d", &id);
    index = findProductByID(products, count, id);
    if (index == -1)
    {
        printf("Product not found.\n");
    }
    else
    {
        printProduct(&products[index]);
    }
}

void showProducts(Product *products, int count)
{
if (count == 0)
{
    printf("NO PRODUCTS FOUND.\n");
    return;
}
for (int i = 0; i < count; i++)
{
    printProduct(&products[i]);
}

}

void addNewProduct(Product **products, int *count)
{
    Product *temp = realloc(
        *products, 
        (*count + 1) * sizeof(Product)
    );
    if (temp == NULL)
    {
        printf("Memory allocation faild.\n");
        return;
    }
    *products = temp;
    printf("ID product:  ");
    scanf("%d", &(*products)[*count].ID);
    int existingIndex = findProductByID(*products, *count, (*products)[*count].ID);
    if (existingIndex != -1)
    {
        printf("This ID already exists.\n");
        return;
    }
    addProduct(&(*products)[*count]);
    (*count)++;
    
}

void deleteProductByID(Product *products, int *count)
{
    int id;
    int index;
    printf("what ID delet: ");
    scanf("%d", &id);
    index = findProductByID(products, *count, id);
    if (index == -1)
    {
        printf("Product not found.\n");
        return;
    }
    deleteProduct(products, count, index);

}

void printProduct(const Product *p)
{
    printf("ID: %d\n", p->ID);
    printf("Names: %s\n", p->name);
    printf("Price: %.2f\n", p->price);
    printf("Quantity: %d\n",p->Quantity);
}