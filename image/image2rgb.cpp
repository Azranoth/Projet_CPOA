#include "image2rgb.h"

void Image2RGB::exportToPPM(){

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
    // Nombre magique PPM, dimensions de l'image & valeur maximale d'un pixel
    // Fichier PPM ASCII -> P3
    fileOut << "P3\n" << _w << " " << _h << "\n" << "255\n";

    // Valeur des pixels
    for(int i = 0; i < _w; i++){
        for(int j = 0; j < _h; j++){
            fileOut << (int)_imgData[i*_w+j][0] << " " << (int)_imgData[i*_w+j][1] << " " << (int)_imgData[i*_w+j][2] << " ";
        }
        fileOut << "\n";
    }
    fileOut.close();
}


void Image2RGB::importPPM(const std::string filename){

    std::ifstream is;
    is.open(filename);

    // Récupération de la taille du fichier
    is.seekg(0, is.end);
    int length = is.tellg();
    is.seekg(0, is.beg);
    std::cout << "prout" << std::endl;
    char* buffer = new char[length];
    // Remplissage du buffer
    is.read(buffer, length);
    is.close();

    std::stringstream stream;
    stream.str(buffer);
    delete[] buffer;

    std::string str;
    std::getline(stream, str);
    if (str != "P3") {
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
    std::cout << "prout" << std::endl;
    // Réinitialisation du tableau de pixels
    if (_imgData != nullptr) {
        delete[] _imgData, _imgData = nullptr;
    }
    _imgData = new Vec3uc[_w*_h];
    std::cout << "prout" << std::endl;
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
            _imgData[j + i*_w][0] = v2;

            stream >> v1;
            v2 = (unsigned int) (f*v1);
            _imgData[j + i*_w][1] = v2;

            stream >> v1;
            v2 = (unsigned int) (f*v1);
            _imgData[j + i*_w][2] = v2;
        }
    }

    std::cout << "prout" << std::endl;
}
