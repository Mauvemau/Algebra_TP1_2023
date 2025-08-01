#pragma once

namespace Program {
	enum class ProgramState {
		DRAW = 0,
		PLAY
	};

	void SetState(ProgramState state);
	void Close();
	void Start();
}
