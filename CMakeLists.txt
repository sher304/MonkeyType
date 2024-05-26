cmake_minimum_required(VERSION 3.27)
project(MonkeyType)

set(CMAKE_CXX_STANDARD 23)

set(BUILD_SHARED_LIBS FALSE)

include(FetchContent)

FetchContent_Declare(
        SFML
        GIT_REPOSITORY  https://github.com/SFML/SFML
        GIT_TAG         2.6.1
)

FetchContent_MakeAvailable(SFML)

FetchContent_Declare(
        fmt
        GIT_REPOSITORY https://github.com/fmtlib/fmt
        GIT_TAG 10.2.1
)

FetchContent_MakeAvailable(fmt)

add_executable(MonkeyType main.cpp
        Helper/Generator_Word/words_generator.cpp
        Helper/Generator_Word/words_generator.h
        Helper/Operator/Erase_operator.h
        Helper/Operator/Erase_operator.cpp
        Extension/TextParameter.h
        Helper/WordChecker/WordChecker.cpp
        Helper/WordChecker/WordChecker.h
        Helper/ScoreSaverReader/GameSave.cpp
        Helper/ScoreSaverReader/GameSave.h
        Helper/ScoreSaverReader/GameScoreReader.cpp
        Helper/ScoreSaverReader/GameScoreReader.h
        Helper/SaveGame/SaveGame.cpp
        Helper/GameReloader/GameReloader.cpp
        Helper/GameReloader/GameReloader.h
        Helper/SaveGame/saveGame.h
        Helper/GameLoader/GameLoad.cpp
        Helper/GameLoader/GameLoad.h
        Helper/ParticleDraw/drawParticles.cpp
        Helper/ParticleDraw/drawParticles.h
        Helper/WordsDraw/WordsDraw.cpp
        Helper/WordsDraw/WordsDraw.h
        Helper/AlignCenter/AlighnCenter.cpp
        Helper/AlignCenter/AlignCenter.h
)

target_link_libraries(MonkeyType sfml-graphics)
target_link_libraries(MonkeyType fmt)
