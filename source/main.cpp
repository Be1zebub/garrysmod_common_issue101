#include <GarrysMod/Lua/Interface.h>
#include <GarrysMod/Interfaces.hpp>
#include <GarrysMod/InterfacePointers.hpp>
#include <icvar.h>

GMOD_MODULE_OPEN() {
    ICvar* icvar = InterfacePointers::Cvar();
    if (!icvar) {
        LUA->PushSpecial(GarrysMod::Lua::SPECIAL_GLOB);
        LUA->GetField(-1, "print");
        LUA->PushString("Failed to get ICvar interface!");
        LUA->Call(1, 0);
    	LUA->Pop();
    }
    
    return 0;
}
