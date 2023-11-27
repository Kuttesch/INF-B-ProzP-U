//*******************************************************************
// Programm    : BENZIN                                                            
// Verfasser   : Feindor/Schmidt
// Übungsbeispiel für:
//               Programmaufbau, Typen, Konstanten, Variablen,
//               Bildschirm-Ein-/Ausgabe, Wertzuweisung, if              
// Datum       : Urprogramm: 1.10.1996
// Eingabe     : Kilometerzahl, Benzinverbrauch in Liter               
// Verarbeitung: Berechnung des Durchschnittsverbrauchs          
// Ausgabe     : Verbrauch                                                         
// Änderungen  : 23.09.2012
//				 18.08.2022 (Jurgovsky)
//*******************************************************************


/*
 * Einbinden der nötigen Headerdateien
 */
#include <stdio.h>  // Standard Input/ Output  z.B. scanf, printf
#include <string.h>

/*
 * Symbolische Konstante definieren
 */
#define MAX_STRING_LENGTH 20
#define SECRET "dude"

/*
 * Definition der Fahrzeugdatenstruktur
 */
struct s_CarDetails
{
	float km;		// gefahrene km (gesamt)
	float liter;	// verbrauchter Sprit (gesamt)
};

char titles[][MAX_STRING_LENGTH] = {"Dich", "Sie"};
unsigned char mode = 0;

/*
 * Deklaration der nötigen Funktionen
 */
void inputName(char name[]);
struct s_CarDetails inputCarDetails(void);
float calculateLitersPer1Km(struct s_CarDetails carDetails);
void printResult(float consumption, const char name[]);


/*
 * Hauptprogramm
 */
int main()
{
	/*
	 * Variablendeklarationen (dt. "Vereinbarungsteil" | engl. "Declarations")
	 */
	struct s_CarDetails carDetails;
	float consumption;
	char  name[MAX_STRING_LENGTH];


	/*
	 * Anweisungsteil
	 */

	// Dialogeröffnung
	printf ("BENZIN: Programm zum Kennenlernen\n");
	printf ("---------------------------------\n");

	// Daten einlesen   
    inputName(name);

	printf ("Als Beispiel berechne ich Dir den\n"
            "Benzinverbrauch Deines Autos.\n");

    carDetails = inputCarDetails();
	
	// Verbrauch berechnen
	consumption = calculateLitersPer1Km(carDetails);

	// Ergebnis ausgeben
    printResult(consumption, name);

	return 0;
} //***************** Ende Hauptprogramm *****************************



/*
 * Definition der Funktionen
 */

// Einlesen des Benutzernamens
void inputName(char name[])
{
	printf ("Hallo, wir wollen etwas C lernen.\nWie heisst Du? ");
	scanf  ("%s", name);

    if(strcmp(name, SECRET) == 0) {
        mode = 1;
    } else {
        mode = 0;
    }

    printf ("Freut mich, %s, %s kennenzulernen!! \n\n", name, titles[mode]);
}

// Einlesen der Fahrzeugdaten
struct s_CarDetails inputCarDetails()
{
	struct s_CarDetails carDetails;

	printf ("Bitte gib ein: \nGefahrene Kilometer: ");
	scanf ("%f", &(carDetails.km));
	printf ("Benzinmenge in Liter: ");
	scanf ("%f", &(carDetails.liter));

	return carDetails;
}

// Berechne Benzinverbrauch auf 100 km
float calculateLitersPer1Km(const struct s_CarDetails carDetails)
{
	float consumption;

    consumption = (carDetails.liter / carDetails.km);

	return consumption;
}

// Ausgabe des Verbrauchs und Test auf Plausibilität
void printResult(const float consumption, const char name[])
{
	const float lowerLimit = 0.03, upperLimit = 0.10;

	printf ("Benzinverbrauch: %10.2f Liter / 1km\n", consumption);

	if (upperLimit < consumption) {
		printf ("%s, %s! Das ist Energieverschwendung!!!\n", name, name);
	}
		
	if (consumption < lowerLimit) {
		printf ("%s, %s! Ich glaube, du schwindelst!!!\n", name, name);
	}
}
