#include <stdio.h>
#include <string.h>
#include "introprog_countsort.h"
#include "arrayio.h"

/*
    Funktion liest einen String ein und wandelt diesen in den Datentypen
    SortDirection um

    return SortDirection
*/
SortDirection extract_order_direction(char *order)
{

    // return SortDirection;
}
/*
    Funktion erstellt auf Basis der Statistik die Ausgabe
    output_array: ist das Array in dem die sortierte Liste gespeichert wird
    count_array: Statistikarray
    order: Sortierrichtung
*/
void count_sort_write_output_array(int output_array[], int count_array[], SortDirection order)
{
    int len = MAX_VALUE;
    if (order == ASCENDING)
    {
        int k = 0;
        for (int j = 0; j < len; j++)
        {
            int currentCount = count_array[j];
            for (int i = 0; i < count_array[j]; i++)
            {
                output_array[k] = j;
                k = k + 1;
            }
        }
    }
    else if (order == DESCENDING)
    {
        int k = 1;
        // len - 1 because count_array[j]
        for (int j = len - 1; j >= 0; j--)
        {
            for (int i = 0; i < count_array[j]; i++)
            {
                output_array[k] = j;
                k = k + 1;
            }
        }
    }
}
// output array
/*
    Funktion errechnet die Statistik
    input_array: unsortierte Liste
    len: Länge der eingelesenen Liste
*/
void count_sort_calculate_counts(int input_array[], int len, int count_array[])
{
    for (int j = 0; j < len; j++)
    {
        count_array[input_array[j]] = count_array[input_array[j]] + 1;
    }
}
// c array consruction
/*
    Funktion führt bereitet Hilfstrukuren vor
    input_array: unsortierte Liste
    len: Länge der eingelesenen Liste
    output_array: sortierte Liste
*/
void count_sort(int input_array[], int len, int output_array[], SortDirection order)
{
    // int c[len];
    // int c[INT_MAX];
    int c[MAX_VALUE];

    for (int i = 0; i < MAX_VALUE; i++)
    {
        c[i] = 0;
    }
    printf("Count Array:");
    print_array(c, MAX_VALUE);
    // for (int j = 0; j < len; j++)
    // {
    //     c[input_array[j]] = c[input_array[j]] + 1;
    // }
    count_sort_calculate_counts(input_array, len, c);
    printf("Count Array:");
    print_array(c, MAX_VALUE);
    // int k = 1;
    // for (int j = 0; j < len; j++)
    // {
    //     output_array[k] = j;
    //     k = k + 1;
    // }
    count_sort_write_output_array(output_array, c, order);
}

/*
    Funktion liest einen String ein und wandelt diesen in den Datentypen
    SortDirection um

    return SortDirection
*/
SortDirection extract_order_direction(char *order);

int main(int argc, char *argv[])
{
    if (argc < 3)
    {
        printf("Aufruf: %s <Dateiname> asc|desc\n", argv[0]);
        printf("Beispiel: %s zahlen.txt asc\n", argv[0]);
        return 1;
    }

    char *filename = argv[1];

    /*
     * Hier die Sortierrichtung einlesen und einer Variablen
     * des Datentypes SortDirection (siehe h-Datei) verwenden.
     *
     * Beenden des Programmes mit derselben Ausgabe der Hilfe
     * (siehe Anfang main-Funktion)
     *
     * Implementieren Sie zur Umwandlung die Funktion
     * extract_order_direction und verwenden Sie, wenn kein
     * gültiger Parameter gefunden wurde, NOTDEFINED.
     *
     * Hinweis: Die extract_order_direction soll auch mit dieser
     * SortDirection auch ein Standardverhalten implementieren,
     * die nicht mit einem Fehler terminiert.
     *
     * Das Hauptprogramm main hingegen, darf auf unkorrekte Eingaben
     * reagieren und auch entsprechend Ausgaben erzeugen oder mit Fehler
     * beenden.
     */

    int input_array[MAX_LAENGE];
    int len = read_array_from_file(input_array, MAX_LAENGE, filename);

    printf("Unsortiertes Array:");
    print_array(input_array, len);

    /*
     * Hier count_sort aufrufen und alle nötigen Deklarationen einfügen!
     */
    int output_array[len];
    printf("Sortiertes Array; after initialization:");
    print_array(output_array, len);
    count_sort(input_array, len, output_array, ASCENDING);

    printf("Sortiertes Array:");

    /* Folgende Zeile einkommentieren, um das Array auszugeben! */
    print_array(output_array, len);

    return 0;
}
