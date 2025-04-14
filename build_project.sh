#!/bin/bash

# Colors
RED="\033[0;31m"
GREEN="\033[0;32m"
YELLOW="\033[0;33m"
R="\033[0m"

# Configurations
PROJECT_NAME=no_name_engine
ECC=-DCMAKE_EXPORT_COMPILE_COMMANDS=ON
PMV=-DCMAKE_POLICY_VERSION_MINIMUM=3.5
BUILD_DIRECTORY=build
BINARY="./$BUILD_DIRECTORY/$PROJECT_NAME"

# Functions
build() {
    echo -e "${YELLOW}Running CMake and generating files in $BUILD_DIRECTORY...${R}"
    sleep 1
    cmake -B $BUILD_DIRECTORY $ECC $PMV

    if [ $? -eq 0 ]; then
        echo -e "${GREEN}CMake finished successfully.${R}"
        sleep 1
        echo -e "${YELLOW}Running make to build the project...${R}"
        sleep 1
        cd $BUILD_DIRECTORY && make
    else
        echo -e "${RED}Error while running CMake.${R}"
        exit 1
    fi
}

clean() {
    echo -e "${YELLOW}Cleaning $BUILD_DIRECTORY directory...${R}"
    sleep 1
    rm -rf $BUILD_DIRECTORY
    echo -e "${GREEN}Build directory removed.${R}"
}

run() {
    local CURRENT_DIR
    CURRENT_DIR=$(pwd)
    build
    cd "$CURRENT_DIR"
    echo -e "${YELLOW}Running the application...${R}"
    $BINARY
}

help() {
    echo -e "${YELLOW}Usage:${R} ./build.sh {build|clean|run|help}"
    echo
    echo "  build   Build the project using CMake and Make"
    echo "  clean   Remove the build directory"
    echo "  run     Run the compiled binary"
    echo "  help    Show this help message"
}

# Main entry point
case "$1" in
    build) build ;;
    clean) clean ;;
    run) run ;;
    help | *) help ;;
esac
