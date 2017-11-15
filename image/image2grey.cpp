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
    fileOut << "P2\n" << _w << " " << _h << "\n" << "255\n";

    // Valeur des pixels
    for(int i = 0; i < _w; i++){
        for(int j = 0; j < _h; j++){
            fileOut << (int)_imgData[i*_w+j] << " ";
        }
        fileOut << "\n";
    }
    fileOut.close();
}


void Image2Grey::importPGM(const std::string filename){

    std::ifstream is;
    is.open(filename);

    // Récupération de la taille du fichier
    is.seekg(0, is.end);
    int length = is.tellg();
    is.seekg(0, is.beg);

    char* buffer = new char[length];
    // Remplissage du buffer
    is.read(buffer, length);
    is.close();

    std::stringstream stream;
    stream.str(buffer);
    delete[] buffer;

    std::string str;
    std::getline(stream, str);
    if (str != "P2") {
        std::cerr << "Bad magic number : " << str << std::endl;
        exit(1);
    }

    // Ignorer les commenaires
    std::getline(stream, str);
    while (str[0] == '#') {
        std::getline(stream, str);
    }

    // Récupération des dimensions de l'image dans _w et _h
    std::stringstream ss;
    ss.str(str);
    ss >> _w;
    ss >> _h;

    // Réinitialisation du tableau de pixels
    if (_imgData != nullptr) {
        delete[] _imgData, _imgData = nullptr;
    }
    _imgData = new unsigned char[_w*_h];

    // Ignorer les commentaires
    std::getline(stream, str);
    while (str[0] == '#') {
        std::getline(stream, str);
    }

    ss.str(str);
    ss.seekg(0, ss.beg);

    int max_value;
    ss >> max_value;
    float f = 255/(float)max_value;

    // Ignorer les commentaires
    while (stream.str()[stream.tellg()] == '#') {
        std::getline(stream, str);
    }

    // Affectation des nouvelles valeurs
    unsigned int v1, v2;

    for (int i=0; i < (int)_h; i++) {
        for (int j=0; j < (int)_w; j++) {
            stream >> v1;
            v2 = (unsigned int) (f*v1);
            _imgData[j + i*_w] = v2;
        }
    }
}


Image2Grey Image2Grey::subSampling(){

    Image2Grey subSampledImg = Image2Grey(_w/2, _h/2);

    for(int i = 0; i < _w; i+=2){
        for(int j = 0; j < _h; j+=2){
            subSampledImg.setPixel(i/2, j/2, (*this)(i,j));
        }
    }


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

Image2Grey Image2Grey::blur(const unsigned char m){
    Image2Grey blurImg = Image2Grey(_w,_h);

    for(int j=1; j < _h-1; j++){
        for(int i=1; i <_w-1; i++){
            unsigned char v = 0;
            unsigned char p = (int)m;
            for(int l=-1; l < 2; l++){
                for(int k=-1; k < 2; k++)
                    v += (*this)(i+k,j+l)*(p++);
            }
            blurImg.setPixel(i,j,v);
        }
    }


    for(int j=0;j<_h;j++){
        blurImg.setPixel(0,j,(*this)(0,j));
        blurImg.setPixel(_w-1,j,(*this)(_w-1,j));
    }

    for(int i=0;i<_w;i++){
        blurImg.setPixel(i,0,(*this)(i,0));
        blurImg.setPixel(i,_h-1,(*this)(i,_h-1));
    }

    return blurImg;

}



