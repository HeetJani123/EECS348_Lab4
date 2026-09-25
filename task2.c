#include <stdio.h>
#include <ctype.h>

int main() {
    float temp, converted_temp, temp_c;
    char original, target;

    printf("Enter the temperature value: ");
    if (scanf("%f", &temp) != 1) {
        printf("Invalid input. Please enter a numerical temperature.\n");
        return 1;
    }

    printf("Enter the original scale (C, F, or K): ");
    scanf(" %c", &original);
    original = toupper(original);

    printf("Enter the scale to convert to (C, F, or K): ");
    scanf(" %c", &target);
    target = toupper(target);

    // Validate scales
    if ((original != 'C' && original != 'F' && original != 'K') ||
        (target != 'C' && target != 'F' && target != 'K')) {
        printf("Error: Invalid scale entered. Please use C, F, or K.\n");
        return 1;
    }

    //absolute zero
    if ((original == 'C' && temp < -273.15) ||
        (original == 'F' && temp < -459.67) ||
        (original == 'K' && temp < 0)) {
        printf("Error: Temperature cannot be below absolute zero.");
        return 1;
    }

    // Conversion
    if (original == target) {
        converted_temp = temp;
        temp_c = (original == 'C') ? temp : ((original == 'F') ? (temp - 32) * 5.0 / 9.0 : temp - 273.15);
    } else if (original == 'C' && target == 'F') { 
        converted_temp = (temp * 9.0 / 5.0) + 32; temp_c = temp; 
    } else if (original == 'C' && target == 'K') { 
        converted_temp = temp + 273.15; temp_c = temp; 
    } else if (original == 'F' && target == 'C') { 
        converted_temp = (temp - 32) * 5.0 / 9.0; temp_c = converted_temp; 
    } else if (original == 'F' && target == 'K') { 
        converted_temp = ((temp - 32) * 5.0 / 9.0) + 273.15; temp_c = (temp - 32) * 5.0 / 9.0; 
    } else if (original == 'K' && target == 'C') { 
        converted_temp = temp - 273.15; temp_c = converted_temp; 
    } else if (original == 'K' && target == 'F') { 
        converted_temp = ((temp - 273.15) * 9.0 / 5.0) + 32; temp_c = temp - 273.15; 
    }

    printf("\nConverted temperature: %.2f %c\n", converted_temp, target);

    // Convert to Celsius for easier categorization
    if (temp_c < 0) {
        printf("Temperature category: Freezing, wear warm clothing.\n");
    } else if (temp_c < 10) {
        printf("Temperature category: Cold, wear a jacket.\n");
    } else if (temp_c < 25) {
        printf("Temperature category: Comfortable, perfect weather, enjoy the day.\n");
    } else if (temp_c < 35) {
        printf("Temperature category: Hot, drink lots of water!\n");
    } else {                
        printf("Temperature category: Extreme Heat, stay indoors and keep cool.\n");
    }

    return 0;
}