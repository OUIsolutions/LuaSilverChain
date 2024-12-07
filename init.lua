local info = debug.getinfo(1, "S")
local path = info.source:match("@(.*/)") or ""




local lib_path = ''

if os.getenv("HOME") then
    lib_path = path .. "silverchain.so"
else
    error("os not suported")
end


local load_lua_silver_chain = package.loadlib(lib_path, "luaopen_lua_silverchain")

---@type SilverChainModue
local lib = load_lua_silver_chain()

return lib
