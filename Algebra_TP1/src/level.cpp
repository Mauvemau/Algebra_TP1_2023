#include "level.h"

#include <list>

namespace Level {
	vector<vector<Vector2>> shapes;

	static void drawShape(vector<Vector2> shape);

	void drawShape(vector<Vector2> shape) {
		for (int i = 0; i < shape.size(); i++)
		{
			if (i < shape.size() - 1) {
				DrawLineV(shape[i], shape[i + 1], ORANGE);
			}
		}
		DrawLineV(shape.back(), shape.front(), ORANGE);
	}

	// Public
	void addShape(vector<Vector2> shape) {
		shapes.push_back(shape);
	}

	void wipe() {
		shapes.clear();
	}

	void draw() {
		if (!shapes.empty()) {
			for (int i = 0; i < shapes.size(); i++) {
				drawShape(shapes[i]);
			}
		}
	}
}