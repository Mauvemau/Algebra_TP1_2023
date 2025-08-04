#pragma once

#include "raylib.h"
#include <vector>

using namespace std;

namespace Collision {
	// Devuelve si hay colisi�n entre un array de vectices y un punto
	bool PointInPolygon(Vector2 point, vector<Vector2> poly);
	bool PointInPolygonWinding(Vector2 point, const vector<Vector2>& poly);
}
