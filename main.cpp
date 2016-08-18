#include "Common/Common.hpp"
#include "BinPacking/BinPacking.hpp"
#include "Util/json.hpp"
#include <fstream>

using namespace binpacking;
using json = nlohmann::json;

WishList parser(String fileName);
bool fileExist(String fileName);

int Application::main(){

    if(Application::countArgs() < 2){
        out->put("Arquivo de entrada inálido.", true);
        return 1;
    }

    if(Application::countArgs() < 3){
        out->put("Valor máximo para compras inálido.", true);
        return 1;
    }

    String inputFile = Application::getArg(1);
    if(!fileExist(inputFile)){
        out->put("Arquivo de entrada inálido.", true);
        return 1;
    }

    float binSize = 0;
    try{
        std::string::size_type sz;
        binSize = std::stof(Application::getArg(2), &sz);
    }
    catch (std::invalid_argument e){
        out->put("Valor máximo para compras inálido.", true);
        return 1;
    }

    WishList wl = parser(inputFile);
    BinaryTree *t = NULL;
    BinCollection bins = doPacking(wl, binSize, &t);
    Bin *b = NULL;

    for(unsigned int i = 0; i < bins.size(); i++){

        out->put(i + 1)->put("ª Lista de Compras:", true);
        out->put("#\t Preço\t Nome", true);

        b = bins[i];
        for(unsigned int j = 0; j < b->length(); j++){
            out->put(b->at(j)->getOrder())
               ->put("\t ")
               ->put(b->at(j)->getPrice())
               ->put("\t ")
               ->put(b->at(j)->getName(), true);
        }

        out->put("Sobra: ")->put(binSize - b->getSize(), true);
        out->putNewLine();
    }

    out->put("Deseja exibir a ávore de empacotamento? [s/N]: ");
    if(in->putBool("s", "n", 0)){
        out->put("Árvore de empacotamento:", true);
        t->print();
        out->putNewLine();
    }

    //Limpa a memória
    delete t;
    while(!wl.empty()){
        Game *g = wl.back();
        wl.pop_back();
        delete g;
    }

	return 0;
}

WishList parser(String fileName){

    std::ifstream ifs(fileName);
    std::string content((std::istreambuf_iterator<char>(ifs)), (std::istreambuf_iterator<char>()));
    WishList wl;
    json j = json::parse(content);

    for(unsigned int i = 0; i < j.size(); i++){
        wl.push_back(new Game(j[i]["order"], j[i]["price"], j[i]["name"]));
    }

    return wl;
}

bool fileExist(String fileName){
    std::ifstream infile(fileName);
    return infile.good();
}
