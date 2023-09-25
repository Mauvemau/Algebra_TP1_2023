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

            if (((vecCurrent.y >= point.y && vecNext.y < point.y) || (vecCurrent.y < point.y && vecNext.y >= point.y)) &&
                (point.x < (vecNext.x - vecCurrent.x) * (point.y - vecCurrent.y) / (vecNext.y - vecCurrent.y) + vecCurrent.x)) {
                collision = !collision;
            }
        }
        return collision;
    }
}