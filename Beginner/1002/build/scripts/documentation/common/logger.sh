#!/bin/bash

LOG_FILE=/tmp/doxygen_generator.log

: '
|------------------------------------------------
| [description] Save the error description and
|               date in a file
|
| [return]      [void]
|------------------------------------------------
'
function build_error_file()
{
    __ERRNO__="$1"

    {
        printf "%s\n" "-------------------------------"
        printf "%s\n\n" "$(date)"
        printf "[ERROR] (%s)\n" "$__ERRNO__"
    } >> "$LOG_FILE"
}

: '
|------------------------------------------------
| [description] Check the command statsu code
|               looking for any error
|
| [return]      [void]
|------------------------------------------------
'
function check()
{
    __CODE__=$1
    __ERRNO__=$2

    if [ -z "$__CODE__" ] || [ "$__CODE__" != 0 ]; then
        build_error_file "$__ERRNO__"

        printf "%s\n\n" "Somenthing didn't work well. Error saved on $LOG_FILE"

        exit
    fi
}
