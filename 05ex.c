/*
Willkommen zum fünften Aufgabenblatt vom Programmierkurs. Auf diesem Aufabenblatt geht es um Rekursion.

Um die Tests für dieses Blatt zu kompilieren und zu starten, führen Sie den folgenden Befehl aus:
cc -std=c11 -g -Wall 05ex_test.c -o 05ex_test.o -lm && ./05ex_test.o
*/

#include "05_canvas.h"
#include <stdio.h>
#include <math.h>

int valid_coordinate(Canvas c, int x, int y) {
    return (
        0 <= x
        && 0 <= y
        && x < canvas_width(c)
        && y < canvas_height(c)
    );
}

/*
Aufgabe 1a:
Zeichnen Sie eine horizontale Linie der Länge `width`, deren am weitesten links liegender Pixel bei `(x, y)` ist.

_Benutzen Sie keine Schleifen - Die Aufgabe soll über Rekursion gelöst werden!_

*/
Canvas recursive_line(Canvas c, int x, int y, int width) {
    if (width == 0) {
        return c;
    }
    int x_to_mark = x + width - 1;
    if(valid_coordinate(c, x_to_mark, y))
    {
        c = canvas_set_black(c, x_to_mark, y);
    }
    c = recursive_line(c, x, y, width - 1);
    return c;
}

/*
Aufgabe 1b:
Zeichnen Sie ein Rechteck mit der Breite `width` und der Höhe `height`. Der Pixel der linken unteren Ecke liegt bei `(x, y)`.

_Benutzen Sie keine Schleifen, die Aufgabe soll über Rekursion gelöst werden!_
*/
Canvas recursive_rectangle(Canvas c, int x, int y, int width, int height) {
    if(width <= 0 || height <= 0)
    {
        return c;
    }
    
    if(width == 1)
    {
        if(valid_coordinate(c, x, y))
        {
            c = canvas_set_black(c, x, y);
        }
        c = recursive_rectangle(c, x, y+1, 1, height-1);
    }
    else
    {
        c = recursive_rectangle(c, x, y, 1, height);
        c = recursive_rectangle(c, x+1, y, width-1, height);
    }

    return c;
}

/*
Aufgabe 2:
Der *Sierpinski Carpet der Ordnung 0* ist ein einzelnes schwarzes Pixel.
Der *Sierpinski Carpet der Ordnung n+1* besteht aus acht Sierpinski Carpets der Ordnung n, angeordnet als drei-mal-drei
Quadrat dessen Mittelstück fehlt.

Beispiele (`X` stellt schwarze Pixel dar)
=========================================

Ordnung 0:

X

Ordnung 1:

XXX
X X
XXX

Ordnung 2:

XXXXXXXXX
X XX XX X
XXXXXXXXX
XXX   XXX
X X   X X
XXX   XXX
XXXXXXXXX
X XX XX X
XXXXXXXXX

Siehe auch die Datei `05sierpinski.jpg`

Aufgabe 2a:
Um in der nächsten Aufgabe den Sierpinski-Carpet auf die Canvas zeichnen zu können müssen Potenzen berechnet werden.
Implementieren Sie die Berechnung der Potenz einer nicht-negativen, ganzzahligen Basis `b` mit einem
nicht-negativen, ganzzahligen Exponenten `exp`.

_Benutzen Sie keine Schleifen, die Aufgabe soll über Rekursion gelöst werden!_
*/
int power(int b, int exp){
    if(exp == 0){
        return 1;
    }
   return b * power(b, exp - 1);
}

/*
Aufgabe 2b:
Diese Funktion soll den Sierpinski Carpet der Ordnung `n` auf die Canvas zeichnen, mit unterer linker Ecke an Koordinate `(x, y)`.

_Benutzen Sie keine Schleifen, die Aufgabe soll über Rekursion gelöst werden!_
*/
Canvas sierpinski_carpet(Canvas c, int n, int x, int y){
    if(n == 0)
    {
        return canvas_set_black(c, x, y);
    }
    float thirds = power(3, n) / 3.0;
    c = sierpinski_carpet(c, n-1, x, y);
    c = sierpinski_carpet(c, n-1, x+thirds, y);
    c = sierpinski_carpet(c, n-1, x+(thirds*2), y);
    c = sierpinski_carpet(c, n-1, x, y+thirds);
    // Leaving middle empty
    c = sierpinski_carpet(c, n-1, x+(thirds*2), y+thirds);
    c = sierpinski_carpet(c, n-1, x, y+(thirds*2));
    c = sierpinski_carpet(c, n-1, x+thirds, y+(thirds*2));
    c = sierpinski_carpet(c, n-1, x+(thirds*2), y+(thirds*2));
    return c;
}

/*
Aufgabe 3:
Implementieren Sie einen Fülleimer. Gegeben eine Koordinate `(x, y)` auf einer (bereits bemalten) Canvas, soll die komplette
zusammenhängende Fläche aller Pixel der selben Farbe (schwarz oder weiß) schwarz gefärbt werden.
Zwei Pixel sind Teil der selben Fläche wenn sie die selbe Farbe haben und direkt benachbart sind. Jeder Pixel hat bis
zu vier direkte Nachbarn - die Diagonalen zählen nicht.

Funktionen, um die Farbe eines Pixels auf der Canvas zu bestimmen, sind im Headerfile der Canvas dokumentiert.
*/
Canvas bucket_fill(Canvas c, int x, int y) {
    if(pixel_is_black(c, x, y))
    {
        c = canvas_set_white(c, x, y);
        for (int x_surrounding = x-1; x_surrounding < x+2; x_surrounding++)
        {
            for (int y_surrounding = y-1; y_surrounding < y+2; y_surrounding++)
            {
                if(
                    x_surrounding != x
                    && y_surrounding != y
                    && x_surrounding >= 0
                    && y_surrounding >= 0
                    && x_surrounding < canvas_width(c)
                    && y_surrounding < canvas_height(c)
                    && pixel_is_black(c, x_surrounding, y_surrounding)
                )
                {
                    c = bucket_fill(c, x_surrounding, y_surrounding);
                }
            }
        }
    }
    else if(pixel_is_white(c, x, y))
    {
        c = canvas_set_black(c, x, y);
        for (int x_surrounding = x-1; x_surrounding < x+2; x_surrounding++)
        {
            for (int y_surrounding = y-1; y_surrounding < y+2; y_surrounding++)
            {
                // printf("x: %d, y: %d\n", x_surrounding, y_surrounding);
                if(
                    x_surrounding != x
                    && y_surrounding != y
                    && x_surrounding >= 0
                    && y_surrounding >= 0
                    && x_surrounding < canvas_width(c)
                    && y_surrounding < canvas_height(c)
                    && pixel_is_white(c, x_surrounding, y_surrounding)
                )
                {
                    c = bucket_fill(c, x_surrounding, y_surrounding);
                }
            }
        }
    }
    return c;
}
