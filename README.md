# 🌻 openFrameworks Templates 🌻

A collection of templates for openFrameworks' project generator. Designed to work primarily for [Visual Studio Code](https://code.visualstudio.com/) on Linux.

Also been working on adding Visual Studio 2019 templates for windows.

## Linux

### About Templates

#### oftBasic

A basic template for use in vscode on Linux. It includes auto formatting using clang-format and all necessary configuration to use intellisense in vscode.

![Screenshot of visual studio code with the basic openFrameworks project running.](screenshot-oftBasic.png)

#### oftArduinoUno

Expands on the basic template to and creates a project that has a arduino sketch and a openFrameworks sketch. Configured with a starter program that lights up the arduino's on board led when there's a mouse click in openFrameworks.

![Shows an image of an arduino plugged into a laptop with an openFrameworks sketch running and visual studio code in the background. The mouse is clicked and the led on the arduino toggles.](screenshot-oftArduinoUno.gif)

### Installation 🏗️

0. (optional) You may want to fork this repository and look through the templates and change the default name and folder path.

1. Add `export PG_OF_PATH=/path/to/openFrameworks` to `.profile` or `.bashrc` if you haven't already. *Doing this also means you can put the your project anywhere on your computer without worrying about projects being in the openFrameworks app directory, although if you every move a project to a different computer you may need to update the path.*

2. Install clang-format if not already installed. 

2. Define the following in Visual Studio Code settings (`Ctrl` + `,`). If using a more advanced template check below to see if there are other vscode settings needed.

>```json
>"openFrameworks.path": "/path/to/openFrameworks/", Must end with /
>```

3. Clone the repository, and run `install.sh`. *Please note this will duplicate the templates into `of/scripts/templates` so that they can be used but if you make any changes you'll have to replace the existing templates by running the install script again.*

### Usage ⚙️

1. Use Project Generator

>```bash
>projectGenerator -t"oftBasic" projectName
>projectGenerator -t"oftArduinoUno" projectName
>```

2. Open the project in vscode. Click the `Open Workspace` button in the bottom right corner if you didn't open the workspace directly.

3. Accept recommended vscode extensions in the bottom right corner if the pop up comes up.

4. See the project's `README.md` for more information on running the project.

5. Make something awesome! 🎨

### Other VSCode Settings 💫

### For oftArduinoUno

```json
"arduino.path": "/path/to/arduino/", Must end with /
"arduino.commandPath": "arduino",
"arduino.defaultBaudRate": 9600,
```

## Windows

### About Templates

#### oftBasicVS2019

A version of `oftBasic` designed for Visual Studio 2019 Community Edition.

### Installation

(these may not be right file an issue if you're having trouble)

0. You'll need to install [git bash]() if you haven't already.
1. Install Clang Tools: https://github.com/llvm/llvm-project/releases/tag/llvmorg-12.0.0
2. Install recommended extensions below.
3. Add `export PG_OF_PATH=\\path\\to\\openFrameworks` to `.profile` or `.bashrc` if you haven't already.
4. Run install.sh in git bash.

#### Suggested Extensions

I'm not as farmilar with automatically installing extensions in visual studio so here's links for the extensions I recommend.

- [Toggle Comments](https://marketplace.visualstudio.com/items?itemName=munyabe.ToggleComment) - Adds `ctrl + /` to comment out code. Why is this not a thing in Visual Studio? Who knows but it's super annoying.
- [Clang Power Tools](https://marketplace.visualstudio.com/items?itemName=caphyon.ClangPowerTools) - Includes clang format. A bit more setup is required but it's worth it.
- [Visual Studio Spell Checker VS2017 or Later](https://marketplace.visualstudio.com/items?itemName=EWoodruff.VisualStudioSpellCheckerVS2017andLater) - Because who doesn't need spell check?

### Usage

1. Launch Project Generator
2. Select `Advanced Options` under the gear icon.
![Screenshot of Project Generator with Advanced Options turned on.](./images/advanced-options-on.PNG)
3. Select the template under the `create/update` tab.
![Screenshot of Project Generator with oftBasicVS2019 template selected turned on.](./images/select-template.PNG)

## Contributing 💖

I'd be happy to accept templates that follow the same kind of structure. Also feel welcome to open an issue to discuss changes, possible features, and bugs.
