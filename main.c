#include <stdio.h>
#include "product.h"
#include <stdlib.h>
#include <string.h>

int main(void)
{
    int count = 0;
    int choise;
    int id;
    int index;
   
    Product *products = NULL;
    loadProducts(&products, &count);
    
    
while (1)
{
    printf("1. Add Product\n");
    printf("2. Show Products\n");
    printf("3. Search Product\n");
    printf("4. Update Product.\n");
    printf("5. Delete product.\n");
    printf("6. Exit."); 

    scanf("%d", &choise);

    if (choise == 1)
    {
        addNewProduct(&products, &count); 
    }
    else if (choise == 2)
    {
        showProducts(products, count);
    }
    else if (choise == 3)
    {
        searchProduct(products, count);
    }
   else if (choise == 4)
{
    updateProduct(products, count);
}
    else if (choise == 5)
    {
        deleteProductByID(products, &count);

    }
    else if (choise == 6)
    {
        saveProducts(products, count);
        break;
    
    }


}
free(products);
return 0;
}