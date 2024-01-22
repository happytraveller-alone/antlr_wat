# if exists CMakeCache.txt, then remove it
if [ -f "CMakeCache.txt" ]; then
    rm CMakeCache.txt
fi
make clean