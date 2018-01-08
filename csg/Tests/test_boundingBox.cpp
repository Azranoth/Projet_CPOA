
// TESTS
#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include "boundingbox.h"
#include "CsgTree.h"



/* -------------BOUNDING BOX-------------*/

TEST(BoundingBoxTest, testCreate){
    double tab[2] = { 1.0, 1.0};
    Vec2f v1 = Vec2f(tab);
    double tab2[2] = { 3.0, 5.0};
    Vec2f v2 = Vec2f(tab2);

    BoundingBox box = BoundingBox(v1, v2);
    EXPECT_TRUE(v1 == box.getLeftBottom());
    EXPECT_TRUE(v2 == box.getRightTop());
}

TEST(BoundingBoxTest, testEq){
    double tab[2] = { 1.0, 1.0};
    Vec2f v1 = Vec2f(tab);
    double tab2[2] = { 3.0, 5.0};
    Vec2f v2 = Vec2f(tab2);
    BoundingBox box = BoundingBox(v1, v2);

    double tab_2[2] = { 1.0, 1.0};
    Vec2f v1_2 = Vec2f(tab_2);
    double tab2_2[2] = { 3.0, 5.0};
    Vec2f v2_2 = Vec2f(tab2_2);
    BoundingBox box2 = BoundingBox(v1_2, v2_2);

    EXPECT_TRUE(box == box2);
}

TEST(BoundingBoxTest, testEq2){
    double tab[2] = { 3.0, 1.0};
    Vec2f v1 = Vec2f(tab);
    double tab2[2] = { 3.0, 5.0};
    Vec2f v2 = Vec2f(tab2);
    BoundingBox box = BoundingBox(v1, v2);

    double tab_2[2] = { 5.0, 1.0};
    Vec2f v1_2 = Vec2f(tab_2);
    double tab2_2[2] = { 3.0, 1.0};
    Vec2f v2_2 = Vec2f(tab2_2);
    BoundingBox box2 = BoundingBox(v1_2, v2_2);

    EXPECT_FALSE(box == box2);
}

TEST(BoundingBoxTest, testUnion){
    double tab[2] = { 1.0, 1.0};
    Vec2f v1 = Vec2f(tab);
    double tab2[2] = { 3.0, 3.0};
    Vec2f v2 = Vec2f(tab2);
    BoundingBox box = BoundingBox(v1, v2);

    double tab_2[2] = { 2.0, 2.0};
    Vec2f v1_2 = Vec2f(tab_2);
    double tab2_2[2] = { 5.0, 4.0};
    Vec2f v2_2 = Vec2f(tab2_2);
    BoundingBox box2 = BoundingBox(v1_2, v2_2);

    BoundingBox res = box + box2;
    EXPECT_TRUE(v1 == res.getLeftBottom());
    EXPECT_TRUE(v2_2 == res.getRightTop());
}

TEST(BoundingBoxTest, testUnion2){
    double tab[2] = { 1.0, 1.0};
    Vec2f v1 = Vec2f(tab);
    double tab2[2] = { 7.0, 5.0};
    Vec2f v2 = Vec2f(tab2);
    BoundingBox box = BoundingBox(v1, v2);

    double tab_2[2] = { 2.0, 2.0};
    Vec2f v1_2 = Vec2f(tab_2);
    double tab2_2[2] = { 5.0, 4.0};
    Vec2f v2_2 = Vec2f(tab2_2);
    BoundingBox box2 = BoundingBox(v1_2, v2_2);

    BoundingBox res = box + box2;
    EXPECT_TRUE(box == res);
}

TEST(BoundingBoxTest, testUnion3){
    double tab[2] = { 3.0, 2.0};
    Vec2f v1 = Vec2f(tab);
    double tab2[2] = { 7.0, 5.0};
    Vec2f v2 = Vec2f(tab2);
    BoundingBox box = BoundingBox(v1, v2);

    double tab_2[2] = { 2.0, 1.0};
    Vec2f v1_2 = Vec2f(tab_2);
    double tab2_2[2] = { 8.0, 4.0};
    Vec2f v2_2 = Vec2f(tab2_2);
    BoundingBox box2 = BoundingBox(v1_2, v2_2);

    BoundingBox res = box + box2;
    EXPECT_TRUE(res.getLeftBottom()==v1_2);
    EXPECT_TRUE(res.getRightTop()[0] == 8.0);
    EXPECT_TRUE(res.getRightTop()[1] == 5.0);
}

TEST(BoundingBoxTest, testInter){
    double tab[2] = { 1.0, 1.0};
    Vec2f v1 = Vec2f(tab);
    double tab2[2] = { 3.0, 3.0};
    Vec2f v2 = Vec2f(tab2);
    BoundingBox box = BoundingBox(v1, v2);

    double tab_2[2] = { 2.0, 2.0};
    Vec2f v1_2 = Vec2f(tab_2);
    double tab2_2[2] = { 5.0, 4.0};
    Vec2f v2_2 = Vec2f(tab2_2);
    BoundingBox box2 = BoundingBox(v1_2, v2_2);

    BoundingBox res = box ^ box2;
    //std::cout << "VALS INTER\n" << res.getLeftBottom()[0] << " " << res.getLeftBottom()[1] << std::endl << res.getRightTop()[0] << " " << res.getRightTop()[1] << std::endl;
    EXPECT_TRUE(res.getLeftBottom() == box2.getLeftBottom());
    EXPECT_TRUE(res.getRightTop() == box.getRightTop());
}

TEST(BoundingBoxTest, testInter2){
    double tab[2] = { 1.0, 1.0};
    Vec2f v1 = Vec2f(tab);
    double tab2[2] = { 3.0, 3.0};
    Vec2f v2 = Vec2f(tab2);
    BoundingBox box = BoundingBox(v1, v2);

    double tab_2[2] = { 4.0, 5.0};
    Vec2f v1_2 = Vec2f(tab_2);
    double tab2_2[2] = { 7.0, 6.0};
    Vec2f v2_2 = Vec2f(tab2_2);
    BoundingBox box2 = BoundingBox(v1_2, v2_2);

    BoundingBox res = box ^ box2;
    //std::cout << "VALS INTER\n" << res.getLeftBottom()[0] << " " << res.getLeftBottom()[1] << std::endl << res.getRightTop()[0] << " " << res.getRightTop()[1] << std::endl;
    EXPECT_TRUE(res.getLeftBottom()[0] == 0.0);
    EXPECT_TRUE(res.getLeftBottom()[1] == 0.0);
    EXPECT_TRUE(res.getRightTop()[0] == 0.0);
    EXPECT_TRUE(res.getRightTop()[1] == 0.0);
}

TEST(BoundingBoxTest, testInter3){
    double tab[2] = { 4.0, 0.0};
    Vec2f v1 = Vec2f(tab);
    double tab2[2] = { 5.0, 8.0};
    Vec2f v2 = Vec2f(tab2);
    BoundingBox box = BoundingBox(v1, v2);

    double tab_2[2] = { 2.0, 1.0};
    Vec2f v1_2 = Vec2f(tab_2);
    double tab2_2[2] = { 8.0, 4.0};
    Vec2f v2_2 = Vec2f(tab2_2);
    BoundingBox box2 = BoundingBox(v1_2, v2_2);

    BoundingBox res = box ^ box2;
    //std::cout << "VALS INTER\n" << res.getLeftBottom()[0] << " " << res.getLeftBottom()[1] << std::endl << res.getRightTop()[0] << " " << res.getRightTop()[1] << std::endl;
    EXPECT_TRUE(res.getLeftBottom()[0] == 4.0);
    EXPECT_TRUE(res.getLeftBottom()[1] == 1.0);
    EXPECT_TRUE(res.getRightTop()[0] == 5.0);
    EXPECT_TRUE(res.getRightTop()[1] == 4.0);
}

TEST(BoundingBoxTest, testPtInside){
    double tab[2] = { 4.0, 0.0};
    Vec2f v1 = Vec2f(tab);
    double tab2[2] = { 5.0, 8.0};
    Vec2f v2 = Vec2f(tab2);
    BoundingBox box = BoundingBox(v1, v2);

    double tab_pt[2] = {1.0, 3.0};
    double tab_pt2[2] = {4.5, 3.0};
    Vec2f pt1 = Vec2f(tab_pt);
    Vec2f pt2 = Vec2f(tab_pt2);

    EXPECT_FALSE(box.isPointInside(pt1));
    EXPECT_TRUE(box.isPointInside(pt2));
}

TEST(BoundingBoxTest, testBoxInside){
    double tab[2] = { 4.0, 0.0};
    Vec2f v1 = Vec2f(tab);
    double tab2[2] = { 5.0, 8.0};
    Vec2f v2 = Vec2f(tab2);
    BoundingBox box = BoundingBox(v1, v2);

    double tab_2[2] = { 2.0, 1.0};
    Vec2f v1_2 = Vec2f(tab_2);
    double tab2_2[2] = { 8.0, 4.0};
    Vec2f v2_2 = Vec2f(tab2_2);
    BoundingBox box2 = BoundingBox(v1_2, v2_2);

    EXPECT_FALSE(box.isBoxIncluded(box2));
}

TEST(BoundingBoxTest, testBoxInside2){
    double tab[2] = { 4.0, 0.0};
    Vec2f v1 = Vec2f(tab);
    double tab2[2] = { 12.0, 8.0};
    Vec2f v2 = Vec2f(tab2);
    BoundingBox box = BoundingBox(v1, v2);

    double tab_2[2] = { 6.0, 1.0};
    Vec2f v1_2 = Vec2f(tab_2);
    double tab2_2[2] = { 8.0, 4.0};
    Vec2f v2_2 = Vec2f(tab2_2);
    BoundingBox box2 = BoundingBox(v1_2, v2_2);

    EXPECT_TRUE(box.isBoxIncluded(box2));
}

TEST(BoundingBoxTest, testAddPoint){
    double tab[2] = { 4.0, 2.0};
    Vec2f v1 = Vec2f(tab);
    double tab2[2] = { 5.0, 8.0};
    Vec2f v2 = Vec2f(tab2);
    BoundingBox box = BoundingBox(v1, v2);

    double tab_pt[2] = { 1.0, 3.0 };
    Vec2f pt = Vec2f(tab_pt);

    box.addPoint(pt);
    EXPECT_TRUE(box.getLeftBottom()[0] == pt[0]);
    EXPECT_TRUE(box.getLeftBottom()[1] == v1[1]);
    EXPECT_TRUE(box.getRightTop()[0] == v2[0]);
    EXPECT_TRUE(box.getRightTop()[1] == v2[1]);

    double tab_pt2[2] = { 10.0, 9.0 };
    Vec2f pt2 = Vec2f(tab_pt2);

    box.addPoint(pt2);
    EXPECT_TRUE(box.getLeftBottom()[0] == pt[0]);
    EXPECT_TRUE(box.getLeftBottom()[1] == v1[1]);
    EXPECT_TRUE(box.getRightTop()[0] == pt2[0]);
    EXPECT_TRUE(box.getRightTop()[1] == pt2[1]);
}

TEST(BoundingBoxTest, testDifference){
    double tab[2] = { 2.0, 1.0};
    Vec2f v1 = Vec2f(tab);
    double tab2[2] = { 8.0, 4.0};
    Vec2f v2 = Vec2f(tab2);
    BoundingBox box = BoundingBox(v1, v2);

    double tab_2[2] = { 2.0, 2.0};
    Vec2f v1_2 = Vec2f(tab_2);
    double tab2_2[2] = { 6.0, 3.0};
    Vec2f v2_2 = Vec2f(tab2_2);
    BoundingBox box2 = BoundingBox(v1_2, v2_2);

    BoundingBox res = box - box2;
    //std::cout << "VALS DIFF\n" << res.getLeftBottom()[0] << " " << res.getLeftBottom()[1] << std::endl << res.getRightTop()[0] << " " << res.getRightTop()[1] << std::endl;
    EXPECT_TRUE(res.getLeftBottom()[0] == 6.0);
    EXPECT_TRUE(res.getLeftBottom()[1] == 1.0);
    EXPECT_TRUE(res.getRightTop()[0] == 8.0);
    EXPECT_TRUE(res.getRightTop()[1] == 4.0);
}


/*--------- CSG ----------*/

TEST(CsgTest, testCreationOperation){
/*
    CsgPrimitive p1 = CsgPrimitive();
    EXPECT_TRUE(p1.getId() == 1);
    EXPECT_TRUE(p1.getParent() == nullptr);

    CsgPrimitive p2 = CsgPrimitive();
    EXPECT_TRUE(p2.getId() == 2);

    CsgOperation op1 = CsgOperation(Union, nullptr, &p1, &p2);
    EXPECT_TRUE(op1.getId() == 3);
    EXPECT_TRUE(p1.getParent() == &op1);
    EXPECT_TRUE(p2.getParent() == &op1);*/
}

TEST(CsgTest, testCreationPrimitives){

    CsgPolygon p1 = CsgPolygon();
    EXPECT_TRUE(p1.getId() == 1);
    EXPECT_TRUE(p1.getVerticesNumber() == 3);
    EXPECT_TRUE(p1.getParent() == nullptr);

    double coords[2] = {1,1};
    Vec2f center = Vec2f(coords);
    CsgPolygon p2 = CsgPolygon(nullptr, center, Matrix33d::identity(), 5);
    EXPECT_TRUE(p2.getId() == 2);

    CsgOperation op1 = CsgOperation(Intersection, nullptr, &p1, &p2);
    EXPECT_TRUE(op1.getId() == 3);
    EXPECT_TRUE(p1.getParent() == &op1);
    EXPECT_TRUE(p2.getParent() == &op1);

    CsgDisk d1 = CsgDisk();
    CsgOperation op2 = CsgOperation(Intersection, nullptr, &d1, &op1);
    EXPECT_TRUE(d1.getId() == 4);
    EXPECT_TRUE(op2.getId() == 5);
    EXPECT_TRUE(op1.getParent() == &op2);

}

TEST(CsgTest, testCreationPrimitives2){

    CsgTree tree = CsgTree();
    CsgPolygon p1 = CsgPolygon();
    EXPECT_TRUE(p1.getId() == 6);
    EXPECT_TRUE(p1.getVerticesNumber() == 3);
    EXPECT_TRUE(p1.getParent() == nullptr);
    tree.addPrimitive(&p1);

    double coords[2] = {1,1};
    Vec2f center = Vec2f(coords);
    CsgPolygon p2 = CsgPolygon(nullptr, center, Matrix33d::identity(), 5);
    EXPECT_TRUE(p2.getId() == 7);
    tree.addPrimitive(&p2);
    tree.joinPrimitive(Intersection, &p1, &p2);
    CsgDisk d1 = CsgDisk();
    EXPECT_TRUE(d1.getId() == 9);
    tree.addPrimitive(&d1);
    EXPECT_TRUE(tree.searchNode(9) == &d1);
    std::cout << tree.getLeafs().size() << std::endl;
}



int main(int argc, char* argv[]){

    testing::InitGoogleTest(&argc, argv);
    setlocale(LC_CTYPE, "");
    return RUN_ALL_TESTS();



}
