/*
 * MAX_VALUE darf zum Testen abgeändert werden
 */
int MAX_LAENGE = 1000;
int MAX_VALUE = 100;

typedef enum SortDirection_ {
    ASCENDING, DESCENDING, NOTDEFINED
} SortDirection; 

/*
    Funktion erstellt auf Basis der Statistik die Ausgabe
    output_array: ist das Array in dem die sortierte Liste gespeichert wird
    count_array: Statistikarray
    order: Sortierrichtung
*/
void count_sort_write_output_array(int output_array[], int count_array[], SortDirection order);

/*
    Funktion errechnet die Statistik 
    input_array: unsortierte Liste
    len: Länge der eingelesenen Liste
*/
void count_sort_calculate_counts(int input_array[], int len, int count_array[]);


/*
    Funktion führt bereitet Hilfstrukuren vor 
    input_array: unsortierte Liste
    len: Länge der eingelesenen Liste
    output_array: sortierte Liste
*/
void count_sort(int input_array[], int len, int output_array[], SortDirection order);

/*
    Funktion liest einen String ein und wandelt diesen in den Datentypen 
    SortDirection um

    return SortDirection
*/
SortDirection extract_order_direction(char *order);