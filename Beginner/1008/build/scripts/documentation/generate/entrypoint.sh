#!/bin/bash

: '
|------------------------------------------------
| [description] Verify the argument
|
| [return]      [void]
|------------------------------------------------
'
function verify_parameters()
{
    local arguments="$1"

    case "${arguments[0]}" in
        '--help') printf "%s\n" "\033[33mUsage:\033[0m\n bash documentation {doxygen_file_directory}" && exit;;
        '--dir'
    esac
}

: '
|------------------------------------------------
| [description] Read the doxygen location file
|
| [return]      [string] Doxygen location
|------------------------------------------------
'
function get_doxyfile_path()
{
    local doxygen_directory="$1"

    if [ "$doxygen_directory" == '--help' ]; then
        doxygen_directory=''
    fi

    while [ -z "$doxygen_directory" ]; do
        printf "%s" "Input the absolute path of the directory: "
        read -r doxygen_directory
    done

    __="$doxygen_directory"
}
