#!/bin/sh

if [ $# -ne 2 ]
then
    echo "Error: two arguments are required."
    echo "Usage: $0 <writefile> <writestr>"
    exit 1
fi

writefile=$1
writestr=$2

write_dir=$(dirname "$writefile")

mkdir -p "$write_dir"

if [ $? -ne 0 ]
then
    echo "Error: could not create directory $write_dir"
    exit 1
fi

echo "$writestr" > "$writefile"

if [ $? -ne 0 ]
then
    echo "Error: could not create file $writefile"
    exit 1
fi

exit 0
