#include <stdio.h>

// Function prototypes
double toCelsius(double temp, char scale);
double fromCelsius(double temp, char targetScale);
void categorizeTemperature(double tempInCelsius);

int main() {
    double temp;
    char currentScale, targetScale;

    // Input the temperature and its scale
    printf("Enter the temperature value: ");
    scanf("%lf", &temp);
    printf("Enter the current scale (F for Fahrenheit, C for Celsius, K for Kelvin): ");
    scanf(" %c", &currentScale);
    printf("Enter the target scale (F for Fahrenheit, C for Celsius, K for Kelvin): ");
    scanf(" %c", &targetScale);

    // Convert temperature to Celsius
    double tempInCelsius = toCelsius(temp, currentScale);

    // Convert from Celsius to target scale
    double convertedTemp = fromCelsius(tempInCelsius, targetScale);

    // Display the converted temperature
    printf("Converted temperature: %.2lf %c\n", convertedTemp, targetScale);

    // Categorize and provide a weather advisory
    categorizeTemperature(tempInCelsius);

    return 0;
}

// Function to convert the temperature to Celsius
double toCelsius(double temp, char scale) {
    switch (scale) {
        case 'F':
        case 'f':
            return (temp - 32) * 5.0 / 9.0;  // Fahrenheit to Celsius
        case 'K':
        case 'k':
            return temp - 273.15;  // Kelvin to Celsius
        case 'C':
        case 'c':
            return temp;  // Already in Celsius
        default:
            printf("Invalid scale entered!\n");
            return 0;
    }
}

// Function to convert the temperature from Celsius to the target scale
double fromCelsius(double temp, char targetScale) {
    switch (targetScale) {
        case 'F':
        case 'f':
            return temp * 9.0 / 5.0 + 32;  // Celsius to Fahrenheit
        case 'K':
        case 'k':
            return temp + 273.15;  // Celsius to Kelvin
        case 'C':
        case 'c':
            return temp;  // Already in Celsius
        default:
            printf("Invalid target scale entered!\n");
            return 0;
    }
}

// Function to categorize the temperature and provide a weather advisory
void categorizeTemperature(double tempInCelsius) {
    if (tempInCelsius < 0) {
        printf("Category: Freezing\n");
        printf("Advisory: Wear heavy winter clothing.\n");
    } else if (tempInCelsius >= 0 && tempInCelsius <= 10) {
        printf("Category: Cold\n");
        printf("Advisory: Wear a jacket.\n");
    } else if (tempInCelsius > 10 && tempInCelsius <= 25) {
        printf("Category: Comfortable\n");
        printf("Advisory: The weather is nice. Dress comfortably.\n");
    } else if (tempInCelsius > 25 && tempInCelsius <= 35) {
        printf("Category: Hot\n");
        printf("Advisory: Wear light clothing and stay hydrated.\n");
    } else {
        printf("Category: Extreme Heat\n");
        printf("Advisory: Stay indoors if possible and drink plenty of water.\n");
    }
}