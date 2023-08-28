#pragma once
#include "raylib.h"
#include <vector>

using namespace std;

namespace Level {
	// Verifica si el jugador esta "colisionando" con el nivel
	bool checkCollisions(Vector2 playerPosition);

	// Añade una nueva forma al nivel
	void addShape(vector<Vector2> shape);

	// Borra el nivel entero
	void wipe(); 

	void draw();
}