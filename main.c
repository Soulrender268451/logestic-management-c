#include <stdio.h>

#define FUEL_PRICE 310.0

char cities[30][50];
int cityCount = 0;
int distanceMatrix[30][30];


char vehicleNames[3][10] = {"Van", "Truck", "Lorry"};
int capacity[3] = {1000, 5000, 10000};
float rate[3] = {30, 40, 80};
float speed[3] = {60, 50, 45};
float efficiency[3] = {12, 6, 4};


void manageCities();
void manageDistances();
void handleDelivery();
void showCities();

int main()
{
    int choice;

    do
    {
        printf("\n===== MANAGEMENT SYSTEM =====\n");
        printf("1. Manage Cities\n");
        printf("2. Manage Distances\n");
        printf("3. New Delivery Request\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
        case 1:
            manageCities();
            break;
        case 2:
            manageDistances();
            break;
        case 3:
            handleDelivery();
            break;
        case 4:
            printf("Exiting program...\n");
            break;
        default:
            printf("Invalid choice!\n");
        }
    }
    while(choice = 4);

    return 0;
}


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


void manageDistances()
{
    int a, b, d, i, j;

    if(cityCount < 2)
    {
        printf("Add at least 2 cities first!\n");
        return;
    }

    showCities();
    printf("Enter source city index: ");
    scanf("%d", &a);
    printf("Enter destination city index: ");
    scanf("%d", &b);

    if(a == b)
    {
        printf("Distance from a city to itself is 0.\n");
        distanceMatrix[a][b] = distanceMatrix[b][a] = 0;
        return;
    }

    printf("Enter distance between %s and %s (km): ", cities[a], cities[b]);
    scanf("%d", &d);
    distanceMatrix[a][b] = d;
    distanceMatrix[b][a] = d;

    printf("Distance added successfully.\n");


    printf("\n--- Distance Table ---\n   ");
    for(i = 0; i < cityCount; i++)
    {
        printf("%8s", cities[i]);
    }
    printf("\n");
    for(i = 0; i < cityCount; i++)
    {
        printf("%8s", cities[i]);
        for(j = 0; j < cityCount; j++)
        {
            printf("%8d", distanceMatrix[i][j]);
        }
        printf("\n");
    }
}

void handleDelivery()
{
    int s, d, v;
    float w;
    float dist, cost, fuelUsed, fuelCost, totalCost, profit, charge, time;

    if(cityCount < 2)
    {
        printf("Add at least 2 cities first!\n");
        return;
    }

    showCities();
    printf("Enter source city index: ");
    scanf("%d", &s);
    printf("Enter destination city index: ");
    scanf("%d", &d);
    printf("Enter weight (kg): ");
    scanf("%f", &w);

    printf("\nVehicle Types:\n1. Van\n2. Truck\n3. Lorry\nEnter choice: ");
    scanf("%d", &v);
    v = v - 1;

    if(s == d)
    {
        printf("Source and destination cannot be same!\n");
        return;
    }
    if(v < 0 || v > 2)
    {
        printf("Invalid vehicle type!\n");
        return;
    }
    if(w > capacity[v])
    {
        printf("Weight exceeds vehicle capacity!\n");
        return;
    }

    dist = distanceMatrix[s][d];
    if(dist <= 0)
    {
        printf("Distance not available!\n");
        return;
    }

    cost = dist * rate[v] * (1 + w / 10000);
    fuelUsed = dist / efficiency[v];
    fuelCost = fuelUsed * FUEL_PRICE;
    totalCost = cost + fuelCost;
    profit = cost * 0.25;
    charge = totalCost + profit;
    time = dist / speed[v];

    printf("\n==============================\n");
    printf("DELIVERY COST ESTIMATION\n");
    printf("------------------------------\n");
    printf("From: %s\nTo: %s\n", cities[s], cities[d]);
    printf("Vehicle: %s\nWeight: %.2f kg\n", vehicleNames[v], w);
    printf("Distance: %.2f km\n", dist);
    printf("------------------------------\n");
    printf("Base Cost: %.2f LKR\n", cost);
    printf("Fuel Cost: %.2f LKR\n", fuelCost);
    printf("Operational Cost: %.2f LKR\n", totalCost);
    printf("Profit: %.2f LKR\n", profit);
    printf("Customer Charge: %.2f LKR\n", charge);
    printf("Estimated Time: %.2f hours\n", time);
    printf("==============================\n");
}
