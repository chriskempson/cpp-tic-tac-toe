#!/usr/bin/env sh

# Need to CD into the application directory before running the application
# otherwise it will be unable to find resources (images, sounds, files).

# Get the directory this script is being run from
SCRIPT_DIR=$(dirname $(readlink -f $0))

cd $SCRIPT_DIR; ./tic-tac-toe
