local SILVER_CHAIN_CODE = "32342jjressd"
local SILVER_CHAIN_PATH = "dependencies/CSilverChainApiNoDependenciesIncluded.h"
dtw.remove_any("release")

function generate_full_c()
    private_darwin.resset_c()

    darwin.add_c_file("citerop.c", true)
    darwin.load_lualib_from_c(
        "luaopen_private_silverchain_cinterop",
        "private_silverchain_cinterop"
    )

    local full_clib = darwin.generate_c_lib_code({
        libname = "lua_silverchain",
        object_export = "public_lua_silverchain",
        include_e_luacembed = false
    })

    full_clib = full_clib:gsub(SILVER_CHAIN_CODE, "#include")
    dtw.write_file("release/silverchain_full.c", full_clib)
end
function generate_darwin_import()
    private_darwin.resset_c()
    darwin.add_c_file("citerop.c", true, function(import, path)
        if import == "dependencies/LuaCEmbed.h" then
            return false
        end
        return true
    end)
    darwin.load_lualib_from_c(
        "luaopen_private_silverchain_cinterop",
        "private_silverchain_cinterop"
    )

    local full_clib = darwin.generate_c_lib_code({
        libname = "lua_silverchain",
        object_export = "public_lua_silverchain",
        include_e_luacembed = false
    })

    full_clib = full_clib:gsub(SILVER_CHAIN_CODE, "#include")
    dtw.write_file("release/silverchain_darwin_import.c", full_clib)
end

function generate_darwin_no_dependencie_not_included()
    private_darwin.resset_c()

    darwin.add_c_file("citerop.c", true, function(import, path)
        if import == "dependencies/CSilverChainApiNoDependenciesIncluded.h" then
            return true
        end
        return false
    end)

    darwin.load_lualib_from_c(
        "luaopen_private_silverchain_cinterop",
        "private_silverchain_cinterop"
    )

    local full_clib = darwin.generate_c_lib_code({
        libname = "lua_silverchain",
        object_export = "public_lua_silverchain",
        include_e_luacembed = false
    })

    full_clib = full_clib:gsub(SILVER_CHAIN_CODE, "#include")
    dtw.write_file("release/silverchain_no_dependecie_included.c", full_clib)
end

darwin.add_lua_code("public_lua_silverchain = {}")
darwin.add_lua_code("private_silver_chain = {}")

local concat_path = true
local src_files = dtw.list_files_recursively("public", concat_path)
for i = 1, #src_files do
    local current = src_files[i]
    darwin.add_lua_code("-- file: " .. current .. "\n")
    darwin.add_lua_file(current)
end
darwin.generate_lua_output({ output_name = "debug.lua" })

--- we must format these , to avoid bugs on include
local camalgamator_content = dtw.load_file(SILVER_CHAIN_PATH)
camalgamator_content = camalgamator_content:gsub("#include", SILVER_CHAIN_CODE)
dtw.write_file(SILVER_CHAIN_PATH, camalgamator_content)

generate_full_c()
generate_darwin_import()
generate_darwin_no_dependencie_not_included()

dtw.copy_any_overwriting("types/luaSilverCHain_types.lua", "LuaSilverChain/types.lua")
dtw.copy_any_overwriting("init.lua", "LuaSilverChain/init.lua")

os.execute("gcc -shared -fpic release/silverchain_full.c -o LuaSilverChain/silverchain.so")
os.execute("zip -r  release/LuaSilverChain.zip LuaSilverChain")
