# LuaSilverChain
a [SilverChain](https://github.com/OUIsolutions/SilverChain) Lua Wrapper



# Install

for installation just type
```shell 
curl -L https://github.com/OUIsolutions/LuaSilverChain/releases/download/0.0.4/LuaSilverChain.zip -o LuaSilverChain.zip && unzip LuaSilverChain.zip  && rm LuaSilverChain.zip 

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

## Building from Scratch
if you want to build the code from scracth  you need to have [Darwin](https://github.com/OUIsolutions/Darwin) 
installed on versio **0.020** and **Docker** our **Podman** installed on your machine.
After install all dependecies,clone the repo on your machine , than run:
```shel
darwin run_blueprint build/ --mode folder
```
