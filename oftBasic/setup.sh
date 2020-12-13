#!/bin/bash

rm -rf .git
rm LICENSE
rm README.md
mv README.md.starter README.md
rm "$0"
