set -e

clang++ $(find proto/ -type f -name "*.cpp")  -Wall -Wextra -Isrc/ -std=c++17 -ggdb -o build
echo Compilation finished.
./build