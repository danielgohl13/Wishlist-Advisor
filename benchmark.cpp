#include "Common/Common.hpp"
#include "BinPacking/BinPacking.hpp"
#include "Util/Chronometer.hpp"

using namespace binpacking;

int Application::main(){

    bool verbose = false;

    if(Application::countArgs() < 2){
        out->put("Quantidade de itens inválida.", true);
        return 1;
    }

    if(Application::countArgs() < 3){
        out->put("Valor máximo para compras inálido.", true);
        return 1;
    }

    std::string::size_type sz;
    int wlSize = 0;
    try{
        wlSize = std::stoi(Application::getArg(1), &sz);
    }
    catch (std::invalid_argument e){
        out->put("Quantidade de itens inválida.", true);
        return 1;
    }

    float binSize = 0;
    try{
        binSize = std::stof(Application::getArg(2), &sz);
    }
    catch (std::invalid_argument e){
        out->put("Valor máximo para compras inálido.", true);
        return 1;
    }

    WishList wl;
    if(verbose) out->put("Lista de entrada: ", true);

    for(int i = 0; i < wlSize; i++){
        wl.push_back(new Game(i, (float) randomic->getInt(75, 5), "item"));
        if(verbose){
            out->put(wl[i]->getOrder())
               ->put("\t ")
               ->put(wl[i]->getPrice())
               ->put("\t ")
               ->put(wl[i]->getName(), true);
       }
    }

    if(verbose) out->putNewLine();

    Chronometer ch;
    ch.start();
    BinCollection bins = doPacking(wl, binSize);
    ch.pause();

    if(verbose){
        Bin *b = NULL;
        for(int i = 0; i < bins.size(); i++){

            out->put(i + 1)->put("ª Lista de Compras:", true);
            out->put("#\t Preço\t Nome", true);

            b = bins[i];
            for(int j = 0; j < b->length(); j++){
                out->put(b->at(j)->getOrder())
                   ->put("\t ")
                   ->put(b->at(j)->getPrice())
                   ->put("\t ")
                   ->put(b->at(j)->getName(), true);
            }

            out->put("Sobra: ")->put(binSize - b->getSize(), true);
            out->putNewLine();
        }
    }

    out->put("Tempo: ")
       ->put(ch.getResultTime(Chronometer::MICROSECONDS_UNITY))
       ->put(" ")
       ->put(ch.getUnitySymble(), true);

    while(!wl.empty()){
        Game *g = wl.back();
        wl.pop_back();
        delete g;
    }

	return 0;
}
