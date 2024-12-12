#include "gtest/gtest.h"
#include "stud.h" 


// Testuoja funkcijos galutinisVidurkis skaièiavimo tikslumà
TEST(StudentasTest, GalutinisVidurkis) {
    vector<int> nd = { 8, 9, 10 };
    int egzaminas = 9;
    ASSERT_NEAR(Studentas::galutinisVidurkis(nd, egzaminas), 9, 0.01);
}

// Testuoja Studentas klasës konstruktoriaus veikimà
TEST(StudentasTest, SukurimoTestas) {
    Studentas s("Jonas", "Jonaitis", { 8, 9, 10 }, 9);
    EXPECT_EQ(s.getVardas(), "Jonas");
    EXPECT_EQ(s.getPavarde(), "Jonaitis");
    ASSERT_NEAR(s.getGalutinis(), 9, 0.01);
}


int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
