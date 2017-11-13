#include <QApplication>
#include "mainwindow.h"

/*-----------------------------------------------*/
/*------------------JEU DE TESTS-----------------*/
/*-----------------------------------------------*/

/*-------VECTEURS--------*/
TEST(VecTest, testEq){
    int tab[3] = {2,5,1};
    Vec3i v1 = Vec3i(tab);
    Array<int,3> array = Array<int,3>(); array[0] = 2; array[1] = 5; array[2] = 1;
    Vec3i v2 = Vec3i(array);
    EXPECT_TRUE(v1==v2);
    EXPECT_TRUE(v2==v1);

    Vec3i v3 = Vec3i();
    EXPECT_FALSE(v1==v3);
}

TEST(VecTest, testEqFloat){
    double tab[3] = {2.0, 5.0, 1.0};
    Vec3f v1 = Vec3f(tab);
    Array<double,3> array = Array<double,3>(); array[0] = 2.0; array[1] = 5.0; array[2] = 1.0;
    Vec3f v2 = Vec3f(array);
    EXPECT_TRUE(v1==v2);
    EXPECT_TRUE(v2==v1);

    Vec3f v3 = Vec3f();
    EXPECT_FALSE(v1==v3);
}


TEST(VecTest, testAdd){
    int tab[3] = {6,3,7};
    Vec3i v1 = Vec3i(tab);
    Array<int,3> array = Array<int,3>(); array[0] = 2; array[1] = 5; array[2] = 1;
    Vec3i v2 = Vec3i(array);
    Vec3i v_add = v1+v2;

    EXPECT_TRUE(v_add[0] == 8);
    EXPECT_TRUE(v_add[1] == 8);
    EXPECT_TRUE(v_add[2] == 8);
}

TEST(VecTest, testAddEqual){
    int tab[3] = {6,3,7};
    Vec3i v1 = Vec3i(tab);
    Array<int,3> array = Array<int,3>(); array[0] = 2; array[1] = 5; array[2] = 1;
    Vec3i v2 = Vec3i(array);
    v1 += v2;

    EXPECT_TRUE(v1[0] == 8);
    EXPECT_TRUE(v1[1] == 8);
    EXPECT_TRUE(v1[2] == 8);
}

TEST(VecTest, testSub){
    int tab[3] = {8,8,8};
    Vec3i v1 = Vec3i(tab);
    Array<int,3> array = Array<int,3>(); array[0] = 2; array[1] = 5; array[2] = 1;
    Vec3i v2 = Vec3i(array);
    Vec3i v_sub = v1-v2;

    EXPECT_TRUE(v_sub[0] == 6);
    EXPECT_TRUE(v_sub[1] == 3);
    EXPECT_TRUE(v_sub[2] == 7);
}

TEST(VecTest, testSubEqual){
    int tab[3] = {8,8,8};
    Vec3i v1 = Vec3i(tab);
    Array<int,3> array = Array<int,3>(); array[0] = 2; array[1] = 5; array[2] = 1;
    Vec3i v2 = Vec3i(array);
    v1 -= v2;

    EXPECT_TRUE(v1[0] == 6);
    EXPECT_TRUE(v1[1] == 3);
    EXPECT_TRUE(v1[2] == 7);
}

TEST(VecTest, testDot){
    int tab[3] = {1, 2, 3};
    Vec3i v1 = Vec3i(tab);
    Array<int,3> array = Array<int,3>(); array[0] = 2; array[1] = 5; array[2] = 3;
    Vec3i v2 = Vec3i(array);
    int dot_sum = v1.dot(v2);

    EXPECT_TRUE(dot_sum==21);
}

TEST(VecTest, testMultScal){
    Array<int,3> array = Array<int,3>(); array[0] = 2; array[1] = 5; array[2] = 3;
    Vec3i v2 = Vec3i(array);
    float f = 3.0f;
    Vec3i vec_mult = v2*f;

    EXPECT_TRUE(vec_mult[0]==6);
    EXPECT_TRUE(vec_mult[1]==15);
    EXPECT_TRUE(vec_mult[2]==9);
}

TEST(VecTest, testMultScal2){
    Array<int,3> array = Array<int,3>(); array[0] = 2; array[1] = 5; array[2] = 3;
    Vec3i v2 = Vec3i(array);
    float f = 3.0f;
    Vec3i vec_mult = f*v2;

    EXPECT_TRUE(vec_mult[0]==6);
    EXPECT_TRUE(vec_mult[1]==15);
    EXPECT_TRUE(vec_mult[2]==9);
}

TEST(VecTest, testCross){
    int tab[3] = {1, 2, 3};
    Vec3i v1 = Vec3i(tab);
    Array<int,3> array = Array<int,3>(); array[0] = 2; array[1] = 5; array[2] = 3;
    Vec3i v2 = Vec3i(array);
    Vec3i v_cross = v1.cross(v2);

    EXPECT_TRUE(v_cross[0] == -9);
    EXPECT_TRUE(v_cross[1] == 3);
    EXPECT_TRUE(v_cross[2] == 1);

}

/*-----------------------*/


/*-------MATRICES--------*/

TEST(MatTest, testEq){
    double tab[3][3] = { {1.0, 3.0, 2.0}, {-3.0, -3.0, 2.0}, {0.0, 1.0, 4.0} };
    Array<double,3> array[3];
    array[0][0] = 1.0; array[0][1] = 3.0; array[0][2] = 2.0;
    array[1][0] = -3.0; array[1][1] = -3.0; array[1][2] = 2.0;
    array[2][0] = 0.0; array[2][1] = 1.0; array[2][2] = 4.0;

    Matrix33d mat1 = Matrix33d(tab);
    Matrix33d mat2 = Matrix33d(array);

    std::cout << mat1[0][0] << " " << mat2[0][0];

    EXPECT_TRUE(mat1[0][0] == mat2[0][0]);
    EXPECT_TRUE(mat1[0][1] == mat2[0][1]);
    EXPECT_TRUE(mat1[0][2] == mat2[0][2]);
    EXPECT_TRUE(mat1[1][0] == mat2[1][0]);
    EXPECT_TRUE(mat1[1][1] == mat2[1][1]);
    EXPECT_TRUE(mat1[1][2] == mat2[1][2]);
    EXPECT_TRUE(mat1[2][0] == mat2[2][0]);
    EXPECT_TRUE(mat1[2][1] == mat2[2][1]);
    EXPECT_TRUE(mat1[2][2] == mat2[2][2]);
}

TEST(MatTest, testInversion){

    double tab[3][3] = { {-1.0, 2.0, 5.0} , {1.0, 2.0, 3.0} , {-2.0, 8.0, 10.0} };
    Matrix33d mat1 = Matrix33d(tab);
    Matrix33d mat2 = mat1.inversion();

    EXPECT_DOUBLE_EQ(mat2[0][0], -0.125);
    EXPECT_DOUBLE_EQ(mat2[0][1], 0.625);
    EXPECT_DOUBLE_EQ(mat2[0][2], -0.125);
    EXPECT_DOUBLE_EQ(mat2[1][0], -0.5);
    EXPECT_DOUBLE_EQ(mat2[1][1], 0.0);
    EXPECT_DOUBLE_EQ(mat2[1][2], 0.25);
    EXPECT_DOUBLE_EQ(mat2[2][0], 0.375);
    EXPECT_DOUBLE_EQ(mat2[2][1], 0.125);
    EXPECT_DOUBLE_EQ(mat2[2][2], -0.125);
}

TEST(MatTest, testSetTranslation){

    Matrix33d mat1;
    Matrix33d::setTranslation(mat1, 5.0, 3.0);

    EXPECT_DOUBLE_EQ(mat1[0][0], 1.0);
    EXPECT_DOUBLE_EQ(mat1[0][1], 0.0);
    EXPECT_DOUBLE_EQ(mat1[0][2], 5.0);
    EXPECT_DOUBLE_EQ(mat1[1][0], 0.0);
    EXPECT_DOUBLE_EQ(mat1[1][1], 1.0);
    EXPECT_DOUBLE_EQ(mat1[1][2], 3.0);
    EXPECT_DOUBLE_EQ(mat1[2][0], 0.0);
    EXPECT_DOUBLE_EQ(mat1[2][1], 0.0);
    EXPECT_DOUBLE_EQ(mat1[2][2], 1.0);
}

TEST(MatTest, testSetRotation){

    Matrix33d mat1;
    Matrix33d::setRotation(mat1, 5.0);

    EXPECT_DOUBLE_EQ(mat1[0][0], cos(5.0));
    EXPECT_DOUBLE_EQ(mat1[0][1], -sin(5.0));
    EXPECT_DOUBLE_EQ(mat1[0][2], 0.0);
    EXPECT_DOUBLE_EQ(mat1[1][0], sin(5.0));
    EXPECT_DOUBLE_EQ(mat1[1][1], cos(5.0));
    EXPECT_DOUBLE_EQ(mat1[1][2], 0.0);
    EXPECT_DOUBLE_EQ(mat1[2][0], 0.0);
    EXPECT_DOUBLE_EQ(mat1[2][1], 0.0);
    EXPECT_DOUBLE_EQ(mat1[2][2], 1.0);
}

TEST(MatTest, testSetScaling){

    Matrix33d mat1;
    Matrix33d::setScaling(mat1, 5.0);

    EXPECT_DOUBLE_EQ(mat1[0][0], 5.0);
    EXPECT_DOUBLE_EQ(mat1[0][1], 0.0);
    EXPECT_DOUBLE_EQ(mat1[0][2], 0.0);
    EXPECT_DOUBLE_EQ(mat1[1][0], 0.0);
    EXPECT_DOUBLE_EQ(mat1[1][1], 5.0);
    EXPECT_DOUBLE_EQ(mat1[1][2], 0.0);
    EXPECT_DOUBLE_EQ(mat1[2][0], 0.0);
    EXPECT_DOUBLE_EQ(mat1[2][1], 0.0);
    EXPECT_DOUBLE_EQ(mat1[2][2], 5.0);
}

TEST(MatTest, testApplyTransform){

    Matrix33d mat1;
    Matrix33d::setTranslation(mat1, 5.0, 3.0);
    Matrix33d mat2;
    Matrix33d::setScaling(mat2, 4.0);
    Matrix33d::applyTransformation(mat1, mat2);

    EXPECT_DOUBLE_EQ(mat1[0][0], 4.0);
    EXPECT_DOUBLE_EQ(mat1[0][1], 0.0);
    EXPECT_DOUBLE_EQ(mat1[0][2], 20.0);
    EXPECT_DOUBLE_EQ(mat1[1][0], 0.0);
    EXPECT_DOUBLE_EQ(mat1[1][1], 4.0);
    EXPECT_DOUBLE_EQ(mat1[1][2], 12.0);
    EXPECT_DOUBLE_EQ(mat1[2][0], 0.0);
    EXPECT_DOUBLE_EQ(mat1[2][1], 0.0);
    EXPECT_DOUBLE_EQ(mat1[2][2], 4.0);
}

/*--------------------------*/

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

    testing::InitGoogleTest(&argc, argv);
    setlocale(LC_CTYPE, "");
    //return RUN_ALL_TESTS();

    QApplication a(argc, argv);
    MainWindow w;
    w.show();

/*
    int tab[3] = {2,5,1};
    Vec3i v1 = Vec3i(tab);
    Array<int,3> array = Array<int,3>(); array[0] = 2; array[1] = 5; array[2] = 1;
    Vec3i v2 = Vec3i(array);
    v1.display();
    v2.display();

    double tab[3][3] = { {1.0, 3.0, 2.0}, {-3.0, -3.0, 2.0}, {0.0, 1.0, 4.0} };
    Array<double,3> array[3];
    array[0] = Array<double,3>(tab[0]); array[1] = Array<double,3>(tab[1]); array[2] = Array<double,3>(tab[2]);
    array[0][0] = 1.0; array[0][1] = 3.0; array[0][2] = 2.0;
    array[1][0] = -3.0; array[1][1] = -3.0; array[1][2] = 2.0;
    array[2][0] = 0.0; array[2][1] = 1.0; array[2][2] = 4.0;
    Matrix33d mat1 = Matrix33d(tab);
    Matrix33d mat2 = Matrix33d(array);
*/

    unsigned char *input = new unsigned char[25];
    input[0] = 1; input[1] = 2; input[2] = 3; input[3] = 4; input[4] = 5;
    input[5] = 2; input[6] = 3; input[7] = 4; input[8] = 5; input[9] = 6;
    input[10] = 3; input[11] = 4; input[12] = 5; input[13] = 6; input[14] = 7;
    input[15] = 4; input[16] = 5; input[17] = 6; input[18] = 7; input[19] = 8;
    input[20] = 5; input[21] = 6; input[22] = 7; input[23] = 8; input[24] = 9;
    Image2Grey img = Image2Grey(5,5,input);
    img.exportToPGM();

    return a.exec();
}
