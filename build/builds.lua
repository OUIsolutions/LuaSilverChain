


function create_start_project()
    local project = darwin.create_project("lua_silverchain")
    project.add_lua_code("public_lua_silverchain = {}")
    project.add_lua_code("private_silver_chain = {}")
    local concat_path = true
    local src_files = dtw.list_files_recursively("public", concat_path)
    for i = 1, #src_files do
        local current = src_files[i]
        project.add_lua_code("-- file: " .. current .. "\n")
        project.add_lua_file(current)
    end

    return project
end 

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

