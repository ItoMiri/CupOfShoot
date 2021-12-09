#include "KeyboardInput.h"

int KeyboardInput::key[KB_MAX];

KeyboardInput::KeyboardInput()
{
    for (int i = 0; i < KB_MAX; i++) {
        KeyboardInput::key[i] = 0;
    }
}

KeyboardInput::~KeyboardInput()
{
}

void KeyboardInput::Update()
{
    static char buf[KB_MAX];
    GetHitKeyStateAll(buf);
    for (int i = 0; i < KB_MAX; i++) {
        if (buf[i]) {
            if (KeyboardInput::key[i] == KB_PRESS_NONE) KeyboardInput::key[i] = KB_PRESS_FIRST;
            else if (KeyboardInput::key[i] >= KB_PRESS_FIRST) KeyboardInput::key[i] = KB_PRESS_PRESSING;
        }
        else KeyboardInput::key[i] = KB_PRESS_NONE;
    }
}

int KeyboardInput::GetKey(int key)
{
    if (key < 0 || key > KB_MAX) return -1;
    return KeyboardInput::key[key];
}
