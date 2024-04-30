#!/bin/bash

message=/var/spool/folder/message
[ -r "$message" ]  || { echo "can not read this message"; exit 1; }
echo "$message has message from:"
grep "^From " $message

