#!/bin/bash

source "$(pwd)"/common/logger.sh
source "$(pwd)"/generate/parameters.sh

: '
|------------------------------------------------------
| [language]    English
| [description] Create new doxyfile based on a specific
|               directory
|
| [param  : string] $1 Doxyfile directory
| [param  : string] $2 Flag to active file replace
| [param  : string] $3 Language to export documentation
|
| [return : void]
|------------------------------------------------------
'
function create_doxyfile()
{
    local doxyfile_directory="$1"
    local doxyfile_replace="$2"
    local doxyfile_language="$3"

    if [ ! -z "$doxyfile_directory" ] && [ -d "$doxyfile_directory" ]; then
        cd "$doxyfile_directory"

        doxygen -g "$doxyfile_directory"/Doxyfile

        if [ "$doxyfile_replace" == '1' ]; then
            replace_configurations "$doxyfile_directory" Doxyfile
        fi

        set_language "$doxyfile_directory" Doxyfile "$3"

        doxygen "$doxyfile_directory"/Doxyfile
    fi
}

: '
|------------------------------------------------------
| [language]    English
| [description] Searches for a particular setting in
|               the doxygen file and how its activated
|               by string substitution
|
| [param : string] $1 Doxyfile directory
| [param : string] $2 Doxygen configuration file name
|
| [return : void]
|------------------------------------------------------
'
function replace_configurations()
{
    local doxyfile_directory="$1"
    local doxyfile_file_name="$2"

    for configuration in "${CONFIG[@]}"; do
        sed -i 's/^'"$configuration"'.*NO$/'"$configuration"' = YES/g' "$doxyfile_directory"/"$doxyfile_file_name"
    done
}

: '
|------------------------------------------------------
| [language]    English
| [description] Configure the output language for
|               doxyfile documentation
|
| [param : string] $1 Doxyfile directory
| [param : string] $2 Doxygen configuration file name
| [param : string] $3 Language of the documentation
|
| [return : void]
|------------------------------------------------------
'
function set_language()
{
    local doxyfile_directory="$1"
    local doxyfile_file_name="$2"
    local doxyfile_language="$3"

    case "$doxyfile_language" in
        'pt-br') sed -i 's/^OUTPUT_LANGUAGE.*$/OUTPUT_LANGUAGE = Portuguese/g' "$doxyfile_directory"/"$doxyfile_file_name" ;;
        *)       sed -i 's/^OUTPUT_LANGUAGE.*$/OUTPUT_LANGUAGE = English/g' "$doxyfile_directory"/"$doxyfile_file_name" ;;
    esac
}
