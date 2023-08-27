#pragma once

namespace Program {
	enum class ProgramState {
		DRAW = 0,
		PLAY
	};

	void setState(ProgramState state);
	void close();
	void start();
}
