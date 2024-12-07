#include "dependencies/LuaCEmbed.h"
#include "dependencies/doTheWorld.h"
#include "dependencies/CTextEngine.h"
#include "dependencies/CSilverChainApiNoDependenciesIncluded.h"

//============================ Generators =================================================
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

//============================ Errors ========================================================

LuaCEmbedResponse * private_silver_chain_lua_get_error_msg(LuaCEmbed *args){
    SilverChainError *error = (SilverChainError*)LuaCEmbed_get_long_arg(args,0);
    return LuaCEmbed_send_str(error->error_msg);
}

LuaCEmbedResponse * private_silver_chain_lua_get_error_path(LuaCEmbed *args){
    SilverChainError *error = (SilverChainError*)LuaCEmbed_get_long_arg(args,0);
    return LuaCEmbed_send_str(error->error_path);
}

LuaCEmbedResponse * private_silver_chain_lua_free_error(LuaCEmbed *args){
    SilverChainError *error = (SilverChainError*)LuaCEmbed_get_long_arg(args,0);
    SilverChainError_free(error);
    return NULL;
}

//============================ String Array =================================================
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
    LuaCEmbed_add_callback(l, "generate", private_silver_chain_lua_generator);
    LuaCEmbed_add_callback(l, "generate_watch", private_silver_chain_lua_generator_watch_mode);
    LuaCEmbed_add_callback(l, "get_error_msg", private_silver_chain_lua_get_error_msg);
    LuaCEmbed_add_callback(l, "get_error_path", private_silver_chain_lua_get_error_path);
    LuaCEmbed_add_callback(l, "free_error", private_silver_chain_lua_free_error);
    LuaCEmbed_add_callback(l, "newStringArray", private_silver_chain_lua_new_SiverChainStringArray);
    LuaCEmbed_add_callback(l, "free_string_array", private_silver_chain_lua_free_SiverChainStringArray);
    LuaCEmbed_add_callback(l, "append_string_array", private_silver_chain_lua_apend_SiverChainStringArray);

    return LuaCembed_send_self_as_lib(l);
}
