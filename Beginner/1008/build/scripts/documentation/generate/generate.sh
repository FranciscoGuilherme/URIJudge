#!/bin/bash

source $(pwd)/parameters.sh
source $(pwd)/../common/logger.sh

: '
|------------------------------------------------
| [description] Create new doxyfile based on a
|               specific directory
|
| [return]      [void]
|------------------------------------------------
'
function create_doxyfile()
{
    local $doxyfile_directory="$1"

    if [ -z "$doxyfile_directory" ]; then
        local current_directory=$(pwd)

        __ERRNO__=$(cd "$current_directory" 2>&1) || check $? "$__ERRNO__"
        __ERRNO__=$(cd ../../../src 2>&1) || check $? "$__ERRNO__"
    fi

    if [ ! -z "$doxyfile_directory" ]; then
        __ERRNO__=$(cd $doxyfile_directory 2>&1) || check $? "$__ERRNO__"
    fi

    doxygen -g
    doxygen Doxyfile
}

: '
|------------------------------------------------
| [description] Searches for a particular setting
|               in the doxygen file and how it is
|               activated by string substitution
|
| [return]      [void]
|------------------------------------------------
'
function replace_configurations()
{
    local doxygen="$1"

    for configuration in "${CONFIG[@]}"; do
        sed -i 's/^'"$configuration"'.*NO$/'"$configuration"' = YES/g' "$doxygen"
    done
}
