rm -rf dependencies
mkdir dependencies
curl -L https://github.com/OUIsolutions/Darwin/releases/download/0.013/darwin015.c -o darwin.c
gcc darwin.c -o darwin.o
curl -L https://github.com/OUIsolutions/LuaCEmbed/releases/download/v0.779/LuaCEmbed.h -o dependencies/LuaCEmbed.h


curl -L https://github.com/OUIsolutions/SilverChain/releases/download/v0.08/CSilverChainApiNoDependenciesIncluded.h -o  dependencies/CSilverChainApiNoDependenciesIncluded.h
curl -L https://github.com/OUIsolutions/CTextEngine/releases/download/v2.002/CTextEngine.h -o dependencies/CTextEngine.h
curl -L https://github.com/OUIsolutions/DoTheWorld/releases/download/v7.005/doTheWorld.h -o dependencies/doTheWorld.h
curl -L https://github.com/OUIsolutions/C-Cli-Entry/releases/download/0.001/CliEntry.h -o  dependencies/CliEntry.h
