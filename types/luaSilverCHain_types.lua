---@class PrivateSilverChainCInterop
---@field generate fun(src:string,import_dir:string,project_short_cut:string,tags:number,implement_main:boolean,main_file:string,main_path:string):number
---@field generate_watch fun(src:string,import_dir:string,project_short_cut:string,tags:number,implement_main:boolean,main_file:string,main_path:string,timeout:number):number
---@field get_error_msg fun(error:number):string
---@field get_error_path fun(error:number):string
---@field free_error fun(error:number)
---@field newStringArray fun():number
---@field free_string_array fun(string_array:number)
---@field append_string_array fun(string_array:number,value:string)

---@type PrivateSilverChainCInterop
private_silverchain_cinterop = private_silverchain_cinterop

---@class PrivateSilverChain
---@field check_types fun(value:any,valid_types:string[])


---@field PrivateSilverChain
private_silver_chain = private_silver_chain

---@class GenerationProps
---@field src string
---@field import_dir string | nil
---@field project_short_cut string | nil
---@field tags string[]
---@field implement_main boolean | nil
---@field main_file string | nil
---@field main_path string | nil
---@field timeount number | nil

---@class SilverChainModue
---@field generate fun(props:GenerationProps)
---@field generate_watch fun(props:GenerationProps)

---@type SilverChainModue
public_lua_silverchain = public_lua_silverchain
