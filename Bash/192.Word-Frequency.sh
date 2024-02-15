#!/bin/bash

# Read from the file words.txt and output the word frequency list to stdout.

# Replace multiple spaces with a single space, convert spaces to newlines, and convert to lowercase
cat words.txt | tr -s ' ' '\n' | tr '[:upper:]' '[:lower:]' |
# Remove empty lines
awk NF |
# Count the frequency of each word and sort them by frequency
sort | uniq -c | sort -nr |
# Format the output as required
awk '{print $2 " " $1}'