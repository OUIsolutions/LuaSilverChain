
public_lua_silverchain.remove = function(src)
    if not src then
        error("src is required")
    end
    private_silver_chain.remove(src)
end