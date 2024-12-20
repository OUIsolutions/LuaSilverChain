#include "dependencies/LuaCEmbed.h"
#include "dependencies/doTheWorld.h"
#include "dependencies/CTextEngine.h"
#include "dependencies/CSilverChainApiNoDependenciesIncluded.h"

#ifdef __linux__
#define  private_lua_silver_chain_ptr_cast long long
#endif

#ifdef  _WIN32
#define  private_lua_silver_chain_ptr_cast  long

#endif



char * private_silver_chain_get_str_arg_if_exist(LuaCEmbed *args,int index){
    if(LuaCEmbed_get_arg_type(args, index) == LUA_CEMBED_STRING){
        return  LuaCEmbed_get_str_arg(args,index);
    }
    return NULL;
}

//============================ Generators =================================================
LuaCEmbedResponse * private_silver_chain_lua_generator(LuaCEmbed *args){
    char *src = LuaCEmbed_get_str_arg(args, 0);
    char *import_dir = LuaCEmbed_get_str_arg(args,1);
    char * project_short_cut =  LuaCEmbed_get_str_arg(args,2);
    SilverChainStringArray *tags = (SilverChainStringArray*)(private_lua_silver_chain_ptr_cast)LuaCEmbed_get_long_arg(args,3);
    bool implement_main = LuaCEmbed_get_bool_arg(args, 4);
    char *main_name = private_silver_chain_get_str_arg_if_exist(args,5);
    char *main_path = private_silver_chain_get_str_arg_if_exist(args,6);
    if(LuaCEmbed_has_errors(args)){
        printf("%s\n",LuaCEmbed_get_error_message(args));
    }

    SilverChainError *error = SilverChain_generate_code(src,import_dir,project_short_cut,tags,implement_main, main_name,main_path);
    return LuaCEmbed_send_long((private_lua_silver_chain_ptr_cast)error);
}

LuaCEmbedResponse * private_silver_chain_lua_generator_watch_mode(LuaCEmbed *args){
    char *src = LuaCEmbed_get_str_arg(args, 0);
    char *import_dir = LuaCEmbed_get_str_arg(args,1);
    char * project_short_cut =  LuaCEmbed_get_str_arg(args,2);
    SilverChainStringArray *tags = (SilverChainStringArray*)(private_lua_silver_chain_ptr_cast)LuaCEmbed_get_long_arg(args,3);
    bool implement_main = LuaCEmbed_get_bool_arg(args, 4);
    char *main_name = private_silver_chain_get_str_arg_if_exist(args,5);
    char *main_path = private_silver_chain_get_str_arg_if_exist(args,6);
    int timeout =  LuaCEmbed_get_long_arg(args,6);
    SilverChain_generate_code_in_watch_mode(src,import_dir,project_short_cut,tags,implement_main, main_name,main_path,timeout);
    return NULL;
}

//============================ Errors ========================================================

LuaCEmbedResponse * private_silver_chain_lua_get_error_msg(LuaCEmbed *args){
    SilverChainError *error = (SilverChainError*)(private_lua_silver_chain_ptr_cast)LuaCEmbed_get_long_arg(args,0);
    return LuaCEmbed_send_str(error->error_msg);
}

LuaCEmbedResponse * private_silver_chain_lua_get_error_path(LuaCEmbed *args){
    SilverChainError *error = (SilverChainError*)(private_lua_silver_chain_ptr_cast)LuaCEmbed_get_long_arg(args,0);
    return LuaCEmbed_send_str(error->error_path);
}

LuaCEmbedResponse * private_silver_chain_lua_free_error(LuaCEmbed *args){
    SilverChainError *error = (SilverChainError*)(private_lua_silver_chain_ptr_cast)LuaCEmbed_get_long_arg(args,0);
    SilverChainError_free(error);
    return NULL;
}

//============================ String Array =================================================
LuaCEmbedResponse * private_silver_chain_lua_new_SiverChainStringArray(LuaCEmbed *args){
    SilverChainStringArray *value = newSilverChainStringArray();
    return LuaCEmbed_send_long((private_lua_silver_chain_ptr_cast )value);
}

LuaCEmbedResponse * private_silver_chain_lua_free_SiverChainStringArray(LuaCEmbed *args){
    SilverChainStringArray *value = (SilverChainStringArray*)(private_lua_silver_chain_ptr_cast)LuaCEmbed_get_long_arg(args,0);
    SilverChainStringArray_free(value);
    return NULL;
}

LuaCEmbedResponse * private_silver_chain_lua_apend_SiverChainStringArray(LuaCEmbed *args){
    SilverChainStringArray *value = (SilverChainStringArray*)(private_lua_silver_chain_ptr_cast)LuaCEmbed_get_long_arg(args,0);
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
