# LuaSilverChain
a [SilverChain](https://github.com/OUIsolutions/SilverChain) Lua Wrapper

# Install

for installation just type
```shell 
curl -L https://github.com/OUIsolutions/LuaSilverChain/releases/download/0.0.3/LuaSilverChain.zip -o LuaSilverChain.zip && unzip LuaSilverChain.zip  && rm LuaSilverChain.zip 

```

# Usage
you can use the lib following these example 

```lua
---@type SilverChainModue
silverchain = require("LuaSilverChain")
silverchain.generate({
    src = "src",
    project_short_cut = "my_project_name",
    tags = { "dependencies", "consts",  "macros", "types" ,"globals", "fdeclare" ,"fdef" },
    implement_main=true,
    main_name="main.c"
})

```
