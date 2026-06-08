# MyApp

MyApp is a minimal Unreal Program template. It is intended as a small starting point for building standalone tools for Unreal Engine.

Started with https://github.com/lpestl/UnrealSlateAppTemplate, and made modifications to it to remove an unnecessary extra module and keep directories leaner.

## Getting Started

Use this template as a base for a new Unreal Program. Rename `MyApp` to your program name in the target, module, source folder, namespaces, and project file as needed.

This app offers a 'toolset' where different tools can be added, similar to how an asset editor and its toolkit work.
A sample tool is included under:

```text
Source/MyApp/Private/Sample
```

To add your own tool do the following:

- Make a child class of `IMyAppTool`.
- Register the tool to the toolset in `FMyAppToolset::RegisterTools()`.
- (Optional) Add the tool tabs to the layout defined in `FMyAppToolset::LoadLayout()`.

## Usage in an Engine Source Directory

To place the program inside the engine, split the files and folders between the source and non-source.

Place the source files and folders in
```text
Engine/Source/Programs/[PROGRAM_NAME]/
```

Place the .uproject file and non-source folders (e.g. Config, Resources) here:
```text
/Engine/Programs/[PROGRAM_NAME]/
```

Example result:
```
# Source

/Engine/Source/Programs/[PROGRAM_NAME]/Private/
/Engine/Source/Programs/[PROGRAM_NAME]/Public/
/Engine/Source/Programs/[PROGRAM_NAME]/[PROGRAM_NAME].Build.cs
/Engine/Source/Programs/[PROGRAM_NAME]/[PROGRAM_NAME].Target.cs

# Non-source

/Engine/Programs/[PROGRAM_NAME]/Config/
/Engine/Programs/[PROGRAM_NAME]/Resources/
/Engine/Programs/[PROGRAM_NAME]/[PROGRAM_NAME].uproject
```

## Usage Outside The Engine Directory

When using this project outside the Unreal Engine source tree, simply right-click the `.uproject` file and choose the engine version to generate project files.

## Build And Run

Build and run the program with a `Development` target.

Do not use `Development Editor`; this template does not define an editor target.
