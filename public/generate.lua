public_lua_silverchain.generate = function(props)
    private_silver_chain.check_types(props.src, { "string" }, "props.src")
    private_silver_chain.check_types(props.import_dir, { "string", "nill" }, "props.import_dir")
    private_silver_chain.check_types(props.project_short_cut, { "string", "nill" }, "props.project_short_cut")
    private_silver_chain.check_types(props.tags, { "table" }, "props.tags")
    private_silver_chain.check_types(props.implement_main, { "boolean", "nill" }, "props.implement_main")
    private_silver_chain.check_types(props.main_file, { "string", "nill" }, "props.main_file")
    private_silver_chain.check_types(props.main_path, { "string", "nill" }, "props.main_path")

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

    local silver_chain_string_array = private_silverchain_cinterop.newStringArray()
    for i = 1, #props.tags do
        private_silverchain_cinterop.append_string_array(
            silver_chain_string_array,
            props.tags[i])
    end
    local implement_main = props.implement_main
    if implement_main == nil then
        implement_main = true
    end

    private_silverchain_cinterop.generate(
        props.src,
        import_dir,
        project_short_cut,
        silver_chain_string_array,
        implement_main,
        props.main_file,
        props.main_path
    )
    private_silverchain_cinterop.free_string_array(silver_chain_string_array)
end
