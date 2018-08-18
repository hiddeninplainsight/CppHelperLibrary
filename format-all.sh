#!/bin/bash

find . \( -path ./third-party-libraries -o -path ./cmake-build-* \) -prune -type f -o -name '*.h' -exec clang-format -style=file -i {} \;
find . \( -path ./third-party-libraries -o -path ./cmake-build-* -o -path ./tests \) -prune -type f -o -name '*.cpp' -exec clang-format -style=file -i {} \;
