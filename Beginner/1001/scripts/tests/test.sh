#!/bin/bash

source dbg.sh
source parameters.sh

verify_program_output()
{
    for result in ./output/*; do
        cat "$result" | "${BINARIES[TESTS]}"
    done
}

verify_program_output
