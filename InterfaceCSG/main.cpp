#include <QApplication>
#include "mainwindow.h"

/*----------IMAGE-----------*/

TEST(ImgTest, testCreate){
    int *input = new int[25];
    input[0] = 1; input[1] = 2; input[2] = 3; input[3] = 4; input[4] = 5;
    input[5] = 2; input[6] = 3; input[7] = 4; input[8] = 5; input[9] = 6;
    input[10] = 3; input[11] = 4; input[12] = 5; input[13] = 6; input[14] = 7;
    input[15] = 4; input[16] = 5; input[17] = 6; input[18] = 7; input[19] = 8;
    input[20] = 5; input[21] = 6; input[22] = 7; input[23] = 8; input[24] = 9;
    Image2D<int> img = Image2D<int>(5,5,input);

    EXPECT_TRUE(img(0,0) == input[0]);
    EXPECT_TRUE(img(1,0) == input[1]);
    EXPECT_TRUE(img(2,0) == input[2]);
    EXPECT_TRUE(img(3,0) == input[3]);
    EXPECT_TRUE(img(4,0) == input[4]);

    EXPECT_TRUE(img(0,1) == input[5]);
    EXPECT_TRUE(img(1,1) == input[6]);
    EXPECT_TRUE(img(2,1) == input[7]);
    EXPECT_TRUE(img(3,1) == input[8]);
    EXPECT_TRUE(img(4,1) == input[9]);

    EXPECT_TRUE(img(0,2) == input[10]);
    EXPECT_TRUE(img(1,2) == input[11]);
    EXPECT_TRUE(img(2,2) == input[12]);
    EXPECT_TRUE(img(3,2) == input[13]);
    EXPECT_TRUE(img(4,2) == input[14]);

    EXPECT_TRUE(img(0,3) == input[15]);
    EXPECT_TRUE(img(1,3) == input[16]);
    EXPECT_TRUE(img(2,3) == input[17]);
    EXPECT_TRUE(img(3,3) == input[18]);
    EXPECT_TRUE(img(4,3) == input[19]);

    EXPECT_TRUE(img(0,4) == input[20]);
    EXPECT_TRUE(img(1,4) == input[21]);
    EXPECT_TRUE(img(2,4) == input[22]);
    EXPECT_TRUE(img(3,4) == input[23]);
    EXPECT_TRUE(img(4,4) == input[24]);
}





int main(int argc, char *argv[]){

/*
    testing::InitGoogleTest(&argc, argv);
    setlocale(LC_CTYPE, "");
    return RUN_ALL_TESTS();
*/

    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    /*------- TESTS D'EXECUTION DES CLASSES Image2D, Image2Grey & Image2RGB ------*/

    // Voir les fichiers exportés dans le répertoire InterfaceCSG du répertoire de build du projet //


    unsigned char *input = new unsigned char[25];
    input[0] = 1; input[1] = 2; input[2] = 3; input[3] = 4; input[4] = 5;
    input[5] = 2; input[6] = 3; input[7] = 4; input[8] = 5; input[9] = 6;
    input[10] = 3; input[11] = 4; input[12] = 5; input[13] = 6; input[14] = 7;
    input[15] = 4; input[16] = 5; input[17] = 6; input[18] = 7; input[19] = 8;
    input[20] = 5; input[21] = 6; input[22] = 7; input[23] = 8; input[24] = 9;

    Image2Grey img = Image2Grey(5,5,input);
    img.exportToPGM();

    Image2Grey imgS = Image2Grey(5,5);
    //imgS.importPGM("../../ProjCPOA_Init/gs.pgm");
    imgS.importPGM("gs.pgm");
    Image2Grey imgS2 = imgS.subSampling();
    imgS2.exportToPGM();

    Image2Grey imgT = Image2Grey(5,5);
    //imgT.importPGM("../../ProjCPOA_Init/gs.pgm");
    imgT.importPGM("gs.pgm");
    Image2Grey imgT2 = imgT.threshold(50);
    imgT2.exportToPGM();

    Image2Grey imgB = Image2Grey(5,5);
    //imgB.importPGM("../../ProjCPOA_Init/gs.pgm");
    imgB.importPGM("gs.pgm");
    unsigned char m = 2;
    Image2Grey imgB2 = imgB.blur(m);
    imgB2.exportToPGM();

    /*
    // Crash std::bad_alloc()
    Image2RGB imgI = Image2RGB(5,5);
    //imgI.importPPM("../../ProjCPOA_Init/paquerette.ppm");
    imgI.importPPM("paquerette.ppm");
    imgI.exportToPPM();
*/

    return a.exec();
}


