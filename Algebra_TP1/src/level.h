#pragma once
#include "raylib.h"
#include <vector>

using namespace std;

namespace Level {
	// Verifica si el jugador esta "colisionando" con el nivel
	bool CheckCollisions(Vector2 playerPosition);

	// A�ade una nueva forma al nivel
	void AddShape(vector<Vector2> shape);

	// Borra el nivel entero
	void Wipe();

	void Draw();
}