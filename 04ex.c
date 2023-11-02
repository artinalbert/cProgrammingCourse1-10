/*
Willkommen zum vierten Aufgabenblatt vom Programmierkurs. Auf diesem Aufabenblatt geht es darum, ein komplizierteres Problem wiederholt in Teilprobleme zu zerlegen.

Um die Tests für dieses Blatt zu kompilieren und zu starten, führen Sie den folgenden Befehl aus:
cc -std=c11 -g -Wall 04ex_test.c 04ex_helpers.c -o 04ex_test.o -lm && ./04ex_test.o
*/

#include "04_canvas.h"
#include "04ex_helpers.h"
#include <stdio.h>

/*
Aufgabe 1a:
In diesem Aufgabenblatt schreiben wir eine Funktion, um auf der Canvas gefüllte Kreise zu zeichnen. Kreise sind konzeptionell einfach:
Haben wir einen Mittelpunkt und einen Radius, können wir alle Punkte schwarz färben, deren Distanz zum
Mittelpunkt kleiner oder gleich des Radius ist.

Für diese Aufgabe, implementieren Sie eine Funktion die genau das tut. Gegeben sind die Koordinaten `x` und `y` des
Mittelpixels und ein Radius. Nun sollen alle Pixel, die innerhalb der Distanz um diesen Mittelpixel liegen schwarz
gefärbt werden. Durch diese Methode entstehen immer Kreise mit ungeradem Durchmesser, da wir mit diskreten Pixeln arbeiten.
Der Mittelpixel hat eine Distanz von 0 zu sich selbst, und daher muss er immer schwarz gefärbt werden, selbst bei Radius 0.
Nutzen Sie für die Distanzbestimmung die `distance` Funktion aus `04ex_helpers.h`.
Headerfile und die zugehörige Implementierung sind bereits eingebunden, die Funktion kann
also einfach verwendet werden.
*/
Canvas draw_odd_circle(Canvas c, int x, int y, int radius_from_middle) {
    for (size_t current_x = 0; current_x < canvas_width(c); current_x++)
    {
        for (size_t current_y = 0; current_y < canvas_height(c); current_y++)
        {
            if (distance(x, y, current_x, current_y) <= radius_from_middle)
            {
                c = canvas_set_black(c, current_x, current_y);
            }
            
        }
        
    }
    return c;
}

/*
Aufgabe 1b:
Implementieren Sie nun selbst eine Funktion, welche die abgerundete Distanz zwischen zwei Punkten (`x0`, `y0`)
und (`x1`, `y1`) berechnet.
Sei `a := x1 - x0` und `b := y1 - y0`. Dann liefert uns der Satz des Pythagoras die Distanz zwischen den Punkten als
`c := quadratwurzel(a^2 + b^2)`.
Die Datei `04ex_helpers.h` mit den Hilsfunktionen enthält eine Funktion `squareroot`. Nutzen Sie diese Funktion, um die
Distanz zu berechnen.
*/
int my_distance(int x0, int y0, int x1, int y1) {
    int a = x1 - x0;
    int b = y1 - y0;
    return squareroot(a * a + b * b);
}

/*
Aufgabe 1c:
Implementieren Sie nun selbst die Berechnung der abgerundeten Quadratwurzel von `n`.
Tipp: Finden Sie die größte natürliche Zahl, deren Quadrat kleiner oder gleich `n` ist. Es muss nicht effizient sein, wir
testen nur mit relativ kleinen Zahlen.
*/
int my_squareroot(int n) {
    int pre_nr = 0;
    while((pre_nr + 1) * (pre_nr + 1) <= n)
    {
        pre_nr++;
    }
    return pre_nr;
}

/*
Aufgabe 1d:
Die Kreisfunktion aus Aufgabe 1a erstellt immer nur Kreise mit ungeradem Durchmesser. Kreise mit einem
geraden Durchmesser haben keinen einzelnen Mittelpixel, demnach benötigen wir eine flexiblere Kreis-Zeichnungs Funktion
mit anderen Parametern, um diese Kreise zeichnen zu können.
`x` ist die x-Koordinate der linkesten Pixel des Kreises, `y` ist die y-koordinate der untersten Pixel des Kreises,
`diameter` ist der Durchmesser. Dadurch ist `(x,y)` die Koordinate der unteren linken Ecke des kleinsten Quadrats (der
Länge und Breite `diameter`) welches den erwünschten Kreis vollständig enthält.

Um Kreise mit _ungeradem_ Durchmesser zu erstellen, können Sie einfach Ihre `draw_odd_circle` Funktion ein mal aufrufen.
Für Kreise mit _geradem_ Durchmesser rufen Sie Ihre `draw_odd_circle` vier mal auf: Einmal für jeden der vier Pixel
welche den exakten Mittelpunkt des erwünschten Kreises umgeben.
*/
Canvas draw_circle(Canvas c, int x, int y, int diameter) {
    int radius = diameter * 0.49;
    if(diameter % 2 == 0)
    {
        c = draw_odd_circle(c, x + diameter, y+radius, radius);
        // c = draw_odd_circle(c, x+radius-1, y+radius, radius+1);
        // c = draw_odd_circle(c, x+radius, y+radius-1, radius+1);
        // c = draw_odd_circle(c, x+radius-1, y+radius-1, radius+1);
    }
    else
    {
        c = draw_odd_circle(c, x+radius, y+radius, radius);
    }
    
    return c;
}

/*
Aufgabe 1e:
Dadurch, dass Sie das Problem in kleinere Subprobleme geteilt haben, haben Sie gerade eine vollständige Funktion zum
Kreisezeichnen implementiert. Das ist ziemlich cool!
Geben Sie zur Feier `5` zurück.
*/
int high_five() {
    return 5;
}

/*
Aufgabe 2a:
Gegeben sei eine natürliche Zahl `n`. Falls sie gerade ist, teilen Sie sie durch zwei, ansonsten multiplizieren Sie sie
mit drei und addieren eins. Wiederholen Sie dies bis Sie als Ergebnis die Zahl `1` erreichen. Die Anzahl Wiederholungen
die Sie dafür benötigen ist die _Hailstone-Zahl von `n`_.
Zum Beispiel `hailstone(1) == 0`, `hailstone(4) == 2` (4 -> 2 -> 1), und `hailstone(5) == 5` (5 -> 16 -> 8 -> 4 -> 2 -> 1).
Berechnen Sie die Hailstone-Zahl vom Parameter `n`.
*/
int hailstone(int n) {
    int hailstone_nr = 0;
    while (n != 1)
    {
        if(n % 2 == 0)
        {
            n = n / 2;
        }
        else
        {
            n = n * 3 + 1;
        }
        hailstone_nr++;
    }
    return hailstone_nr;
}

/*
Aufgabe 2b:
Unser Testrunner hat keine Tests für Aufgabe 2a. Falls Sie Ihre Lösung selber testen wollen, erstellen Sie am besten
eine separate C-Datei wo Sie Ihre Lösung hineinkopieren und gegen einige Beispielwerte testen.
Falls Sie keine Beispielwerte von Hand berechnen wollen, schauen Sie am besten hier nach:  https://oeis.org/A006577

Für die _Bewertung_ von diesem Aufgabenblatt lassen wir Tests für Aufgabe 2a laufen, zum Debuggen müssen Sie
allerdings Ihre eigenen Tests schreiben.
Lassen Sie `99` von dieser Funktion zurückgeben um zu zeigen, dass Sie das verstanden haben.
*/
int bring_your_own_tests() {
    return 99;
}
