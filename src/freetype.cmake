set(FREETYPELIB_DIR ${CMAKE_CURRENT_LIST_DIR}/../deps/freetype)

file(GLOB PUBLIC_HEADERS "${FREETYPELIB_DIR}/include/ft2build.h" "${FREETYPELIB_DIR}/include/freetype/*.h")
file(GLOB PUBLIC_CONFIG_HEADERS "${FREETYPELIB_DIR}/include/freetype/config/*.h")
file(GLOB PRIVATE_HEADERS "${FREETYPELIB_DIR}/include/freetype/internal/*.h")


set(BASE_SRCS
        ${FREETYPELIB_DIR}/src/autofit/autofit.c
        ${FREETYPELIB_DIR}/src/base/ftbase.c
        ${FREETYPELIB_DIR}/src/base/ftbbox.c
        ${FREETYPELIB_DIR}/src/base/ftbdf.c
        ${FREETYPELIB_DIR}/src/base/ftbitmap.c
        ${FREETYPELIB_DIR}/src/base/ftcid.c
        ${FREETYPELIB_DIR}/src/base/ftfstype.c
        ${FREETYPELIB_DIR}/src/base/ftgasp.c
        ${FREETYPELIB_DIR}/src/base/ftglyph.c
        ${FREETYPELIB_DIR}/src/base/ftgxval.c
        ${FREETYPELIB_DIR}/src/base/ftinit.c
        ${FREETYPELIB_DIR}/src/base/ftmm.c
        ${FREETYPELIB_DIR}/src/base/ftotval.c
        ${FREETYPELIB_DIR}/src/base/ftpatent.c
        ${FREETYPELIB_DIR}/src/base/ftpfr.c
        ${FREETYPELIB_DIR}/src/base/ftstroke.c
        ${FREETYPELIB_DIR}/src/base/ftsynth.c
        ${FREETYPELIB_DIR}/src/base/fttype1.c
        ${FREETYPELIB_DIR}/src/base/ftwinfnt.c
        ${FREETYPELIB_DIR}/src/bdf/bdf.c
        ${FREETYPELIB_DIR}/src/bzip2/ftbzip2.c
        ${FREETYPELIB_DIR}/src/cache/ftcache.c
        ${FREETYPELIB_DIR}/src/cff/cff.c
        ${FREETYPELIB_DIR}/src/cid/type1cid.c
        ${FREETYPELIB_DIR}/src/gzip/ftgzip.c
        ${FREETYPELIB_DIR}/src/lzw/ftlzw.c
        ${FREETYPELIB_DIR}/src/pcf/pcf.c
        ${FREETYPELIB_DIR}/src/pfr/pfr.c
        ${FREETYPELIB_DIR}/src/psaux/psaux.c
        ${FREETYPELIB_DIR}/src/pshinter/pshinter.c
        ${FREETYPELIB_DIR}/src/psnames/psnames.c
        ${FREETYPELIB_DIR}/src/raster/raster.c
        ${FREETYPELIB_DIR}/src/sdf/sdf.c
        ${FREETYPELIB_DIR}/src/sfnt/sfnt.c
        ${FREETYPELIB_DIR}/src/smooth/smooth.c
        ${FREETYPELIB_DIR}/src/truetype/truetype.c
        ${FREETYPELIB_DIR}/src/type1/type1.c
        ${FREETYPELIB_DIR}/src/type42/type42.c
        ${FREETYPELIB_DIR}/src/winfonts/winfnt.c
        ${FREETYPELIB_DIR}/src/base/ftdebug.c
        ${FREETYPELIB_DIR}/src/svg/ftsvg.c
        )

list(APPEND BASE_SRCS "${FREETYPELIB_DIR}/src/base/ftsystem.c")

function(freetype_add_library TARGET)
    add_library("${TARGET}" STATIC
            ${PUBLIC_HEADERS}
            ${PUBLIC_CONFIG_HEADERS}
            ${PRIVATE_HEADERS}
            ${BASE_SRCS}
            )

    target_compile_definitions(
            "${TARGET}" PRIVATE FT2_BUILD_LIBRARY)


    target_include_directories("${TARGET}"
            PUBLIC
            ${FREETYPELIB_DIR}/include
            ${FREETYPELIB_DIR}/include/freetype/config
            PRIVATE
            ${FREETYPELIB_DIR}/include/freetype/internal
            )
endfunction()



