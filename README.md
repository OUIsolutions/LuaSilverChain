# LuaSilverChain
a [SilverChain](https://github.com/OUIsolutions/SilverChain) Lua Wrapper


# Release

| Item| What it is |
|-----|------------|
| [LuaSilverChain.zip](https://github.com/OUIsolutions/LuaSilverChain/releases/download/0.0.5/LuaSilverChain.zip)| Zip file with the LuaSilverChain module |
|[silverchain_darwin_import.c](https://github.com/OUIsolutions/LuaSilverChain/releases/download/0.0.5/silverchain_darwin_import.c) | C file to be used with Darwin to build the LuaSilverChain module |
|[silverchain_full.c](https://github.com/OUIsolutions/LuaSilverChain/releases/download/0.0.5/silverchain_full.c) | C file with the full implementation of the LuaSilverChain module |
|[silverchain_no_dependecie_included.c](https://github.com/OUIsolutions/LuaSilverChain/releases/download/0.0.5/silverchain_no_dependecie_included.c)| C file with the implementation of the LuaSilverChain module without the dependencies included |



# Install

for installation just type
```shell 
curl -L https://github.com/OUIsolutions/LuaSilverChain/releases/download/0.0.5/LuaSilverChain.zip -o LuaSilverChain.zip && unzip LuaSilverChain.zip  && rm LuaSilverChain.zip 

```

# Usage
you can use the lib following these example 

## Generation
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
## Remove 

```lua
silverchain = require("LuaSilverChain")
silverchain.remove("src")
```
## Building from Scratch
if you want to build the code from scracth  you need to have [Darwin](https://github.com/OUIsolutions/Darwin) 
installed on versio **0.020** and **Docker** our **Podman** installed on your machine.
After install all dependecies,clone the repo on your machine , than run:
```shel
darwin run_blueprint build/ --mode folder
```
