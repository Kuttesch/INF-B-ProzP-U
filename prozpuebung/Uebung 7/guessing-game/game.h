#ifndef _ZR_H_
#define _ZR_H_

#define ORACLE_VALUE_MIN 1
#define ORACLE_VALUE_MAX 100

#define N_GUESSES 5


/* Prototypen der benötigten Funktionen */

/**
 * Gibt n mal das Zeichen c aus
 */
void line(int n, char c);

/**
 * Startet das Ratespiel. 
 * Wählt zufällig einen Wert im Intervall [ORACLE_VALUE_MIN, ORACLE_VALUE_MAX].
 * Nimmt wiederholt Benutzereingaben entgegen und prüft diese auf Übereinstimmung mit dem gewählten Wert. (siehe 'void guess(int guessedValue)')
 * Beendet das Ratespiel, wenn der Benutzer die Zahl erraten konnte oder wenn die Rateversuche des Benutzers N_GUESSES übersteigen. 
 * Nach Beendigung des Ratespiels wird der Benutzer gefragt ob er erneut spielen möchte. Durch Eingabe von 'j' oder 'J' wird das Ratespiel mit einer neuen Zufallszahl erneut gestartet. Jede andere Eingabe beendet das Spiel.
 */
void guessingGame(int oracleValueMin, int oracleValueMax);

/**
 * Nimmt wiederholt Benutzereingaben entgegen und prüft diese auf Übereinstimmung mit dem gewählten Wert 'oracleValue'.
 */
void guess(int oracleValue, char * display, int oracleValueMin, int oracleValueMax);

/**
 * Setzt alle Pixel des Displays auf state DISP_UNKNOWN
 */
void initializeDisplay(char * display, int sizeOfDisplay);

/**
 * Aktualisiert die Zustände der Pixel so, dass der aktuelle Spielstand wiedergegeben wird.
 */
void updateDisplay(char * display, int guess, int oracle, int remainingGuesses, int oracleValueMin, int oracleValueMax);

/**
 * Zeigt die Pixel des Displays auf der Konsole an.
 */
void showDisplay(char * display);

#endif
