//Include
#include "utils.h"
#include "Windows.h"

//Funcions
bool IsKeyDown(int virtualKeyCode)
{
	short keyState = GetAsyncKeyState(virtualKeyCode);
	return((keyState & 0x8000) > 0);
}

int GetRandomInt(int min, int max)
{
	return min + rand() % (max - min + 1);
}