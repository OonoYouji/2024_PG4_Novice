#include "InputManager.h"

#include <Novice.h>

void InputManager::Initialize() {

}

void InputManager::Update() {

	memcpy(preKeys_, keys_, 256);
	Novice::GetHitKeyStateAll(keys_);

}

void InputManager::Finalize() {

}
