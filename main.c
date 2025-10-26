#include <stdio.h>

char cities[30][50];
int cityCount = 0;
int distanceMatrix[30][30];


char vehicleNames[3][10] = {"Van", "Truck", "Lorry"};
int capacity[3] = {1000, 5000, 10000};
float rate[3] = {30, 40, 80};
float speed[3] = {60, 50, 45};
float efficiency[3] = {12, 6, 4};

void showCities()
{
    int i;
    printf("\n--- City List ---\n");
    if(cityCount == 0)
    {
        printf("No cities added yet.\n");
        return;
    }
    for(i = 0; i < cityCount; i++)
    {
        printf("%d. %s\n", i, cities[i]);
    }
}



void manageCities()
{
    int choice, i, index;
    char name[50];

    printf("\n1. Add City\n2. Rename City\n3. Remove City\nEnter choice: ");
    scanf("%d", &choice);

    if(choice == 1)
    {
        if(cityCount >= 30)
        {
            printf("City limit reached!\n");
            return;
        }
        printf("Enter city name: ");
        scanf("%s", cities[cityCount]);
        cityCount++;
        printf("City added successfully.\n");
    }
    else if(choice == 2)
    {
        showCities();
        printf("Enter city index to rename: ");
        scanf("%d", &index);
        if(index >= 0 && index < cityCount)
        {
            printf("Enter new name: ");
            scanf("%s", name);
            int j = 0;
            while(name[j] != '\0')
            {
                cities[index][j] = name[j];
                j++;
            }
            cities[index][j] = '\0';
            printf("City renamed.\n");
        }
        else
        {
            printf("Invalid index!\n");
        }
    }
    else if(choice == 3)
    {
        showCities();
        printf("Enter city index to remove: ");
        scanf("%d", &index);
        if(index >= 0 && index < cityCount)
        {
            for(i = index; i < cityCount - 1; i++)
            {
                int j = 0;
                while(cities[i+1][j] != '\0')
                {
                    cities[i][j] = cities[i+1][j];
                    j++;
                }
                cities[i][j] = '\0';
            }
            cityCount--;
            printf("City removed.\n");
        }
        else
        {
            printf("Invalid index!\n");
        }
    }
}
