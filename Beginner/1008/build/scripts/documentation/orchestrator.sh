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

function _build_source_path()
{
    local path

    for ((count=; count <= manipulate[0]; count++)); do
        path="$path/${manipulate[$count]}"
    done
}

function source_path()
{
    local file="$0"
    local path=$(pwd)
    local manipulate=(
        "$(echo $file | awk -F '/' '{print NF}')"
        "$(echo $file | awk -F '/' '{print $1}')"
    )

    if [ "${manipulate[1]}" == '.' ]; then
        for ((count=2; count <= manipulate[0]; count++)); do
            path="$path/${manipulate[$count]}"
        done
    fi
}

source $(source_path "$0")/common/logger.sh
source $(source_path "$0")/generate/generate.sh
source $(source_path "$0")/generate/entrypoint.sh

function main()
{
    local arguments=("$1" "$2" "$3")

    echo "$0"
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
