#!/bin/bash

: '
|------------------------------------------------
| GENERATE THE PROJECT DOCUMENTATION WITH doxygen
|------------------------------------------------
|
| Project  : Doxygen generator
| Filename : documentation.sh
| Version  : 0.0.0
| Date     : July 28, 2019
|
|------------------------------------------------
|
| Copyright (c) 2019, Francisco G. A. S. Bessa
| All rights reserved.
|
|------------------------------------------------
'

source dbg.sh
source parameters.sh

: '
|------------------------------------------------
| [description] Searches for a particular setting
|               in the doxygen file and how it is
|               activated by string substitution
|
| [return]      [int] Status code zero of success
|                     program execution
|------------------------------------------------
'
function replace_configurations()
{
    local doxygen="$1"

    for configuration in "${CONFIG[@]}"; do
        sed -i 's/^'"$configuration"'.*NO$/'"$configuration"' = YES/g' "$doxygen"
    done
}

: '
|------------------------------------------------
| [description] Read the doxygen location file
|
| [return]      [string] Doxygen location
|------------------------------------------------
'
function get_doxygen_path_directory()
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
| [description] Entrypoint
|
| [return]      [int] Status code zero of success
|                     program execution
|------------------------------------------------
'
function main()
{
    local doxygen

    get_doxygen_path_directory; doxygen=${__}
    __ERRNO__=$(replace_configurations "$doxygen" 2>&1) || check $? "$__ERRNO__"

    printf "%s\n" "File updated with the latest settings"
}

main
