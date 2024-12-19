public_lua_silverchain.generate = function(props)
    private_silver_chain.check_types(props, { "table" }, "props")

    private_silver_chain.check_types(props.src, { "string" }, "props.src")
    private_silver_chain.check_types(props.import_dir, { "string", "nil" }, "props.import_dir")
    private_silver_chain.check_types(props.project_short_cut, { "string", "nil" }, "props.project_short_cut")
    private_silver_chain.check_types(props.tags, { "table" }, "props.tags")
    private_silver_chain.check_types(props.implement_main, { "boolean", "nil" }, "props.implement_main")
    private_silver_chain.check_types(props.main_file, { "string", "nil" }, "props.main_file")
    private_silver_chain.check_types(props.main_path, { "string", "nil" }, "props.main_path")
    local import_dir = props.import_dir
    if not import_dir then
        import_dir = props.src .. "/imports"
    end

    local project_short_cut = props.project_short_cut
    if not project_short_cut then
        project_short_cut = "LuaSilverChain"
    end


    for i = 1, #props.tags do
        if type(props.tags[i]) ~= "string" then
            error("tag " .. i .. "not a string")
        end
    end
    if #props.tags == 0 then
        error("tags cannot be empty")
    end

    local silver_chain_string_array = private_silverchain_cinterop.newStringArray()
    for i = 1, #props.tags do
        local current = props.tags[i]
        private_silver_chain.check_types(current, { "string" }, "tags[" .. i .. "]")
        private_silverchain_cinterop.append_string_array(
            silver_chain_string_array,
            props.tags[i])
    end

    local implement_main = props.implement_main
    if implement_main == nil then
        implement_main = true
    end
    local error_obj = private_silverchain_cinterop.generate(
        props.src,
        import_dir,
        project_short_cut,
        silver_chain_string_array,
        implement_main,
        props.main_file,
        props.main_path
    )
    private_silverchain_cinterop.free_string_array(silver_chain_string_array)
    if error_obj ~= 0 then
        error_msg = private_silverchain_cinterop.get_error_msg(error_obj)
        private_silverchain_cinterop.free_error(error_obj)
        error(error_msg)
    end
end
