r = require("release/LuaCAmalgamator")
code = r.generate_amalgamation_with_callback("cweb_studio/one.c", function(import, path)
    return "include-once"
end)
io.open("saida.c", "w"):write(code)
