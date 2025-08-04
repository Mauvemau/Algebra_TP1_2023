#include "collision_manager.h"

namespace Collision {
    // https://en.wikipedia.org/wiki/Point_in_polygon

    int IsLeft(Vector2 P0, Vector2 P1, Vector2 P2);

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

    int IsLeft(Vector2 P0, Vector2 P1, Vector2 P2) { // Producto cruzado.
        return static_cast<int>((P1.x - P0.x) * (P2.y - P0.y) -
                                (P2.x - P0.x) * (P1.y - P0.y));
    } // > 0 izquierda. < 0 derecha. = 0 alineado.

    bool PointInPolygonWinding(Vector2 point, const vector<Vector2>& poly) {
        int wNum = 0;
        int size = poly.size();

        for (int i = 0; i < size; i++) {
            Vector2 vecCurrent = poly[i];
            Vector2 vecNext = poly[(i + 1) % size];

            if (vecCurrent.y <= point.y) {
                if (vecNext.y > point.y) {
                    if (IsLeft(vecCurrent, vecNext, point) > 0)
                        ++wNum;
                }
            } else {
                if (vecNext.y <= point.y) {
                    if (IsLeft(vecCurrent, vecNext, point) < 0)
                        --wNum;
                }
            }
            /*
            Recorremos todos los vectores de el poligono.
            Si estamos bajando y al mismo tiempo cruzando horizontalmente al punto
            y ademas el punto se encuentra del lado izquierdo sumamos 1 punto.
            Si estamos subiendo y al mismo tiempo cruzando horizontalmente al pundo
            y ademas el punto se encuentra del lado derecho restamos 1 punto.
            Si el resultado es 0 entonces nos encontramos dentro.
            */
        }

        return wNum != 0;
    }
}
