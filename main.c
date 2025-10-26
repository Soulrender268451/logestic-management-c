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
