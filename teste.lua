---@type SilverChainModue
silverchain = require("release/LuaSilverChain")

silverchain.generate({
    src = "luadoTheWorld",
    tags = { "consts", "dependency", "fdeclare", "fdefine", "macros" }
})
