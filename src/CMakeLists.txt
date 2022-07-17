function(shoegaze2_add_library TARGET)
    message(STATUS "Shoegaze2 Library '${TARGET}'")

    set(SG2_DIR ${SHOEGAZE2_SRC_PATH}/Shoegaze2)
    add_library(${TARGET} STATIC
            ${SG2_DIR}/GUI/Primitives/Point.h
            ${SG2_DIR}/GUI/Primitives/Size.h
            ${SG2_DIR}/GUI/Primitives/Position.h
            ${SG2_DIR}/GUI/Color.h
            ${SG2_DIR}/GUI/View.h
            ${SG2_DIR}/GUI/Font/Font.h
            ${SG2_DIR}/GUI/Font/Font.cpp
            ${SG2_DIR}/System/Interface/Audio/AudioBuffer.h
            ${SG2_DIR}/System/Interface/Audio/AudioMixer.h
            ${SG2_DIR}/System/Interface/Audio/AudioMixer.cpp
            ${SG2_DIR}/System/Interface/Audio/IAudioDescriptor.h
            ${SG2_DIR}/System/Interface/Audio/IAudioDescriptor.cpp
            ${SG2_DIR}/System/Interface/Audio/IAudioDevice.h
            ${SG2_DIR}/System/Interface/Audio/IAudioDevice.cpp
            ${SG2_DIR}/System/Interface/Audio/IAudioSystem.h
            ${SG2_DIR}/System/Interface/Audio/IAudioSystem.cpp
            ${SG2_DIR}/System/Interface/GUI/IBrush.h
            ${SG2_DIR}/System/Interface/GUI/ICanvas.h
            ${SG2_DIR}/System/Interface/GUI/IDisplayDevice.h
            ${SG2_DIR}/System/Interface/GUI/IImage.h
            ${SG2_DIR}/System/Interface/GUI/IPaint.h
            ${SG2_DIR}/System/Interface/GUI/IPath.h
            ${SG2_DIR}/System/Interface/GUI/IRenderingContext.h
            ${SG2_DIR}/System/Interface/GUI/IRenderingContext.cpp
            ${SG2_DIR}/System/Text/UTF8Encoding.cpp
            ${SG2_DIR}/System/Text/UTF8Encoding.h
            ${SG2_DIR}/System/Text/String.cpp
            ${SG2_DIR}/System/Text/String.h
            ${SG2_DIR}/System/Text/Encoding.cpp
            ${SG2_DIR}/System/Text/Encoding.h
            ${SG2_DIR}/System/Events/Event.h
            ${SG2_DIR}/System/Events/Event.cpp
            )

    include(${SHOEGAZE2_SRC_PATH}/freetype.cmake)
    freetype_add_library(${TARGET}-freetype)
    get_target_property(LIBFREETYPE_${TARGET}_INCLUDES ${TARGET}-freetype INCLUDE_DIRECTORIES)

    target_include_directories(${TARGET} PUBLIC ${SHOEGAZE2_SRC_PATH} ${LIBFREETYPE_${TARGET}_INCLUDES})

    add_dependencies(${TARGET} ${TARGET}-freetype)
    target_link_libraries(${TARGET} ${TARGET}-freetype)
endfunction()


