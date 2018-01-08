#include <iostream>

#include "matrix33d.h"
// TESTS
#include <gmock/gmock.h>
#include <gtest/gtest.h>

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

int main(int argc, char *argv[])
{

    testing::InitGoogleTest(&argc, argv);
    setlocale(LC_CTYPE, "");
    return RUN_ALL_TESTS();

}
