apt update
sudo apt install -y cmake wget

mkdir milrenderer_install_deps_tmp && cd milrenderer_install_deps_tmp

wget https://codeload.github.com/bkaradzic/bgfx.cmake/zip/refs/tags/v1.129.8940-496 -O bgfx.cmake-1.129.8940-496.zip
unzip bgfx.cmake-1.129.8940-496.zip
cd bgfx.cmake-1.129.8940-496
mkdir build && cd build
cmake ..
make -j$(nproc)
sudo make install
cd ../..

wget https://codeload.github.com/open-source-parsers/jsoncpp/zip/refs/tags/1.9.6 -O jsoncpp-1.9.6.zip
unzip jsoncpp-1.9.6.zip
cd jsoncpp-1.9.6
mkdir build && cd build
cmake ..
make -j$(nproc)
sudo make install
cd ../..

cd ..
rm -rf ./milrenderer_install_deps_tmp

echo "Installed dependencies"
