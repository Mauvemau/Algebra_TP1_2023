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