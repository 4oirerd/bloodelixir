#include <lua.h>
#include <lauxlib.h>
#include <lualib.h>
#include <stdio.h>

static int lua_say_hello(lua_State *L)
{
	const char *name = luaL_optstring(L, 1, "stranger");
	printf("Hello, %s!\n", name);
	return 0;
}

int main(void)
{
	lua_State *L = luaL_newstate();
	luaL_openlibs(L);
	lua_register(L, "hello", lua_say_hello);
	const char *script = "hello('Peter')\nhello()";
	if(luaL_dostring(L, script) != LUA_OK)
	{
		fprintf(stderr, "Error: %s\n", lua_tostring(L, -1));
		lua_pop(L, 1);

	}

	lua_close(L);
	return 0;
}
