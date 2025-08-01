#include "collision_manager.h"

namespace Collision {
    // https://en.wikipedia.org/wiki/Point_in_polygon

    // Fuente: http://jeffreythompson.org/collision-detection/poly-point.php 
    bool pointInPolygon(Vector2 point, vector<Vector2> poly) {
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
        }
        return collision;
    }

    int isLeft(Vector2 P0, Vector2 P1, Vector2 P2) {
        return (int)((P1.x - P0.x) * (P2.y - P0.y) -
        (P2.x - P0.x) * (P1.y - P0.y));
    }

    bool pointInPolygonWinding(Vector2 point, const vector<Vector2>& poly) {
        int wn = 0;
        int n = poly.size();

        for (int i = 0; i < n; i++) {
            Vector2 v0 = poly[i];
            Vector2 v1 = poly[(i + 1) % n];

            if (v0.y <= point.y) {
                if (v1.y > point.y) {
                    if (isLeft(v0, v1, point) > 0)
                        ++wn;
                }
            } else {
                if (v1.y <= point.y) {
                    if (isLeft(v0, v1, point) < 0)
                        --wn;
                }
            }
        }

        return wn != 0;
    }
}
