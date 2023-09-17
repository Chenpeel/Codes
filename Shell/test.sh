#!/bin/bash
if [ -f "~/ins.sh" ]; then
    echo "There's file named ins.sh at alpha"
elif [ -f "~/test.sh" ]; then
    echo "There's not file  named test.sh at alpha"
else
    echo "????"
fi