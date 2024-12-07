#include "dependencies/LuaCEmbed.h"
#include "dependencies/doTheWorld.h"
#include "dependencies/CTextEngine.h"
#include "dependencies/CSilverChainApiNoDependenciesIncluded.h"

LuaCEmbedResponse * private_silver_chain_lua_generator(LuaCEmbed *args){
    char *src = LuaCEmbed_get_str_arg(args, 0);
    char *import_dir = LuaCEmbed_get_str_arg(args,1);
    char * project_short_cut =  LuaCEmbed_get_str_arg(args,2);
    SilverChainStringArray *tags = (SilverChainStringArray*)LuaCEmbed_get_long_arg(args,3);
    bool implement_main = LuaCEmbed_get_bool_arg(args, 4);
    char *main_name = LuaCEmbed_get_str_arg(args,5);
    char *main_path = LuaCEmbed_get_str_arg(args,5);

    SilverChainError *error = SilverChain_generate_code(src,import_dir,project_short_cut,tags,implement_main, main_name,main_path);
    if(error){
        return LuaCEmbed_send_long((long)error);
    }
    return NULL;
}

LuaCEmbedResponse * private_silver_chain_lua_generator_watch_mode(LuaCEmbed *args){
    char *src = LuaCEmbed_get_str_arg(args, 0);
    char *import_dir = LuaCEmbed_get_str_arg(args,1);
    char * project_short_cut =  LuaCEmbed_get_str_arg(args,2);
    SilverChainStringArray *tags = (SilverChainStringArray*)LuaCEmbed_get_long_arg(args,3);
    bool implement_main = LuaCEmbed_get_bool_arg(args, 4);
    char *main_name = LuaCEmbed_get_str_arg(args,5);
    char *main_path = LuaCEmbed_get_str_arg(args,5);
    int timeout =  LuaCEmbed_get_long_arg(args,6);
    SilverChain_generate_code_in_watch_mode(src,import_dir,project_short_cut,tags,implement_main, main_name,main_path,timeout);
    return NULL;
}



LuaCEmbedResponse * private_silver_chain_lua_new_SiverChainStringArray(LuaCEmbed *args){
    SilverChainStringArray *value = newSilverChainStringArray();
    return LuaCEmbed_send_long((long)value);
}

LuaCEmbedResponse * private_silver_chain_lua_free_SiverChainStringArray(LuaCEmbed *args){
    SilverChainStringArray *value = (SilverChainStringArray*)LuaCEmbed_get_long_arg(args,0);
    SilverChainStringArray_free(value);
    return NULL;
}

LuaCEmbedResponse * private_silver_chain_lua_apend_SiverChainStringArray(LuaCEmbed *args){
    SilverChainStringArray *value = (SilverChainStringArray*)LuaCEmbed_get_long_arg(args,0);
    char *str  = LuaCEmbed_get_str_arg(args, 1);
    SilverChainStringArray_append(value, str);
    return NULL;
}



int luaopen_private_silverchain_cinterop(lua_State *state){
    //functions will be only assescible by the required reciver
    LuaCEmbed * l = newLuaCEmbedLib(state);
    LuaCEmbed_set_long_lib_prop(l,"CAMALGAMATOR_UNEXPECTED_ERROR",CAMALGAMATOR_UNEXPECTED_ERROR);
    LuaCEmbed_set_long_lib_prop(l,"CAMALGAMATOR_DONT_INCLUDE",CAMALGAMATOR_DONT_INCLUDE);
    LuaCEmbed_set_long_lib_prop(l,"CAMALGAMATOR_DONT_CHANGE",CAMALGAMATOR_DONT_CHANGE);
    LuaCEmbed_set_long_lib_prop(l,"CAMALGAMATOR_INCLUDE_ONCE",CAMALGAMATOR_INCLUDE_ONCE);
    LuaCEmbed_set_long_lib_prop(l,"CAMALGAMATOR_INCLUDE_PERPETUAL",CAMALGAMATOR_INCLUDE_PERPETUAL);

    LuaCEmbed_add_callback(l,"generate_amalgamation_simple",private_lua_c_amalgamator_generate_amalgamation_simple);
    LuaCEmbed_add_callback(l,"generate_amalgamation_complex",private_lua_c_amalgamator_generate_amalgamation_complex);
    return LuaCembed_send_self_as_lib(l);
}
