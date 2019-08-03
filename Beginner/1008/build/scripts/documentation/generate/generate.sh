#!/bin/bash

source "$(pwd)"/common/logger.sh
source "$(pwd)"/generate/parameters.sh

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
    local doxyfile_directory="$1"
    local replace="$2"

    if [ ! -z "$doxyfile_directory" ] && [ -d "$doxyfile_directory" ]; then
        cd "$doxyfile_directory"

        doxygen -g "$doxyfile_directory"/Doxyfile

        if [ "$replace" == '1' ]; then
            replace_configurations Doxyfile "$doxyfile_directory"
        fi

        doxygen "$doxyfile_directory"/Doxyfile
    else
        exit
    fi
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
    local file="$1"
    local doxyfile_directory="$2"

    for configuration in "${CONFIG[@]}"; do
        sed -i 's/^'"$configuration"'.*NO$/'"$configuration"' = YES/g' "$doxyfile_directory"/"$file"
    done
}
