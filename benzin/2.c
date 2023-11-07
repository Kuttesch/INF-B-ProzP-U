#include <stdio.h>

// Definition der Fahrzeugdatenstruktur
struct CarDetails {
    float km;     // gefahrene Kilometer (gesamt)
    float liter;  // verbrauchter Sprit (gesamt)
    float gewicht; // Gewicht des Fahrzeugs in Kilogramm
};

// Funktion, um den Benutzernamen einzugeben
void inputName(char name[]) {
    printf("Willkommen! Bitte gib deinen Namen ein: ");
    scanf("%s", name);
}

// Funktion, um die Fahrzeugdaten einzugeben
struct CarDetails inputCarDetails() {
    struct CarDetails carDetails;

    printf("Gib die gefahrenen Kilometer ein: ");
    scanf("%f", &carDetails.km);
    printf("Gib die Menge des verbrauchten Benzins in Litern ein: ");
    scanf("%f", &carDetails.liter);
    printf("Gib das Gewicht deines Fahrzeugs in Kilogramm ein: ");
    scanf("%f", &carDetails.gewicht);

    return carDetails;
}

// Funktion zur Berechnung des Benzinverbrauchs auf 100 km
float calculateLitersPer100Km(const struct CarDetails carDetails) {
    return (carDetails.liter / carDetails.km) * 100.0f;
}

// Funktion zur Ausgabe des Verbrauchs und Plausibilitätstests
void printResult(float consumption, const char name[], const struct CarDetails carDetails) {
    printf("Benzinverbrauch: %.2f Liter / 100 km\n", consumption);
    printf("Gewicht: %.2f Kilogramm\n", carDetails.gewicht);

    const float lowerLimit = 3.0f;
    const float upperLimit = 10.0f;

    if (consumption > upperLimit) {
        printf("%s, das ist ein hoher Verbrauch. Du könntest effizienter fahren!\n", name);
    } else if (consumption < lowerLimit) {
        printf("%s, das ist ein niedriger Verbrauch. Gut gemacht!\n", name);
    } else {
        printf("%s, dein Verbrauch liegt im normalen Bereich.\n", name);
    }
}

int main() {
    char name[50];
    struct CarDetails carDetails;
    float consumption;

    printf("BENZIN: Programm zum Kennenlernen\n");
    printf("---------------------------------\n");

    inputName(name);

    printf("Als Beispiel berechne ich den Benzinverbrauch deines Autos.\n");

    carDetails = inputCarDetails();

    consumption = calculateLitersPer100Km(carDetails);

    printResult(consumption, name, carDetails);

    return 0;
}
