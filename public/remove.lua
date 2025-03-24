
public_lua_silverchain.remove = function(src)
    if not src then
        error("src is required")
    end
    private_silverchain_cinterop.remove_source(src)
end