#pragma once
#include "raylib.h"
#include <vector>

using namespace std;

namespace Level {
	// Añade una nueva forma al nivel
	void addShape(vector<Vector2> shape);

	// Borra el nivel entero
	void wipe(); 

	void draw();
}