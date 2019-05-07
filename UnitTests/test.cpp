#include "pch.h"

TEST(Galutinis, GalutinisEquals/*((7+8+4+5+10)*0.4+9*0.6)*/) {
    StudentDerived A;
    vector<int> nd{ 7, 8, 4, 5, 10 };
    A.setNd(nd);
    A.setEgz(9);
    string GType = "v";
    A.setGal(A.galBalas(GType));
    EXPECT_EQ(A.galutinis(), 8.12);
}

TEST(Sorting, EachContainerHasOneObject) {
    vector<StudentDerived> ls, vargs;
    StudentDerived x;
    x.setGal(9.54);
    ls.push_back(x);
    x.setGal(1.11);
    ls.push_back(x);
    SortToGroups(ls, vargs);
    EXPECT_EQ(vargs.size(), 1);
    EXPECT_EQ(ls.size(), 1);
}

TEST(Generate, GeneratesRequiredAmount) {
    vector<StudentDerived> ls;
    string GType = "v";
    generate(10, GType, ls);
    EXPECT_EQ(ls.size(), 10);
}
