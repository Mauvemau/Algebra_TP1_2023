#include "level.h"

#include <list>

#include "collision_manager.h"

namespace Level {
	vector<vector<Vector2>> shapes;

	static void drawShape(vector<Vector2> shape);

	void drawShape(vector<Vector2> shape) {
		for (int i = 0; i < static_cast<int>(shape.size()); i++)
		{
			if (i < static_cast<int>(shape.size()) - 1) {
				DrawLineV(shape[i], shape[i + 1], ORANGE);
			}
		}
		DrawLineV(shape.back(), shape.front(), ORANGE);
	}

	// Public
	bool checkCollisions(Vector2 playerPosition) {
		bool colliding = false;
		for (int i = 0; i < static_cast<int>(shapes.size()); i++) {
			if (Collision::pointPolygon(playerPosition, shapes[i])) {
				colliding = true;
			}
		}
		return colliding;
	}

	void addShape(vector<Vector2> shape) {
		shapes.push_back(shape);
	}

	void wipe() {
		shapes.clear();
	}

	void draw() {
		if (!shapes.empty()) {
			for (int i = 0; i < static_cast<int>(shapes.size()); i++) {
				drawShape(shapes[i]);
			}
		}
	}
}