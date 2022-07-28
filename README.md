# Shoegaze 2
*This project is in early development stage* \
\
Shoegaze 2 is a cross-platform real-time audio processing library. \
This library provides several interfaces for graphics, user input, audio I/O, and manages it all via these interfaces.\

# Including Shoegaze 2 in projects
CMake:
```
add_subdirectory(path/to/shoegaze2 [binary_dir])
shoegaze2_add_library(shoegaze2-lib)
target_link_libraries(<target> PUBLIC shoegaze2-lib ...)
```

# Implementations
- [Desktop](https://github.com/shoegaze2/shoegaze2-desktop) - Windows, Linux and MacOS
- Bare-metal RaspberryPi - *work in progress* 

# Dependencies
- [freetype](https://github.com/freetype/freetype) - used to convert fonts to paths
