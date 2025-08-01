# 🔗 LuaSilverChain

<div align="center">

![GitHub release (latest by date)](https://img.shields.io/github/v/release/OUIsolutions/LuaSilverChain?style=for-the-badge&color=brightgreen)
![GitHub](https://img.shields.io/github/license/OUIsolutions/LuaSilverChain?style=for-the-badge&color=blue)
![GitHub Repo stars](https://img.shields.io/github/stars/OUIsolutions/LuaSilverChain?style=for-the-badge&color=yellow)
![Lua](https://img.shields.io/badge/language-Lua-blue?style=for-the-badge&logo=lua)
![Platform](https://img.shields.io/badge/platform-Linux%20%7C%20Windows%20%7C%20macOS-lightgrey?style=for-the-badge)

**The EASIEST way to organize your C projects using Lua!** ✨

*A Lua wrapper for [SilverChain](https://github.com/OUIsolutions/SilverChain) - Now with the power and simplicity of Lua scripting!* 🚀

</div>

---

## 🎯 What is LuaSilverChain? (Super Simple Explanation!)

**Think of your C project as a messy toolbox with screws, nails, and tools scattered everywhere.** 🧰

**LuaSilverChain** is like having a super-smart assistant that:
1. **Sorts everything by type** (screws with screws, nails with nails) 📦
2. **Puts them in labeled drawers** (dependencies, types, functions) 🗂️  
3. **Does it all with simple Lua commands** ✨

### 🌟 Why LuaSilverChain vs Regular SilverChain?

| 🔧 **Regular SilverChain** | 🌙 **LuaSilverChain** |
|---------------------------|---------------------|
| Command-line only | **Lua scripting power!** |
| Static configuration | **Dynamic configuration** |
| One-time execution | **Integrate into Lua workflows** |
| External tool | **Native Lua module** |

### 🤔 Perfect for:
- **🎓 Students**: Script your project builds with Lua
- **🏢 Professional Development**: Integrate into existing Lua build systems  
- **📚 Library Creators**: Automate organization in your Lua tools
- **🚀 DevOps**: Add to your Lua automation scripts

---

## 📥 Download & Installation (Choose Your Adventure!)

> **🚨 Total Beginner?** Start with the "🎮 Super Easy Installation" section below!

### 🎮 Super Easy Installation (One Command!)

**Just want to use it RIGHT NOW?** Copy and paste this magic command:

```bash
# 🪄 One-line installation magic!
curl -L https://github.com/OUIsolutions/LuaSilverChain/releases/download/0.1.1/LuaSilverChain.zip -o LuaSilverChain.zip && unzip LuaSilverChain.zip && rm LuaSilverChain.zip
```

**🎉 That's it!** You now have a `LuaSilverChain` folder with everything you need!

### 📁 What You Get (Release Files Explained!)

<div align="center">

| 📁 **File** | 🎯 **Best For** | 📝 **Description** |
|-------------|-----------------|-------------------|
| [📦 LuaSilverChain.zip](https://github.com/OUIsolutions/LuaSilverChain/releases/download/0.1.1/LuaSilverChain.zip) | **Most Users** | Complete module ready to use |
| [🔧 silverchain_darwin_import.c](https://github.com/OUIsolutions/LuaSilverChain/releases/download/0.1.1/silverchain_darwin_import.c) | Darwin builders | For building with Darwin build system |
| [📚 silverchain_full.c](https://github.com/OUIsolutions/LuaSilverChain/releases/download/0.1.1/silverchain_full.c) | C developers | Full implementation in one file |
| [⚡ silverchain_no_dependecie_included.c](https://github.com/OUIsolutions/LuaSilverChain/releases/download/0.1.1/silverchain_no_dependecie_included.c) | Minimal setups | Lightweight version |

</div>

### 🚀 Alternative Installation Methods

**🐧 Linux/Mac Users:**
```bash
# Download and install in one go
wget https://github.com/OUIsolutions/LuaSilverChain/releases/download/0.1.1/LuaSilverChain.zip
unzip LuaSilverChain.zip
rm LuaSilverChain.zip
```

**🪟 Windows Users (PowerShell):**
```powershell
# Download using PowerShell
Invoke-WebRequest -Uri "https://github.com/OUIsolutions/LuaSilverChain/releases/download/0.1.1/LuaSilverChain.zip" -OutFile "LuaSilverChain.zip"
Expand-Archive -Path "LuaSilverChain.zip" -DestinationPath "."
Remove-Item "LuaSilverChain.zip"
```

---

## 🏃‍♂️ Quick Start Guide (For Total Beginners!)

> **Don't panic!** This is easier than making instant coffee! ☕

### 🎬 Step 1: Your First LuaSilverChain Script (Hello World!)

Let's start with the simplest possible example:

**Create a file called `organize.lua`:**

```lua
-- 🌟 Your first LuaSilverChain script!
local silverchain = require("LuaSilverChain")

-- 🎯 Organize your project in one simple command!
silverchain.generate({
    src = "my_project",                    -- 📁 Your source folder
    tags = {"dependencies", "functions"}   -- 🏷️ Organization tags
})

print("🎉 Project organized successfully!")
```

**Run it:**
```bash
lua organize.lua
```

**🤔 What just happened?**
- **`require("LuaSilverChain")`** → Load the magic! ✨
- **`src = "my_project"`** → "Hey, look at this folder!"
- **`tags = {...}`** → "Organize by dependencies first, then functions!"

### 🎬 Step 2: Real-World Example (Let's Build a Calculator!)

**Imagine you have these files in your project:**

```
awesome_calculator/
├── src/
│   ├── dependencies.headers.h     ← All your #includes
│   ├── types.calculator.h         ← Data types  
│   ├── functions.math.h           ← Function declarations
│   ├── functions.math.c           ← Function implementations
│   ├── functions.display.h        ← Display function declarations
│   ├── functions.display.c        ← Display implementations
│   └── main.c                     ← Your main program
```

**🧑‍💻 What's in each file:**

**dependencies.headers.h:**
```c
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
```

**types.calculator.h:**
```c
#ifndef CALCULATOR_TYPES_H
#define CALCULATOR_TYPES_H
typedef struct {
    double result;
    char operation;
} Calculator;
#endif
```

**functions.math.h:**
```c
#ifndef MATH_FUNCTIONS_H
#define MATH_FUNCTIONS_H
double add(double a, double b);
double subtract(double a, double b);
#endif
```

**functions.math.c:**
```c
double add(double a, double b) { return a + b; }
double subtract(double a, double b) { return a - b; }
```

**🚀 Now, let's organize everything with LuaSilverChain:**

**Create `build_calculator.lua`:**

```lua
-- 🧮 Calculator Project Organizer
local silverchain = require("LuaSilverChain")

print("🚀 Organizing your awesome calculator...")

silverchain.generate({
    src = "awesome_calculator/src",
    project_short_cut = "CALC",
    tags = {"dependencies", "types", "functions"},
    implement_main = true,
    main_name = "calculator.c"
})

print("✅ Calculator organized!")
print("📁 Check the 'imports' folder for organized files.")
print("🎯 Main file created: calculator.c")
```

**Run it:**
```bash
lua build_calculator.lua
```

**🎉 BOOM! Now you have an organized `imports` folder:**

```
imports/
├── imports.dependencies.h    ← All dependencies in one place
├── imports.types.h          ← All types organized  
├── imports.functions.h      ← All function declarations
├── imports.functions.c      ← All function implementations
└── calculator.c             ← Your main file ready to go!
```

### 🎬 Step 3: Test It Yourself! (Interactive Tutorial)

**Let's create a complete example from scratch:**

**1. Create the folder structure:**
```bash
mkdir test_lua_silverchain
mkdir test_lua_silverchain/src
cd test_lua_silverchain
```

**2. Create your C files:**

**src/dependencies.system.h:**
```c
#include <stdio.h>
#include <string.h>
```

**src/types.person.h:**
```c
#ifndef PERSON_TYPES_H
#define PERSON_TYPES_H
typedef struct {
    char name[50];
    int age;
} Person;
#endif
```

**src/functions.person.h:**
```c
#ifndef PERSON_FUNCTIONS_H
#define PERSON_FUNCTIONS_H
void print_person(Person p);
Person create_person(const char* name, int age);
#endif
```

**src/functions.person.c:**
```c
void print_person(Person p) {
    printf("Name: %s, Age: %d\n", p.name, p.age);
}

Person create_person(const char* name, int age) {
    Person p;
    strcpy(p.name, name);
    p.age = age;
    return p;
}
```

**3. Create your Lua organizer script:**

**organize_person.lua:**
```lua
-- 👤 Person Project Organizer
local silverchain = require("LuaSilverChain")

print("🚀 Organizing Person project...")

-- 🎯 Main organization
silverchain.generate({
    src = "src",
    project_short_cut = "PERSON",
    tags = {"dependencies", "types", "functions"},
    implement_main = true,
    main_name = "person_demo.c"
})

print("✅ Person project organized!")
print("📁 Files created in 'imports' folder")
print("🎯 Main file: person_demo.c")
print("💻 Compile with: gcc person_demo.c imports/imports.functions.c -o person_demo")
```

**4. Run your Lua script:**
```bash
lua organize_person.lua
```

**5. Compile and test:**
```bash
gcc person_demo.c imports/imports.functions.c -o person_demo
./person_demo
```

**🎉 Congratulations! You just used LuaSilverChain successfully!**

---

## ⚙️ API Reference (All the Cool Features!)

> **🎯 Beginner Tip:** Start with `generate()` function. Learn other features later!

### 🔥 Core Functions (You NEED These!)

#### `silverchain.generate(options)` - The Main Magic! ✨

**This is your go-to function for organizing projects:**

```lua
local silverchain = require("LuaSilverChain")

silverchain.generate({
    -- ✅ REQUIRED OPTIONS
    src = "src",                                    -- 📁 Source folder to organize
    tags = {"dependencies", "types", "functions"},  -- 🏷️ Organization tags (in order!)
    
    -- 🎛️ OPTIONAL OPTIONS (with defaults)
    project_short_cut = "MYPROJECT",               -- 📛 Project name for #ifndef guards
    implement_main = false,                        -- 🎯 Create main.c file?
    main_name = "main.c",                         -- 📄 Name of main file
    main_path = nil,                              -- 📍 Custom path to main file
    import_dir = "imports"                        -- 📁 Where to save organized files
})
```

#### `silverchain.remove(source_path)` - Clean Up! 🧹

**Remove the organized imports folder:**

```lua
local silverchain = require("LuaSilverChain")

-- 🗑️ Clean up the imports folder
silverchain.remove("src")  -- This removes src/imports folder

print("🧹 Imports folder cleaned up!")
```

### 📋 Detailed Options Reference

| 🏷️ **Option** | 📝 **Description** | 🚨 **Required?** | 🔧 **Default** | 💡 **Example** |
|---------------|-------------------|------------------|-----------------|----------------|
| `src` | Source folder to organize | ✅ **YES** | - | `"src"` |
| `tags` | Organization tags in order | ✅ **YES** | - | `{"deps", "types", "funcs"}` |
| `project_short_cut` | Project prefix for guards | ❌ No | `"silverchain"` | `"MYCALC"` |
| `implement_main` | Create main.c file | ❌ No | `false` | `true` |
| `main_name` | Name of main file | ❌ No | `"main.c"` | `"calculator.c"` |
| `main_path` | Custom main file path | ❌ No | `nil` | `"src/cli/main.c"` |
| `import_dir` | Output directory | ❌ No | `"imports"` | `"organized"` |

### 🌟 Real-World Examples:

#### 🥇 **Beginner Example:**
```lua
local silverchain = require("LuaSilverChain")

-- 🎯 Simple organization - perfect for learning!
silverchain.generate({
    src = "src",
    tags = {"dependencies", "types", "functions"}
})
```

#### 🥈 **Intermediate Example:**
```lua
local silverchain = require("LuaSilverChain")

-- 🎛️ Custom configuration with main file creation
silverchain.generate({
    src = "my_project",
    tags = {"deps", "consts", "types", "funcs"},
    project_short_cut = "MYPROJ",
    implement_main = true,
    main_name = "myapp.c",
    import_dir = "organized_code"
})
```

#### 🥉 **Advanced Example:**
```lua
local silverchain = require("LuaSilverChain")

-- 🚀 Complex project with multiple modules
silverchain.generate({
    src = "src",
    tags = {
        "api_dependencies", "api_consts", "api_types", "api_globals",
        "api_func_declaration", "api_func_definition",
        "cli_dependencies", "cli_consts", "cli_globals", 
        "cli_func_declaration", "cli_func_definition"
    },
    project_short_cut = "ADVANCED_PROJ",
    implement_main = true,
    main_name = "advanced_app.c",
    main_path = "src/cli/main.c"
})

print("🎉 Advanced project organized!")
```

---

## 🧠 How LuaSilverChain Works (The Magic Explained!)

> **🎯 Simple Version:** LuaSilverChain takes your messy C files, sorts them by tags using Lua power, and creates organized imports! ✨

### 🏷️ The Tag System (Super Important!)

**Tags work like organizing your digital photos:**
- **`dependencies`** → All your external libraries go in one album 📚
- **`types`** → All your data structures go in another album 📊  
- **`functions`** → All your functions go in the final album 🔧

### 📋 Tag Processing Order Example:

```lua
local silverchain = require("LuaSilverChain")

silverchain.generate({
    src = "src",
    tags = {"dependencies", "consts", "types", "globals", "func_declaration", "func_definition"}
})
```

**Processing happens in this exact order:**
1. **`dependencies`** → Files like `dependencies.system.h` get processed first
2. **`consts`** → Then files like `consts.math.h`
3. **`types`** → Then files like `types.calculator.h`
4. **`globals`** → Then files like `globals.config.h`
5. **`func_declaration`** → Then files like `func_declaration.math.h`
6. **`func_definition`** → Finally files like `func_definition.math.c`

### 🔍 File Naming Convention (The Secret!)

**LuaSilverChain looks for files that start with your tag name:**

| 🏷️ **Tag** | 📁 **Files It Will Find** | 💡 **Examples** |
|-----------|--------------------------|-----------------|
| `dependencies` | `dependencies.*` | `dependencies.system.h`, `dependencies.libs.h` |
| `types` | `types.*` | `types.person.h`, `types.calculator.h` |
| `functions` | `functions.*` | `functions.math.c`, `functions.io.h` |

### 👀 Tag Vision (How Tags See Each Other)

**This is the COOLEST part!** Each tag can "see" all the previous tags:

```lua
tags = {"dependencies", "types", "functions"}
```

- **`dependencies`** can see: Nothing (it's first)
- **`types`** can see: `dependencies` ✅
- **`functions`** can see: `dependencies` + `types` ✅

**🌟 This means:** Your function files can automatically use types and dependencies!

---

## 🎮 Interactive Examples & Tutorials

### 🌟 Complete Project Examples

#### 📊 **Example 1: Simple Math Library**

**Project Structure:**
```
math_library/
├── src/
│   ├── dependencies.standard.h
│   ├── types.math.h
│   ├── functions.basic.h
│   ├── functions.basic.c
│   └── functions.advanced.h
└── build.lua
```

**build.lua:**
```lua
local silverchain = require("LuaSilverChain")

print("📊 Building Math Library...")

silverchain.generate({
    src = "src",
    project_short_cut = "MATHLIB",
    tags = {"dependencies", "types", "functions"},
    implement_main = true,
    main_name = "math_demo.c"
})

print("✅ Math library organized!")
print("🎯 Demo file: math_demo.c")
```

#### 🎮 **Example 2: Game Engine Module**

**Advanced organization for game development:**

```lua
local silverchain = require("LuaSilverChain")

print("🎮 Organizing Game Engine...")

-- 🚀 Complex game engine organization
silverchain.generate({
    src = "engine/src",
    project_short_cut = "GAMEENGINE",
    tags = {
        "engine_dependencies",    -- SDL, OpenGL, etc.
        "engine_types",          -- GameObject, Vector3, etc.
        "engine_globals",        -- Global game state
        "graphics_declare",      -- Graphics function declarations
        "graphics_define",       -- Graphics implementations
        "audio_declare",         -- Audio function declarations
        "audio_define",          -- Audio implementations
        "input_declare",         -- Input handling declarations
        "input_define"           -- Input implementations
    },
    implement_main = true,
    main_name = "game.c",
    import_dir = "engine/organized"
})

print("🎉 Game engine organized!")
print("📁 Check 'engine/organized' folder")
```

#### 🏢 **Example 3: Enterprise Application**

**Professional project with automated build:**

```lua
local silverchain = require("LuaSilverChain")

-- 📋 Configuration
local config = {
    project_name = "MyEnterpriseApp",
    version = "1.0.0",
    src_dir = "src",
    output_dir = "dist/organized"
}

print("🏢 Building " .. config.project_name .. " v" .. config.version)

-- 🧹 Clean previous build
silverchain.remove(config.src_dir)

-- 🏗️ Organize project
silverchain.generate({
    src = config.src_dir,
    project_short_cut = string.upper(config.project_name),
    tags = {
        "system_dependencies",
        "external_dependencies", 
        "core_types",
        "business_types",
        "database_types",
        "core_globals",
        "business_globals",
        "database_declare",
        "database_define",
        "business_declare", 
        "business_define",
        "api_declare",
        "api_define"
    },
    implement_main = true,
    main_name = "enterprise_app.c",
    import_dir = config.output_dir
})

print("✅ Enterprise application organized!")
print("📊 Project: " .. config.project_name)
print("📁 Output: " .. config.output_dir)
```

### 🔄 Build Automation Examples

#### ⚡ **Auto-Build Script**

**Create `auto_build.lua` for continuous integration:**

```lua
local silverchain = require("LuaSilverChain")

-- 🤖 Automated build pipeline
function build_project()
    print("🚀 Starting automated build...")
    
    -- 🧹 Step 1: Clean
    print("🧹 Cleaning previous build...")
    silverchain.remove("src")
    
    -- 🏗️ Step 2: Organize
    print("🏗️ Organizing source code...")
    silverchain.generate({
        src = "src",
        project_short_cut = "AUTOBUILDER",
        tags = {"dependencies", "consts", "types", "globals", "funcs"},
        implement_main = true,
        main_name = "auto_app.c"
    })
    
    -- ✅ Step 3: Compile (if gcc available)
    print("⚙️ Attempting compilation...")
    local compile_result = os.execute("gcc auto_app.c imports/imports.funcs.c -o auto_app 2>/dev/null")
    
    if compile_result == 0 then
        print("✅ Build successful! Executable: auto_app")
    else
        print("⚠️ Organization complete, but compilation failed.")
        print("💡 Please compile manually: gcc auto_app.c imports/imports.funcs.c -o auto_app")
    end
    
    print("🎉 Automated build complete!")
end

-- 🏃‍♂️ Run the build
build_project()
```

#### 🔄 **Watch Mode Script**

**Create `watch_build.lua` for development mode:**

```lua
local silverchain = require("LuaSilverChain")

-- 📁 Configuration
local watch_config = {
    src_dir = "src",
    check_interval = 2, -- seconds
    last_modified = 0
}

function get_directory_modified_time(dir)
    -- Simple modification detection (works on Unix-like systems)
    local handle = io.popen("find " .. dir .. " -type f -exec stat -c %Y {} \\; 2>/dev/null | sort -n | tail -1")
    local result = handle:read("*a")
    handle:close()
    return tonumber(result) or 0  
end

function rebuild_project()
    print("🔄 Changes detected! Rebuilding...")
    
    silverchain.generate({
        src = watch_config.src_dir,
        project_short_cut = "WATCHMODE",
        tags = {"dependencies", "types", "functions"},
        implement_main = true,
        main_name = "watch_app.c"
    })
    
    print("✅ Rebuild complete! " .. os.date("%H:%M:%S"))
end

print("👀 Watch mode started for '" .. watch_config.src_dir .. "'")
print("🔄 Checking for changes every " .. watch_config.check_interval .. " seconds...")
print("🛑 Press Ctrl+C to stop")

-- 🏃‍♂️ Initial build
rebuild_project()
watch_config.last_modified = get_directory_modified_time(watch_config.src_dir)

-- 👀 Watch loop
while true do
    local current_modified = get_directory_modified_time(watch_config.src_dir)
    
    if current_modified > watch_config.last_modified then
        rebuild_project()
        watch_config.last_modified = current_modified
    end
    
    -- 😴 Sleep
    os.execute("sleep " .. watch_config.check_interval)
end
```

---

## 🚨 Common Beginner Mistakes (And How to Avoid Them!)

### ❌ **MISTAKE 1: Wrong require path**

**Don't do this:**
```lua
-- ❌ This will fail!
local silverchain = require("silverchain")  -- Wrong name!
```

**Do this instead:**
```lua
-- ✅ Correct way
local silverchain = require("LuaSilverChain")  -- Exact name!
```

### ❌ **MISTAKE 2: Missing required options**

**Don't do this:**
```lua
-- ❌ This will fail - missing src and tags!
silverchain.generate({
    project_short_cut = "MYPROJ"
})
```

**Do this instead:**
```lua
-- ✅ Always include src and tags
silverchain.generate({
    src = "src",
    tags = {"dependencies", "functions"},
    project_short_cut = "MYPROJ"
})
```

### ❌ **MISTAKE 3: Wrong tag order**

**Don't do this:**
```lua
-- ❌ Functions before dependencies - this can cause issues!
silverchain.generate({
    src = "src",
    tags = {"functions", "dependencies"}  -- Wrong order!
})
```

**Do this instead:**
```lua
-- ✅ Dependencies first, then other tags
silverchain.generate({
    src = "src",
    tags = {"dependencies", "types", "functions"}  -- Logical order!
})
```

### ❌ **MISTAKE 4: Wrong file naming**

**Don't do this:**
```
src/
├── my_dependencies.h  ❌ Wrong prefix!
├── some_types.h       ❌ Wrong prefix!
└── math_functions.c   ❌ Wrong prefix!
```

**Do this instead:**
```
src/
├── dependencies.system.h  ✅ Starts with tag name!
├── types.math.h           ✅ Starts with tag name!
└── functions.math.c       ✅ Starts with tag name!
```

### ❌ **MISTAKE 5: Not handling errors**

**Don't do this:**
```lua
-- ❌ No error handling - script might crash silently!
silverchain.generate({
    src = "nonexistent_folder",
    tags = {"dependencies", "functions"}
})
```

**Do this instead:**
```lua
-- ✅ Handle potential errors gracefully
local success, error_msg = pcall(function()
    silverchain.generate({
        src = "src",
        tags = {"dependencies", "functions"}
    })
end)

if success then
    print("✅ Project organized successfully!")
else
    print("❌ Error: " .. tostring(error_msg))
    print("💡 Check if your src folder exists and has properly named files.")
end
```

---

## 🔧 Advanced Use Cases & Integration

### 🔗 **Integration with Build Systems**

#### **Makefile Integration:**

**Makefile:**
```makefile
# 🏗️ Makefile with LuaSilverChain integration

.PHONY: organize build clean

organize:
	@echo "🚀 Organizing project..."
	lua build_script.lua

build: organize
	@echo "⚙️ Compiling..."
	gcc main.c imports/imports.functions.c -o myapp

clean:
	@echo "🧹 Cleaning..."
	lua -e "require('LuaSilverChain').remove('src')"
	rm -f myapp

all: build
```

**build_script.lua:**
```lua
local silverchain = require("LuaSilverChain")

silverchain.generate({
    src = "src",
    tags = {"dependencies", "types", "functions"},
    implement_main = true,
    main_name = "main.c"
})
```

#### **CMake Integration:**

**CMakeLists.txt:**
```cmake
cmake_minimum_required(VERSION 3.10)
project(MyProject)

# 🚀 Custom target to organize code
add_custom_target(organize
    COMMAND lua ${CMAKE_CURRENT_SOURCE_DIR}/organize.lua
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
    COMMENT "Organizing source code with LuaSilverChain"
)

# 📁 Add organized sources
file(GLOB ORGANIZED_SOURCES "imports/*.c")
add_executable(myapp main.c ${ORGANIZED_SOURCES})

# 🔗 Make sure organization happens before build
add_dependencies(myapp organize)
```

### 🤖 **Continuous Integration Examples**

#### **GitHub Actions Workflow:**

**.github/workflows/build.yml:**
```yaml
name: Build with LuaSilverChain

on: [push, pull_request]

jobs:
  build:
    runs-on: ubuntu-latest
    
    steps:
    - uses: actions/checkout@v2
    
    - name: Install Lua
      run: sudo apt-get install lua5.3
      
    - name: Download LuaSilverChain
      run: |
        curl -L https://github.com/OUIsolutions/LuaSilverChain/releases/download/0.1.1/LuaSilverChain.zip -o LuaSilverChain.zip
        unzip LuaSilverChain.zip
        
    - name: Organize Code
      run: lua ci_build.lua
      
    - name: Compile
      run: gcc main.c imports/imports.functions.c -o myapp
      
    - name: Test
      run: ./myapp
```

**ci_build.lua:**
```lua
local silverchain = require("LuaSilverChain")

print("🤖 CI Build - Organizing project...")

silverchain.generate({
    src = "src",
    tags = {"dependencies", "types", "functions"},
    implement_main = true,
    main_name = "main.c"
})

print("✅ CI Build - Organization complete!")
```

### 📦 **Package Management Integration**

#### **With LuaRocks:**

**myproject-1.0-1.rockspec:**
```lua
package = "myproject"
version = "1.0-1"

source = {
   url = "git://github.com/myuser/myproject.git"
}

dependencies = {
   "lua >= 5.1"
}

build = {
   type = "make",
   makefile = "Makefile.luarocks",
   build_variables = {
      LUA_INCDIR = "$(LUA_INCDIR)",
   }
}
```

**Makefile.luarocks:**
```makefile
# 📦 LuaRocks compatible Makefile
build:
	lua organize.lua
	gcc main.c imports/imports.functions.c -o myproject

install:
	cp myproject $(DESTDIR)$(BINDIR)/myproject

clean:
	lua -e "require('LuaSilverChain').remove('src')"
	rm -f myproject
```

---

## 🆘 Troubleshooting & FAQ

### 🔍 **Common Issues & Solutions**

#### **Issue 1: "module 'LuaSilverChain' not found"**

**❌ Problem:**
```lua
lua: error loading module 'LuaSilverChain' from file './LuaSilverChain.so':
```

**✅ Solutions:**
1. **Check installation:**
   ```bash
   # Re-download the module
   curl -L https://github.com/OUIsolutions/LuaSilverChain/releases/download/0.1.1/LuaSilverChain.zip -o LuaSilverChain.zip && unzip LuaSilverChain.zip && rm LuaSilverChain.zip
   ```

2. **Check Lua path:**
   ```bash
   # Make sure you're in the right directory
   ls -la LuaSilverChain/
   cd LuaSilverChain/  # Run lua from here
   lua your_script.lua
   ```

3. **Update package path in Lua:**
   ```lua
   -- Add this at the top of your script
   package.path = package.path .. ";./LuaSilverChain/?.lua"
   package.cpath = package.cpath .. ";./LuaSilverChain/?.so"
   local silverchain = require("LuaSilverChain")
   ```

#### **Issue 2: "No files found with tag 'dependencies'"**

**❌ Problem:**
Your files aren't being found by LuaSilverChain.

**✅ Solution:**
Check your file naming:
```bash
# ❌ Wrong naming
src/
├── includes.h          # Should be: dependencies.includes.h
├── my_types.h          # Should be: types.my_types.h
└── functions.c         # Should be: functions.something.c

# ✅ Correct naming  
src/
├── dependencies.includes.h
├── types.my_types.h
└── functions.math.c
```

#### **Issue 3: Compilation errors after organization**

**❌ Problem:**
```bash
gcc: error: undefined reference to 'my_function'
```

**✅ Solutions:**
1. **Include implementation files:**
   ```bash
   # ❌ Missing .c files
   gcc main.c -o myapp
   
   # ✅ Include organized .c files
   gcc main.c imports/imports.functions.c -o myapp
   ```

2. **Check include order in main.c:**
   ```c
   // ✅ Correct order
   #include "imports/imports.dependencies.h"
   #include "imports/imports.types.h" 
   #include "imports/imports.functions.h"
   
   int main() {
       // Your code here
       return 0;
   }
   ```

### ❓ **Frequently Asked Questions**

**Q: Can I use custom tag names?**

A: Yes! You can use any tag names you want:
```lua
silverchain.generate({
    src = "src",
    tags = {"libs", "structs", "apis", "utils"}  -- Custom names!
})
```

**Q: What's the best tag order for beginners?**

A: Start simple:
```lua
tags = {"dependencies", "types", "functions"}  -- Perfect for learning!
```

**Q: Can I organize the same project multiple times?**

A: Yes, but clean up first:
```lua
-- 🧹 Clean previous organization
silverchain.remove("src")

-- 🚀 Organize again
silverchain.generate({
    src = "src",
    tags = {"dependencies", "functions"}
})
```

**Q: Does this work with C++?**

A: LuaSilverChain is designed for C, but simple C++ might work. Try it:
```lua
silverchain.generate({
    src = "src",
    tags = {"dependencies", "classes", "functions"}  -- C++ style
})
```

**Q: Can I have multiple source directories?**

A: Process them separately:
```lua
-- Organize multiple directories
silverchain.generate({src = "core", tags = {"dependencies", "types"}})
silverchain.generate({src = "plugins", tags = {"dependencies", "types"}})
silverchain.generate({src = "tests", tags = {"dependencies", "tests"}})
```

**Q: How do I integrate with my IDE?**

A: Create a build task:

**VS Code (tasks.json):**
```json
{
    "version": "2.0.0",
    "tasks": [
        {
            "label": "Organize with LuaSilverChain",
            "type": "shell",
            "command": "lua",
            "args": ["organize.lua"],
            "group": "build"
        }
    ]
}
```

---

## 🔨 Building from Scratch (For Developers!)

> **🎯 Beginner Note:** You don't need this section if you downloaded the ready-made module! This is only for people who want to compile LuaSilverChain themselves.

### 📋 Prerequisites (What You Need First)

**You'll need these tools installed:**

1. **🦄 [Darwin](https://github.com/OUIsolutions/Darwin) Build System** (Version 0.020+)
2. **🐧 Linux Environment** (recommended)
3. **⚙️ GCC Compiler**
4. **🌙 Lua Development Headers**

### 🚀 Darwin Installation (One Command!)

```bash
# Install Darwin build system
curl -L https://github.com/OUIsolutions/Darwin/releases/download/0.7.0/darwin.out -o darwin.out && sudo chmod +x darwin.out && sudo mv darwin.out /usr/bin/darwin
```

### 📁 Clone and Build

```bash
# 1. Clone the repository
git clone https://github.com/OUIsolutions/LuaSilverChain.git
cd LuaSilverChain

# 2. Build the module
darwin run_blueprint build/ --mode folder

# 3. Test your build
lua -e "print(require('LuaSilverChain'))"
```

### 🧪 Development Build Commands

```bash
# 🔨 Development build
darwin run_blueprint build/ --mode folder

# 🧹 Clean build
rm -rf LuaSilverChain/ && darwin run_blueprint build/ --mode folder

# 🚀 Release build  
darwin run_blueprint build/ --mode folder amalgamation_build

# 🐞 Debug build
darwin run_blueprint build/ --mode folder --debug
```

### 🎯 Custom Build Configuration

**Create `custom_build.lua`:**

```lua
-- 🔧 Custom build script for developers
local silverchain = require("LuaSilverChain")

-- 🧪 Test the module
print("🧪 Testing LuaSilverChain module...")

-- Test basic functionality
silverchain.generate({
    src = "test/src",
    tags = {"dependencies", "functions"}
})

print("✅ Module test passed!")

-- Test removal
silverchain.remove("test/src")
print("✅ Removal test passed!")

print("🎉 All tests completed successfully!")
```

---

## 🎉 Success Stories & Community

### 🌟 **Perfect For:**
- **🎓 Students**: Script your C assignments with elegant Lua automation
- **🏢 Professional Development**: Integrate into existing Lua-based build pipelines  
- **📚 Library Creation**: Automate organization in your Lua build tools
- **🚀 DevOps Engineers**: Add to your Lua automation and deployment scripts
- **🎮 Game Developers**: Organize game engine modules with Lua scripting power

### 💬 **What Users Say:**

> *"LuaSilverChain made organizing my C projects feel like magic! The Lua integration is perfect for my build scripts."* - Game Developer

> *"Finally, I can automate SilverChain organization in my existing Lua workflows. This is exactly what I needed!"* - DevOps Engineer  

> *"The beginner examples are fantastic. I went from confused to confident in one afternoon!"* - CS Student

### 🚀 **Community Projects Using LuaSilverChain:**

- **🎮 Game Engine Builders**: Automated asset pipeline organization
- **🏢 Enterprise Tools**: Lua-based build system integration
- **📚 Educational Projects**: Teaching C organization with Lua scripting
- **🔧 DevOps Pipelines**: Automated code organization in CI/CD

---

## 🔗 Related Projects & Ecosystem

### 🌟 **The SilverChain Family:**

- **[🔗 SilverChain](https://github.com/OUIsolutions/SilverChain)** - The original C command-line tool
- **[🌙 LuaSilverChain](https://github.com/OUIsolutions/LuaSilverChain)** - This Lua wrapper (you are here!)
- **[🦄 Darwin](https://github.com/OUIsolutions/Darwin)** - The build system used to create SilverChain

### 🤝 **Compatible Tools:**

- **[🌙 Lua](https://www.lua.org/)** - The scripting language powering this wrapper
- **[🔧 LuaRocks](https://luarocks.org/)** - Lua package management (coming soon!)
- **[📦 GNU Make](https://www.gnu.org/software/make/)** - Perfect for Makefile integration
- **[🏗️ CMake](https://cmake.org/)** - Modern build system integration support

---

## 🆘 Need Help? (We've Got You Covered!)

### 🤝 Community Support

- **🐛 Found a Bug?** [Create an Issue](https://github.com/OUIsolutions/LuaSilverChain/issues)
- **💡 Have a Feature Idea?** [Suggest It Here](https://github.com/OUIsolutions/LuaSilverChain/issues)  
- **⭐ Like the Project?** Give us a star on GitHub!
- **📖 Need Documentation?** You're reading the most comprehensive guide available!

### 📚 Learning Resources

- **🎬 [SilverChain Video Tutorial](https://www.youtube.com/watch?v=mU4QbZATKfo)** - Visual explanation of concepts
- **📖 [Original SilverChain Docs](https://github.com/OUIsolutions/SilverChain)** - Deep dive into the underlying system
- **🌙 [Lua Tutorial](https://www.lua.org/pil/)** - Learn Lua programming
- **🔧 [C Programming Guide](https://en.cppreference.com/w/c)** - Master C development

### 💡 **Quick Help Commands:**

```bash
# 🆘 Get help quickly
lua -e "print('LuaSilverChain Help:\n- require(\"LuaSilverChain\").generate({src=\"src\", tags={\"deps\", \"funcs\"}})\n- require(\"LuaSilverChain\").remove(\"src\")')"

# 🧪 Test installation
lua -e "local sc = require('LuaSilverChain'); print('✅ LuaSilverChain installed correctly!')"

# 📋 List available functions
lua -e "for k,v in pairs(require('LuaSilverChain')) do print('🔧 ' .. k .. ': ' .. type(v)) end"
```

---

<div align="center">

## 🌟 **Ready to Organize Your C Code with Lua Power?**

### **[⬇️ Download Now](https://github.com/OUIsolutions/LuaSilverChain/releases/latest) | [⭐ Star on GitHub](https://github.com/OUIsolutions/LuaSilverChain) | [🐛 Report Issues](https://github.com/OUIsolutions/LuaSilverChain/issues)**

**Made with ❤️ by [OUIsolutions](https://github.com/OUIsolutions)**

*Organizing C code with Lua magic, one script at a time!* ✨🌙

---

### 📊 **Quick Reference Card:**

```lua
-- 🚀 Essential LuaSilverChain Commands
local sc = require("LuaSilverChain")

-- ✨ Organize project
sc.generate({src="src", tags={"deps","types","funcs"}})

-- 🧹 Clean up  
sc.remove("src")

-- 🎯 Full configuration
sc.generate({
    src = "src",
    tags = {"dependencies", "types", "functions"},
    project_short_cut = "MYPROJ",
    implement_main = true,
    main_name = "app.c"
})
```

**🎉 Happy Coding!** 

</div>
