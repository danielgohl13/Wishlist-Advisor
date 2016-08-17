 #!/bin/sh

compiler="./tools/compiler";
commonSources="BinPacking/src/Game.cpp BinPacking/src/Bin.cpp BinPacking/src/BinaryTree.cpp BinPacking/src/BinPacking.cpp";
buildDir="./build/";

function benchmark(){

    if [ ! -f "${buildDir}benchmark" ] ; then
        bash -c "$compiler benchmark.cpp  $commonSources";
        echo "# Executando o programa...";
        echo;
    fi

    bash -c "${buildDir}benchmark $1 $2";
}

function main(){
    if [ ! -f "${buildDir}main" ] ; then
        bash -c "$compiler main.cpp  $commonSources";
        echo "# Executando o programa...";
        echo;
    fi

    bash -c "${buildDir}main $1 $2";
}

case $1 in

    "fwl")
        bash -c "./tools/fetchWishlist $2"
    ;;

    "benchmark")
        benchmark "$2" "$3"
    ;;

    "benchmark.")
        benchmark "$2" "$3"
    ;;

    "benchmark.cpp")
        benchmark "$2" "$3"
    ;;

    "main")
        main "$2" "$3";
    ;;

    "main.")
        main "$2" "$3";
    ;;

    "main.cpp")
        main "$2" "$3";
    ;;

 	*)
 		main "$1" "$2";
 	;;

esac
