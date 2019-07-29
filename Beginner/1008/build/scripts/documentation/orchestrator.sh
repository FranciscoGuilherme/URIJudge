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

source initialize.sh
source common/logger.sh
source generate/generate.sh

function main()
{
    local arguments=("$1" "$2" "$3")

    local doxyfile_directory

    verify_parameters "$parameter"

    if [ -z "$parameter" ]; then
        get_doxyfile_path "$parameter"; doxyfile_directory=${__}
    fi

    create_doxyfile "$doxyfile_directory"

    if [ ! -z  "$replace_config" ] && [ "$replace_config" == '1' ]; then
        replace_configurations "$doxyfile_directory"
    fi

    printf "%s\n" "File updated with the latest settings"
}

main "$1" "$2"
