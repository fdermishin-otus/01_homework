mkdir ./build
cd ./build
cmake -DPATCH_VERSION=$1 ../
cmake --build .
cmake --build . --target package
