 #!/bin/sh

compiler="./tools/compiler";
files="main.cpp BinPacking/src/Game.cpp BinPacking/src/Bin.cpp BinPacking/src/BinaryTree.cpp BinPacking/src/BinPacking.cpp";
binary="./build/main";
inputFile=$1;
inputBinSize=$2;

bash -c "$compiler $files";
echo "# Executando o programa...";
echo;
bash -c "$binary $inputFile $inputBinSize";
