#include "collision_manager.h"

namespace Collision {
    // https://en.wikipedia.org/wiki/Point_in_polygon

    bool PointInPolygon(Vector2 point, vector<Vector2> poly) {
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
                collision = !collision; // Even odd rule
            }
            /*
            Me fijo que el punto se encuentre verticalmente a la altura del vector y casteo un rayo horizontalmente hacia la derecha.
            Si el rayo colisiona una cantidad inpar de veces significa que nos encontramos dentro, si colisiona una cantidad par significa
            que nos encontramos fuera.
            */
        }
        return collision;
    }
}
