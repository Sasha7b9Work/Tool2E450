# 2023/09/08 20:52:34 (c) Aleksandr Shevchenko e-mail : Sasha7b9@tut.by

project (PanelGUI)

set(CMAKE_UNITY_BUILD OFF)

message("------------------------------------------------------------------------ ${PROJECT_NAME}")

include_directories(
    src
    ../../common/_VS_KEIL/HAL
    ../../common/libs
    ../../common/libs/STM32Cube_F4/Drivers/STM32F4xx_HAL_Driver/Inc
    ../../common/libs/STM32Cube_F4/Drivers/CMSIS/Device/ST/STM32F4xx/Include
    ../../common/_VS_KEIL/CMSIS
    ../../common
    ../../Panel/src
    ../../Panel/tests
    ../../Panel/src/Hardware/HAL
    ../../Panel/src/Hardware
    ../ThirdParty/wxWidgets/include
    ../../generated/ThirdParty/lib/vc_lib/mswud
)

add_definitions(-DSTM32F429xx -DGUI)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -MP -Wall")

add_compile_options(
    /wd4005     # 'xxx': macro redefinition
    /wd4514     # 'xxx': unreferenced inline function has been removed
    /wd4625     # 'xxx': copy constructor was implicitly defined as deleted
    /wd4626     # 'xxx': assignment operator was implicitly defined as deleted
    /wd4710     # function not inlined
    /wd4711     # function 'xxx' selected for automatic inline expansion
    /wd4820     # 'xxx': 'y' bytes padding added after data member 'zzz'
    /wd4996     # 'xxx': This function or variable may be unsafe. Consider using yyy instead. To disable
                # deprecation, use _CRT_SECURE_NO_WARNINGS
    /wd5026     # 'xxx': move constructor was implicitly defined as deleted
    /wd5027     # 'xxx': move assignment operator was implicitly defined as deleted
    /wd5039     # 'xxx': pointer or reference to potentially throwing function passed to extern C
                # function under -EHc.
    /wd5045     # Compiler will insert Spectre mitigation for memory load if /Qspectre switch specified
    /wd5204     # 'xxx': class has virtual functions, but its trivial destructor is not virtual;
                # instances of objects derived from this class may not be destructed correctly
)

file(GLOB VS_HAL             ../../common/_VS_KEIL/HAL/stm32f4xx_hal_gpio.*
                             ../../common/_VS_KEIL/HAL/stm32f4xx_hal_rcc.*
                             ../../common/_VS_KEIL/HAL/stm32f4xx_hal_cortex.*
                             ../../common/_VS_KEIL/HAL/stm32f4xx_hal.*)
file(GLOB SRC                ../../Panel/src/defines.h
                             ../../Panel/src/FreqMeter.*
                             ../../Panel/src/Log.*
                             ../../Panel/src/Settings.*
                                         src/Application_win.*
                                         src/main_win.cpp)
file(GLOB DEVICE             ../../Panel/src/Device/*)
file(GLOB DISPLAY            ../../Panel/src/Display/*.h
                             ../../Panel/src/Display/Colors.*
                             ../../Panel/src/Display/Display.*
                             ../../Panel/src/Display/Text.*
                             ../../Panel/src/Display/Primitives.*
                                         src/Display/*.*)
file(GLOB DISPLAY_FONT       ../../Panel/src/Display/Font/*.h
                             ../../Panel/src/Display/Font/*.cpp
                             ../../Panel/src/Display/Font/*.inc
                             ../../Panel/src/Display/Font/*.xml)
file(GLOB DISPLAY_PICTURES   ../../Panel/src/Display/Pictures/*.*)
file(GLOB GUI                            src/GUI/*)
file(GLOB HARDWARE           ../../Panel/src/Hardware/*FPGA.*
                             ../../Panel/src/Hardware/FreqMeter.*
                             ../../Panel/src/Hardware/VCP.h
                             ../../Panel/src/Hardware/Timer.*
                                         src/Hardware/VCP_win.cpp)
file(GLOB HARDWARE_HAL                   src/Hardware/HAL/*.*)
file(GLOB HARDWARE_KEYBOARD  ../../Panel/src/Hardware/Keyboard/Keyboard.h
                                         src/Keyboard/Keyboard_win.cpp)
file(GLOB MENU               ../../Panel/src/Menu/*.*)
file(GLOB MENU_PAGES         ../../Panel/src/Menu/Pages/*.*)
file(GLOB SETTINGS           ../../Panel/src/Settings/*.*)
file(GLOB UTILS              ../../Panel/src/Utils/*.*)

source_group(_VS/HAL            FILES ${VS_HAL})
source_group(src                FILES ${SRC})
source_group(Device             FILES ${DEVICE})
source_group(Display            FILES ${DISPLAY})
source_group(Display/Font       FILES ${DISPLAY_FONT})
source_group(Display/Pictures   FILES ${DISPLAY_PICTURES})
source_group(GUI                FILES ${GUI})
source_group(Hardware           FILES ${HARDWARE})
source_group(Hardware/HAL       FILES ${HARDWARE_HAL})
source_group(Hardware/Keyboard  FILES ${HARDWARE_KEYBOARD})
source_group(Menu               FILES ${MENU})
source_group(Menu/Pages         FILES ${MENU_PAGES})
source_group(Settings           FILES ${SETTINGS})
source_group(Utils              FILES ${UTILS})

set_source_files_properties(
    ../../Panel/src/Hardware/HAL/HAL.cpp
    ../../Panel/src/Hardware/HAL/HAL_FSMC.cpp
    ../../Panel/src/Hardware/HAL/HAL_TIM.cpp
    PROPERTIES SKIP_UNITY_BUILD_INCLUSION ON
)

add_executable(${PROJECT_NAME}
    ${VS_HAL}
    ${SRC}
    ${DEVICE}
    ${DISPLAY}
    ${DISPLAY_FONT}
    ${DISPLAY_PICTURES}
    ${HARDWARE}
    ${GUI}
    ${HARDWARE_HAL}
    ${HARDWARE_KEYBOARD}
    ${MENU}
    ${MENU_PAGES}
    ${SETTINGS}
    ${UTILS}
)

target_link_libraries(${PROJECT_NAME} ../../../generated/ThirdParty/lib/vc_lib/wxbase32u)
target_link_libraries(${PROJECT_NAME} ../../../generated/ThirdParty/lib/vc_lib/wxmsw32u_core)
target_link_libraries(${PROJECT_NAME} ../../../generated/ThirdParty/lib/vc_lib/wxpng)
target_link_libraries(${PROJECT_NAME} ../../../generated/ThirdParty/lib/vc_lib/wxzlib)

target_link_libraries(${PROJECT_NAME} WinMM.lib)
target_link_libraries(${PROJECT_NAME} Ws2_32.lib)
target_link_libraries(${PROJECT_NAME} version.lib)
target_link_libraries(${PROJECT_NAME} Imm32.Lib)
target_link_libraries(${PROJECT_NAME} Setupapi.lib)
target_link_libraries(${PROJECT_NAME} Comctl32.lib)
target_link_libraries(${PROJECT_NAME} Rpcrt4.lib)
