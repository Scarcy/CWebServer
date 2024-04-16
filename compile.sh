#!/bin/bash

# Option Flags
compile=false
run=false

# Parse Options
while getopts "cr" opt; do
	case $opt in
	c)
		compile=true
		;;
	r)
		compile=true
		run=true
		;;
	\?)
		echo "Invalid option: -$OPTARG" >&2
		exit 1
		;;
	esac
done

# Actions based on option flags
if $compile; then
	echo "Compiling Project"
	cmake --build build
fi

if $run; then
	./bin/EllefsenWebServer
fi

# Random Tangent about why I made it like this
# I was thinking about the lesser known side-effect of how switch/cases work (Not lesser known to experienced devs, but to noobies)
# How if we don't break out of the cases, it continues executing the following cases.
# I thought it would be interesting to use this side-effect to implement compile / compile & run.
# But then I realized that it would not work, since compilation always has to go first which defeats the entire purpose of my initial idea D=
# But I atleast got to semi implement the same functionality with the two final if-conditionals.
