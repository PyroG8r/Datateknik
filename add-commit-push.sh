#!/bin/sh
# adds, commits and pushes all files in current directory to main.

git add .
LANG=C git status -s | grep ^[MTADRCU] | sed -e 's/A/ Added/g'\
                                        -e 's/M/ Modified/g'\
                                        -e 's/T/ File type changed/g'\
                                        -e 's/D/ Deleted/g'\
                                        -e 's/R/ Renamed/g'\
                                        -e 's/C/ Copied/g'\
                                        -e 's/U/ Updated but unmerged/g'\
                                        -e 's/^.//g'\
                                        | git commit -F -

git push

