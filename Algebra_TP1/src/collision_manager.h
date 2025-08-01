#pragma once

#include "raylib.h"
#include <vector>

using namespace std;

namespace Collision {
	// Devuelve si hay colisi�n entre un array de vectices y un punto
	bool pointPolygon(Vector2 point, vector<Vector2> poly);
	bool pointInPolygonWinding(Vector2 point, const vector<Vector2>& poly);
}
