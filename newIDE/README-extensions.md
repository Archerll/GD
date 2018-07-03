# Writing extensions for GDevelop 5

GDevelop editor and games engines are designed so that all objects, behaviors, actions, conditions and expressions
are provided by _extensions_. These extensions are composed of two parts:

- the _declaration_ of the extension, traditionally done in a file called `JsExtension.js`.
- the _implementation_ of the extension for the game engine (also the "Runtime"), containing the functions corresponding to the actions/conditons/expressions and the classes used for the objects or behaviors. The implementation is traditionally in files called `extensionnametools.js`, `objectnameruntimeobject.js` or `objectnameruntimebehavior.js`.

> Note that some GDevelop extensions are declared in C++, in files called `JsExtension.cpp`. If you want to edit them,
> refer to the paragraph about them at the end.

## Getting started

To modify extensions, you need to have the development version of GDevelop running. Make sure to have [Git](https://git-scm.com/) and [Node.js](https://nodejs.org) installed. [Yarn](https://yarnpkg.com) is optional.

```bash
git clone https://github.com/4ian/GD.git
cd GD/newIDE/app
npm install #or yarn
```

Refer to the [GDevelop IDE Readme](./README.md) for more information about the installation.

## Development

- First, run [GDevelop with Electron](https://github.com/4ian/GD/blob/master/newIDE/README.md#development-of-the-standalone-app).

  When GDevelop is started, the developer console should be opened. Search for the message `Loaded x JS extensions.` that indicates the loading of extensions.

- You can now open an extensions contained in the folder _Extensions_ at the root of the repository. For example, you can open [Extensions/FacebookInstantGames](https://github.com/4ian/GD/tree/master/Extensions/FacebookInstantGames). Edit the JsExtension.js file or a runtime file. After any change, you must import them in GDevelop:

  ```bash
  cd scripts
  node import-GDJS-Runtime.js #This copy extensions declaration and runtime into GDevelop.
  ```

- Finally, verify that the changes are applied:

  - If you modified the declaration (`JsExtension.js`), reload GDevelop by pressing Ctrl+R (or Cmd+R on macOS) in the developer console.
  - If you modified a Runtime file, relaunch a preview. Open the developer console if you want to check for any errors.

- You can now iterate and relaunch the script to develop the extension! 🚀

  > ⚠️ Always check the developer console after reloading GDevelop. If there is any error signaled, click on it to see what went wrong. You may have done a syntax error or mis-used an API.

### Documentation for declaring and writing extensions

- Check the [game engine online documentaiton here](http://4ian.github.io/GD-Documentation/GDJS%20Runtime%20Documentation/index.html). It's also a good idea to check the [Runtime folder of GDJS](../GDJS/README.md) to directly see how the game engine is done.

- The documentation for declaring extension is not yet written (**help is welcome**!). It's almost 100% equivalent to the way extensions are declared in C++ though, so take a look at [Extension.cpp documentation](http://4ian.github.io/GD-Documentation/GDCore%20Documentation/_about_extension_cpp.html) for now.

### Starting a new extension from scratch

If you want to start a new extension:

- Choose a unique and descriptive name. Create a folder with this name in _Extensions_.
- Create a file in it named _JsExtension.js_ and copy the content of the _JsExtension.js_ of another extension.
- Change the extension information (`extension.setExtensionInformation`). The first argument is the extension internal name and should be the same name as your folder for consistency.
- Remove all the actions/conditions/expressions declaration, run `node import-GDJS-Runtime.js` and reload GDevelop to verify that your extension is loaded.
- Create a file called for example _yourextensionnametools.js_ in the same directory.
- Add back the declarations in your extension. Use `setIncludeFile` when declaring your actions/conditions/expressions and set the name of the js file that you've created, prefixed by the path from the root folder. For example: 
  ```js
  .setIncludeFile("Extensions/FacebookInstantGames/facebookinstantgamestools.js")
  ```

## Current status and how to contribute

Declaring extensions in JavaScript is still new, and enhancements are possible to exploit the full potential of extensions:

- [ ] Add support for objects
- [ ] Add support for behaviors
- [ ] Document how to add custom icons
- [ ] Add a button to reload extensions without reloading GDevelop IDE entirely.
- [ ] Create a "watcher" script that automatically run `node import-GDJS-Runtime` anytime a change is made.

## Development of extensions declared in C++ (`JsExtension.cpp` or `Extension.cpp`)

The majority of extensions are still declared in C++ for being compatible with GDevelop 4.
Check the sources in [Extensions folder](https://github.com/4ian/GD/tree/master/Extensions) and install [GDevelop.js](https://github.com/4ian/GDevelop.js). You'll then be able to make changes in C++ source files and have this reflected in the editor.