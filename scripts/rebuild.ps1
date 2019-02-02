rm -r build
mkdir build
cd build
cmake .. -DCMAKE_BUILD_TYPE=Debug -DCMAKE_INSTALL_PREFIX=/usr/local/projectfina-web -G "MinGW Makefiles"
cmake --build . --target install
