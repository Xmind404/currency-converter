
# currency-converter

Application for converting, checking currencies.

The program accesses live currency rates and performs conversions using: https://frankfurter.dev/, 
specifically via the endpoint https://api.frankfurter.dev/v1/.


## Features

- Help for list arguments
- Listing avaiable currencies
- Checking the rise and fall of a specific currency
- Converting currency from one to another

## Technologies used

- [FrankFurter API](https://frankfurter.dev/)
- [CMake](https://github.com/kitware/cmake)
- [C++ 26](https://en.wikipedia.org/wiki/C%2B%2B26)
- [VCPKG](https://github.com/microsoft/vcpkg)
- [CPR](https://github.com/libcpr/cpr)
- [CLion](https://www.jetbrains.com/clion/)

## Installation

Install my-project with [CMake](https://github.com/kitware/cmake) and [CPR](https://github.com/libcpr/cpr) and [VCPKG](https://github.com/microsoft/vcpkg)

```bash
git clone https://github.com/Xmind404/currency-converter.git
```

```bash
cd currency-converter
```

```bash
vcpkg install cpr:x64-windows
```

```bash
mkdir build
```

```bash
cd build
```

```bash
cmake -B . -S .. -DCMAKE_BUILD_TYPE=Release -DCMAKE_TOOLCHAIN_FILE=C:/vcpkg/scripts/buildsystems/vcpkg.cmake
```

```bash
cmake --build . --config Release
```

```bash
Release\currency-converter.exe
```
