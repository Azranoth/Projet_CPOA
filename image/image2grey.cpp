#include "image2grey.h"

void Image2Grey::exportToPGM(){

    // Nom du fichier de sortie
    std::string fileToOpen;
    time_t now = time(0);
    tm *ltm = localtime(&now);
    char date_time[30];
    strftime(date_time, sizeof(date_time), "%d-%m-%y_%H:%M:%S.csv", ltm);
    fileToOpen = "PGM_";
    fileToOpen += date_time;
    fileToOpen += ".pgm";

    std::ofstream fileOut (fileToOpen.c_str(), std::ios::out);
    // Nombre magique PGM, dimensions de l'image & valeur maximale d'un pixel
    // Fichier PGM binaire -> valeurs comprises entre 0 et 255
    fileOut << "P5\n" << _w << " " << _h << "\n" << "255\n";

    // Valeur des pixels
    for(int i = 0; i < _w; i++){
        for(int j = 0; j < _h; j++){
            fileOut << (int)_imgData[i+j*_w] << " ";
        }
        fileOut << "\n";
    }
    fileOut.close();
}

void Image2Grey::importPGM(const std::string filename){

    std::ifstream infile(filename);
    std::stringstream ss;
    std::string inputLine = "";

    // Première ligne -> Version PGM du fichier
    std::getline(infile, inputLine);
    if(inputLine.compare("P5") != 0){
        std::cout << "PGM version error : Binary required (P5)" << std::endl;
        exit(1);
    }
    // Seconde ligne -> dimensions de l'image
    ss << infile.rdbuf();
    ss >> _w >> _h;
    int data[_w*_h];

    int max_value;
    ss >> max_value;

    std::cout << "max value : " << max_value << std::endl;

    std::cout << "import\n";
    for(int i = 0; i < _w*_h; i++){
        ss >> data[i];
        std::cout << data[i] << " ";
    }

    //Réinitialisation du tableau de pixels
    if(_imgData != nullptr){
        delete [] _imgData; _imgData = nullptr;
    }
    _imgData = new unsigned char[_w*_h];

    // Affectation des nouvelles valeurs aux pixels de l'image
    for(int i = 0; i < _w*_h; i++){
        setPixel(i, (unsigned int)data[i]);
    }
    infile.close();
}

Image2Grey Image2Grey::subSampling(){

    unsigned char *sampledData = new unsigned char[_w*_h/4];

    for(int i = 0; i < _w/2; i+=2){
        for(int j = 0; j < _h/2; j+=2){
            sampledData[i*_w+j] = _imgData[i*_w+j];
        }
    }

    Image2Grey subSampledImg = Image2Grey(_w/2, _h/2);
    return subSampledImg;
}

Image2Grey Image2Grey::threshold(const int val){
    Image2Grey outputImg = Image2Grey(_w, _h);
    for(int i = 0; i < _w; i++){
        for(int j = 0; j < _h; j++){
            if((int)(*this)(i,j) < val){
                outputImg.setPixel(i,j,0);
            }
            else{
                outputImg.setPixel(i,j,255);
            }
        }
    }
    return outputImg;
}



