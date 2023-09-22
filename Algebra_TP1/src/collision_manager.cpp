#include "collision_manager.h"

namespace Collision {
    // Fuente: http://jeffreythompson.org/collision-detection/poly-point.php 
    bool pointPolygon(Vector2 point, vector<Vector2> poly) {
        bool collision = false;
        // Recorremos cada uno de los vertices + el que le siga.
        int next = 0;
        for (int current = 0; current < poly.size(); current++) {
            // Conseguimos el indice de nuestro siguiente vertice sumandole 1 al actual.
            // Si se llega al final, cerramos la forma volviendo al primero (0).
            next = current + 1;
            if (next == poly.size()) next = 0;

            // Sacamos las posiciones de nuestros vectores usando los indices.
            Vector2 vecCurrent = poly[current];    // El vector actual
            Vector2 vecNext = poly[next];       // El vector siguiente

            /* 
            Para determinar la colisión usamos esta formula, la cual es una implementación del Teorema de la Curva de Jordan.
            Lo que hace esta función es verificar si nuestro punto (En nuestro caso "point") se encuentra dentro de un poligono.
            (En este caso tenemos una forma compuesta por varios poligonos, los cuales recorremos con el for y comprobamos individualmente
            del primero al ultimo al igual de como se dibujaron.)
            
            Esta condicion se divide en dos partes (Separadas por el &&)
            La primera parte verifica que el punto se encuentre verticalmente entre los dos puntos del poligono actual (vecCurrent y vecNext).
            La segunda parte verifica que el punto se encuentre horizontalmente dentro de la forma;
            Esto lo logra usando el Teorema de la Curva de Jordan, esta verifica si el punto (point) cruza verticalmente por linea vertical que pasa por los dos
            puntos del poligono actual (vecCurrent y vecNext). En este caso, usando el operador "!" podemos invertir esta variable de forma de que la colisión sea
            verdadera unicamente si esta condición da verdadera un numero inpar de veces.

            Cabe destacar que El teorema de la Curva de Jordan funciona unicamente con formas simples en 2 dimensiones.
            */ 
            if (((vecCurrent.y >= point.y && vecNext.y < point.y) || (vecCurrent.y < point.y && vecNext.y >= point.y)) &&
                (point.x < (vecNext.x - vecCurrent.x) * (point.y - vecCurrent.y) / (vecNext.y - vecCurrent.y) + vecCurrent.x)) {
                collision = !collision;
            }
        }
        return collision;
    }
}