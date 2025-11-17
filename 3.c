#include <math.h>
#include <stdio.h>
#include <string.h>

#define MAX 5

struct product
{
    int id;
    char name[50];
    int quantity;
    float price;
} typedef product;

void addProduct(struct product products[], int *count)
{
    struct product p;
    printf("ID: ");
    scanf("%d", &p.id);
    getchar();

    printf("name: ");
    fgets(p.name, sizeof(p.name), stdin);
    p.name[strcspn(p.name, "\n")] = '\0';

    if (strlen(p.name) == 0)
    {
        printf("error\n");
        printf("name: ");
        fgets(p.name, sizeof(p.name), stdin);
        p.name[strcspn(p.name, "\n")] = '\0';
    }

    printf("quantity: ");
    scanf("%d", &p.quantity);

    if (p.quantity <= 0)
    {
        printf("error");
        printf("quantity: ");
        scanf("%d", &p.quantity);
    }

    printf("price: ");
    scanf("%f", &p.price);

    if (p.price <= 0)
    {
        printf("error");
        printf("price: ");
        scanf("%f", &p.price);
    }

    products[*count] = p;
    (*count)++;
    printf("added");
}

void viewProducts(struct product products[], int count)
{
    if (count == 0)
    {
        printf("none product\n");
    }

    for (int i = 0; i < count; i++)
    {
        printf("ID: %d, Name: %s, Quantity: %d, Price: %.2f\n", products[i].id, products[i].name, products[i].quantity, products[i].price);
    }
}

void deleteProducts(struct product products[], int *count)
{
    if (*count == 0)
    {
        printf("none product");
    }

    int id;
    printf("enter ID of product to delete: ");
    scanf("%d", &id);

    int index = -1;
    for (int i = 0; i < *count; i++)
    {
        if (products[i].id == id)
        {
            index = i;
            break;
        }
    }

    if (index == -1)
    {
        printf("none products");
    }

    for (int i = index; i < *count - 1; i++)
    {
        products[i] = products[i + 1];
    }

    (*count)--;

    printf("deleted\n");
}

int main()
{
    struct product products[MAX];
    int count = 0;
    int choice;
    do
    {
        printf("1. Add product\n");
        printf("2. View product\n");
        printf("3. Delete product\n");
        printf("4. Exit\n");

        printf("enter choice: ");
        scanf("%d", &choice);
        getchar();

        switch (choice)
        {
        case 1:
            addProduct(products, &count);
            break;

        case 2:
            viewProducts(products, count);
            break;

        case 3:
            deleteProducts(products, &count);
            break;

        default:
            printf("error");
        }
    } while (choice != 4);
}