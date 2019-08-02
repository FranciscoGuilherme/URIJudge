#!/bin/bash

: '
|------------------------------------------------
| GENERATE THE PROJECT DOCUMENTATION WITH doxygen
|------------------------------------------------
|
| Project  : Doxygen generator
| Filename : orchestrator.sh
| Version  : 0.0.0
| Date     : July 29, 2019
|
|------------------------------------------------
|
| Copyright (c) 2019, Francisco G. A. S. Bessa
| All rights reserved.
|
|------------------------------------------------
'

: '
|------------------------------------------------
| [description] Get the absolute path of the file
|
| [return]      [string] The absolute path
|------------------------------------------------
'
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

: '
|------------------------------------------------
| [description] Verify the argument
|
| [return]      [void]
|------------------------------------------------
'
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
source $(includes_path "$0")generate/entrypoint.sh
source $(includes_path "$0")generate/generate.sh

function main()
{
    local arguments=("$1" "$2" "$3")

    includes_path "$0"; path=${__}

    echo "$path"
    exit

}

main "$1" "$2"

: '
local doxyfile_directory

verify_parameters "$arguments"

if [ -z "$parameter" ]; then
    get_doxyfile_path "$parameter"; doxyfile_directory=${__}
fi

create_doxyfile "$doxyfile_directory"

if [ ! -z  "$replace_config" ] && [ "$replace_config" == '1' ]; then
    replace_configurations "$doxyfile_directory"
fi

printf "%s\n" "File updated with the latest settings"
'
