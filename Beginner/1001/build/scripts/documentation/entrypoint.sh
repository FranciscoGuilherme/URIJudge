#!/bin/bash

: '
|------------------------------------------------
| GENERATE THE PROJECT DOCUMENTATION WITH doxygen
|------------------------------------------------
|
| Project  : Doxygen generator
| Filename : entrypoint.sh
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

source "$(pwd)"/common/logger.sh
source "$(pwd)"/generate/generate.sh

: '
|------------------------------------------------
| [description] Replace or not the default confi-
|               gurations of doxygen file
|
| [return]      [void]
|------------------------------------------------
'

function _replace_status()
{
    local arguments=("$1" "$2" "$3")

    case "${arguments[2]}" in
        '--replace') create_doxyfile "${arguments[1]}" "$REPLACE_ACTIVATED" ;;
        *)           create_doxyfile "${arguments[1]}" "$REPLACE_DISABLED" ;;
    esac
}

: '
|------------------------------------------------
| [description] Verify the input arguments
|
| [return]      [void]
|------------------------------------------------
'
function verify_parameters()
{
    local arguments=("$1" "$2" "$3")

    case "${arguments[0]}" in
        '-h') printf "%s\n" 'Usage: bash <script.sh> <doxygen_file_directory> [--replace]' && exit ;;
        '-d')
                if [ ! -z "${arguments[1]}" ] && [ -d "${arguments[1]}" ]; then
                    _replace_status "${arguments[@]}"
                fi

                if [ ! -d "${arguments[1]}" ]; then
                    arguments[2]="${arguments[1]}"

                    read_doxyfile_path; arguments[1]=${__}
                    _replace_status "${arguments[@]}"
                fi
            ;;
        '--replace')
                arguments[3]=${arguments[0]}
                arguments[0]=${arguments[1]}
                arguments[1]=${arguments[2]}
                arguments[2]=${arguments[3]}

                verify_parameters "${arguments[@]}"
            ;;
    esac
}

: '
|------------------------------------------------
| [description] Read the doxygen location file
|
| [return]      [string] Doxygen location
|------------------------------------------------
'
function read_doxyfile_path()
{
    local doxygen_directory

    while [ -z "$doxygen_directory" ]; do
        printf "%s" "Input the absolute path of the directory: "
        read -r doxygen_directory
    done

    __="$doxygen_directory"
}

: '
|------------------------------------------------
| [description] Entrypoint function
|
| [return]      [void]
|------------------------------------------------
'
function main()
{
    local arguments=("$1" "$2" "$3")

    verify_parameters "${arguments[@]}"
}

main "$1" "$2" "$3"
