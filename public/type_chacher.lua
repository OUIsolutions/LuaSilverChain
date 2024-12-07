private_silver_chain.check_types = function(value, types, name)
    local type_value = type(value)
    for i = 1, #types do
        if types[i] == type_value then
            return
        end
    end
    if #types == 1 then
        error("arg " .. name .. " not '" .. types[1] .. "'")
    end
    error("arg " .. name .. " not in [" .. table.concat(types, ",") .. "]")
end
