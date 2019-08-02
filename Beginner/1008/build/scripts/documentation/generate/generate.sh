#!/bin/bash

function _source_path()
{
    local path=$(pwd)
    local file="${0//.\/}"
    local amount=$(echo "$file" | awk -F '/' '{print NF}')

    for ((count = 1; count <= amount; count++)); do
        path="$path/$(echo "$file" | awk -F '/' '{print $'$count'}')"
    done

    __=$path
}

function includes_path()
{
    declare -A file

    local path
    local file=(
        [path]="$0"
        [name]=$(echo "$0" | awk -F '/' '{print $NF}')
    )

    _source_path "${file['path']}"; path=${__}

    path=$(echo "${path//\/${file[name]}//}")

    __=$path
}

source $(includes_path "$0")common/logger.sh
source $(includes_path "$0")generate/parameters.sh

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
