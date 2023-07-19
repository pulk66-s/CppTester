#!/bin/bash

##################################
# Installation script for Centos #
##################################

#####################################################################
# This script install CppMochaTester for Centos                     #
# It can works for other OS but it's developped and tests on Centos #
# Steps:                                                            #
#  - Compile sources                                                #
#  - Copy binary into /usr/bin                                      #
#  - Copy sources into /lib                                         #
#  - Copy includes into /usr/include                                #
# @author: pulk66-s                                                 #
# @created-at: 18/07/2023                                           #
# @updated-at: 18/07/2023                                           #
#####################################################################

set -euo pipefail
IFS=$'\n\t'

GREEN='\033[0;32m'
RED='\033[0;31m'
NC='\033[0m' # No Color
BINARY_NAME="CppTester"
BINARY_TARGET="/usr/bin/CppTester"
SOURCES_PATH="./src/Tests"
SOURCES_TARGET="/lib/CppTester/"
INCLUDES_PATH="./includes"
INCLUDES_TARGET="/usr/include/CppTester/"

function title() {
    echo -e $GREEN $1 $NC
}

function error() {
    echo -e $RED $1 $NC
}

function cleanup() {
    title "Cleanup"
    make fclean
}

function compile_sources() {
    title "Compile sources"
    make re
}

function copy_binary() {
    title "Copy binary"
    sudo rm $BINARY_TARGET || true
    sudo cp $BINARY_NAME $BINARY_TARGET
}

function copy_sources() {
    title "Copy sources"
    sudo rm -rf $SOURCES_TARGET || true
    sudo mkdir -p $SOURCES_TARGET
    sudo cp -r $SOURCES_PATH $SOURCES_TARGET
}

function copy_includes() {
    title "Copy includes"
    sudo rm -rf $INCLUDES_TARGET || true
    sudo mkdir -p $INCLUDES_TARGET
    sudo cp -r $INCLUDES_PATH/* $INCLUDES_TARGET
}

trap cleanup EXIT

compile_sources
copy_binary
copy_sources
copy_includes
