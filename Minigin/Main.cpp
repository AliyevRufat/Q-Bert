#include "MiniginPCH.h"

#if _DEBUG
// ReSharper disable once CppUnusedIncludeDirective
#include <vld.h>
#endif

#include "SDL.h"
#include "Minigin.h"

extern "C"
{
#include "../3rdParty/Lua5.4.2/include/lua.h"
#include "../3rdParty/Lua5.4.2/include/lauxlib.h"
#include "../3rdParty/Lua5.4.2/include/lualib.h"
}

#ifdef  _WIN64
#pragma comment(lib, "../3rdParty/Lua5.4.2/liblua54.a")
#endif //  _WIN64

int main(int, char* [])
{
	dae::Minigin engine;
	engine.Run();
	return 0;
}