#!/bin/bash

function _replace_status()
{
    local arguments="$1"

    case "${arguments[2]}" in
        '1') create_doxyfile "${arguments[1]}" "$REPLACE_ACTIVATED" ;;
        *)   create_doxyfile "${arguments[1]}" "$REPLACE_DISABLED" ;;
    esac
}

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
        '-h') printf "%s\n" "\033[33mUsage:\033[0m\n bash documentation {doxygen_file_directory}" && exit ;;
        '-d')
                if [ ! -z "${arguments[1]}" ] && [ -f "${arguments[1]}" ] ; then
                    _replace_status "$arguments"
                fi

                if [ ! -f "${arguments[1]}" ]; then
                    arguments[3]="${arguments[2]}"
                    arguments[2]="${arguments[1]}"

                    read_doxyfile_path; arguments[1]=${__}
                    _replace_status "$arguments"
                fi
            ;;
        '-s')
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
