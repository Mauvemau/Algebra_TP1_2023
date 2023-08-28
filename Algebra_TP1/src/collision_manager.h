#pragma once

#include "raylib.h"
#include <vector>

using namespace std;

namespace Collision {
	bool pointPolygon(Vector2 point, vector<Vector2> poly);
}