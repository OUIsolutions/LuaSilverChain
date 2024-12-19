---@type SilverChainModue
silverchain = require("release/LuaSilverChain")

silverchain.generate({
    src = "luadoTheWorld",
    project_short_cut = "testess",
    tags = { "consts", "dependency", "fdeclare", "fdefine", "macros" }
})
