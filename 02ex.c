/*
Willkommen zum zweiten Aufgabenblatt vom Programmierkurs. Auf diesem Aufgabenblatt geht es um folgende neue Konzepte:

- Blöcke und Scope
- else und else-if
- && und ||
- verschachtelte Schleifen

Um die Tests für dieses Blatt zu kompilieren und zu starten, führen Sie den folgenden Befehl aus:
cc -std=c11 -g -Wall 02ex_test.c -o 02ex_test.o -lm && ./02ex_test.o
*/

/*
Wie auch auf dem ersten Aufgabenblatt können Sie alles außer den Kommentaren ignorieren,
und Ihre Lösungen zwischen den "BEGIN CHANGES" und "END CHANGES" eintragen.
*/

#include <stdio.h> 

int sum_divisible_both(int n) {
    int result = 0;
    /*
    Aufgabe 1a:
    Weisen Sie der Variable `result` die Summe aller Ganzzahlen zwischen `0` und `n` (inklusive) zu, welche sowohl
    durch `7` *als auch* durch `13` teilbar sind.
    */
    /* BEGIN CHANGES */
    while (n>0){
        if (n%7==0 && n%13==0){
            result = result + n;
        }
        n--;
    }
    /* END CHANGES */
    return result;
}

int sum_divisible_or(int n) {
    int result = 0;
    /*
    Aufgabe 1b:
    Weisen Sie der Variable `result` die Summe aller Ganzzahlen zwischen `0` und `n` (inklusive) zu, welche
    durch `7` *oder* durch `13` teilbar sind (das beinhaltet auch die Zahlen, die durch beides teilbar sind).
    */
    /* BEGIN CHANGES */
    while (n>0){
        if (n%7==0 || n%13==0){
            result = result + n;
        }
        n--;
    }
    /* END CHANGES */
    return result;
}

int sum_divisible_either(int n) {
   int result = 0;
    /*
    Aufgabe 1c:
    Weisen Sie der Variable `result` die Summe aller Ganzzahlen zwischen `0` und `n` (inklusive) zu, welche *entweder*
    durch `7` *oder* durch `13` teilbar sind (aber nicht durch beides).
    */
    /* BEGIN CHANGES */
    while (n>0){



         if (n%7==0 || n%13==0){
             if (n%7==0 && n%13==0){
                    result = result;
             }
             else{
                 result = result + n;
             }

        }
        n--;
    }
    /* END CHANGES */
    return result;
}

int signum(int x) {
   int result = 0;
    /*
    Aufgabe 2a:
    Weisen Sie der Variable `result` den Wert `-1` zu, falls `x` strikt negativ ist, `0` falls `x` gleich `0` ist, und
    `1` falls `x` strikt positiv ist.
    */
    /* BEGIN CHANGES */
if (x<0){
    result = -1;
}
else if (x==0){
    result = 0;
}
else if (x>0){
    result = 1;
}
    /* END CHANGES */
    return result;
}

int is_leapyear(int year) {
    int result = 0;
    /*
    Aufgabe 2b:
    Im gregorianischen Kalender ist ein Jahr ein Schaltjahr, genau dann wenn die Jahreszahl durch 400 teilbar ist, oder
    wenn sie durch vier teilbar ist aber nicht durch 100.

    Weisen Sie der Variable `result` den Wert `1` zu, falls `year` ein Schaltjahr ist, und ansonsten `0`.
    */
    /* BEGIN CHANGES */
if (year%400==0||year%4==0&&year%100!=0){
    result = 1;
}
    /* END CHANGES */
    return result;
}

int greatest_of_three(int a, int b, int c) {
    int result = 0;
    /*
    Aufgabe 2c:
    Weisen Sie der Variable `result` den größten Wert zu, den eine der drei Variablen `a`, `b`, `c` hat.
    */
    /* BEGIN CHANGES */
    result = a;
    if (b > result) {
        result = b; // If b is greater than result, update result
    }
    if (c > result) {
        result = c; // If c is greater than result, update result
    }
    return result; // Return the greatest value

    /* END CHANGES */
}

int is_prime(int n) {
   int result = 0;
    /*
    Aufgabe 3a:
    Eine Primzahl ist eine natürliche Zahl größer gleich 2, deren einzigen ganzzahligen Teiler die eins und die Zahl selbst sind.
    Die ersten Primzahlen sind 2, 3, 5, 7, 11, 13, ...

    Weisen Sie der Variable `result` den Wert `1` zu, falls `n` eine Primzahl ist, und ansonsten `0`.
    */
    /* BEGIN CHANGES */
if (n==2){
    result = 1;
}
else if (n>2){
    int i = 2;
    while (i<n){
        if (n%i==0){
            result = 0;
            break;
        }
        else{
            result = 1;
        }
        i++;
    }
}
    /* END CHANGES */
    return result;
}

int sum_first_primes(int n) {
   int result = 0;
    /*
    Aufgabe 3b:
    Weisen Sie der Variable `result` die Summe der ersten `n` Primzahlen zu.
    Beispiel für `n = 4`: `2 + 3 + 5 + 7 = 17`.
    */
    /* BEGIN CHANGES */
    int counter = 2;
while (n>0){
    if(is_prime(counter)==1){
        result = result + counter;
        n--;
    }

    counter ++;
}


//    int sum_first_primes(int n) {
//        int result = 0;
//        int count = 0;
//        for (int i = 2; count < n; i++) {
//            if (is_prime(i)) {
//                result += i;
//                count++;
//            }
//        }
//        return result;
//    }


    /* END CHANGES */
    return result;
}
