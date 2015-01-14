#include <lua.h>
#include <lauxlib.h>

#include <stdlib.h> /* For function exit() */
#include <stdio.h> /* For input/output */

void bail(lua_State *L, char *msg){
	fprintf(stderr, "\nFATAL ERROR:\n %s: %s\n\n",
			msg, lua_tostring(L, -1));
	exit(1);
}
int lua_print(lua_State *L, double x) { /* call lua print */
	/* push functions and arguments */
	lua_getglobal(L, "print"); /* function to be called */
	lua_pushnumber(L, x); /* push 1st argument */
	/* do the call (1 arguments, 1 result) */
	if (lua_pcall(L, 1, 0, 0) != 0)
	{
		return 2;
	}
	return 0;
}
#define err_exit(num,fmt,args...)  \
    do{printf("[%s:%d]"fmt"\n",__FILE__,__LINE__,##args);exit(num);} while(0)
#define err_return(num,fmt,args...)  \
		    do{printf("[%s:%d]"fmt"\n",__FILE__,__LINE__,##args);return(num);} while(0)

int main(int argc, const char *argv[])
{
	int ret = 0;
	lua_State *L = luaL_newstate(); /* Create new lua state variable */
	/* Load Lua libraries, otherwise, the lua function in *.lua will be nil */
	luaL_openlibs(L);
    ret =	luaL_loadfile(L, "./test_seri.lua");
	if( 0 != ret)
	{
		err_return(-1, "luaL_loadfile failed:%s", lua_tostring(L, -1));
	}
	ret = lua_pcall(L, 0, 0, 0);

	lua_getglobal(L, "loadstate");
	ret = lua_pcall(L, 0, 0, 0);
	if( 0 != ret)
	{
		err_return(-1, "lua_pcall failed:%s", lua_tostring(L, -1));
	}
	lua_getglobal(L, "print_debug");
	lua_pcall(L, 0,0,0);
	lua_close(L);                   /* Close the lua state variable */    

	return 0;
}
