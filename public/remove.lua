
public_lua_silverchain.remove = function(src)
    if not src then
        error("src is required")
    end
    private_silverchain_cinterop.remove_source(src)
end
public_lua_silverchain.remove_from_content = function(content, src)
    if not content or not src then
        error("content and src are required")
    end
    private_silverchain_cinterop.remove_from_content(content, src)
end