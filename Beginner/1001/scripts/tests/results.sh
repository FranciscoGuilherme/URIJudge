#!/bin/bash

source dbg.sh
source parameters.sh

run_all_cases()
{
    local path="$1"

    mkdir output

    for test in ./cases/*; do
        file=$(echo "$test" | awk -F '/' '{ printf $3 }')

        cat "$test" | "$path" > ./output/"$file"
    done

    return 0
}

get_directory_path()
{
    local path=$1

    while [ -z "$path" ]; do
        read -r path
    done

    if [ ! -d "$path" ]; then
        return 1
    fi

    __ERRNO__=$(run_all_cases "$path" 2>&1) || check $? "$__ERRNO__"

    return 0
}

main()
{
    local path;

    if [ -f "${BINARIES[PROGRAM]}" ]; then
        __ERRNO__=$(run_all_cases "${BINARIES[PROGRAM]}" 2>&1) || check $? "$__ERRNO__"

        return 0
    fi

    if [ -z "$1" ]; then
        printf "%s" "Input the absolute path of the directory: "

        __ERRNO__=$(get_directory_path "$1" 2>&1) || check $? "$__ERRNO__"
    fi

    return 0
}

main "$1"
