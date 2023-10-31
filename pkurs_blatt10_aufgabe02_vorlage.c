// Bibiotheken I/O, string und stdlib
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* prepare_repeated_message(char* message, int repeat){

    return NULL;
}

// Einsprungspunkt 'main' in das Programm definieren
int main() {
    // Text hier ohne Umbruch ausgeben, 
    // da die Umbrüche in der Funktion generiert werden sollen
    char* o = prepare_repeated_message("Hallo Osiris!", 3);
    printf("%s", o);
    free(o);
    // Rückgabe von 0 zur Signalisierung, dass kein Fehler aufgetreten ist
    return 0;
}