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





int main(int argc, char *argv[]){

    testing::InitGoogleTest(&argc, argv);
    setlocale(LC_CTYPE, "");
    return RUN_ALL_TESTS();

    QApplication a(argc, argv);
    MainWindow w;
    w.show();


    int tab[3] = {2,5,1};
    Vec3i v1 = Vec3i(tab);
    Array<int,3> array = Array<int,3>(); array[0] = 2; array[1] = 5; array[2] = 1;
    Vec3i v2 = Vec3i(array);
    v1.display();
    v2.display();





    return a.exec();
}
