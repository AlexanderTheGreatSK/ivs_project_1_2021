//======== Copyright (c) 2021, FIT VUT Brno, All rights reserved. ============//
//
// Purpose:     White Box - Tests suite
//
// $NoKeywords: $ivs_project_1 $white_box_code.cpp
// $Author:     JMENO PRIJMENI <xlogin00@stud.fit.vutbr.cz>
// $Date:       $2021-01-04
//============================================================================//
/**
 * @file white_box_tests.cpp
 * @author JMENO PRIJMENI
 * 
 * @brief Implementace testu prace s maticemi.
 */

#include "gtest/gtest.h"
#include "white_box_code.h"

//============================================================================//
// ** ZDE DOPLNTE TESTY **
//
// Zde doplnte testy operaci nad maticemi. Cilem testovani je:
// 1. Dosahnout maximalniho pokryti kodu (white_box_code.cpp) testy.
// 2. Overit spravne chovani operaci nad maticemi v zavislosti na rozmerech 
//    matic.
//============================================================================//

class WhiteBoxTest : public ::testing::Test {

protected:
    //Matrix matrix;

    //----create-zero-matrix-----------------

    Matrix createZeroSquaredMatrix() {
        Matrix matrixTmp = Matrix(0,0);

        return matrixTmp;
    }

    Matrix createZeroRowMatrix() {
        Matrix matrixTmp = Matrix(0,5);

        return matrixTmp;
    }

    Matrix createZeroColMatrix() {
        Matrix matrixTmp = Matrix(5,0);

        return matrixTmp;
    }

    //----create-square-matrix-----------------

    Matrix createOneW0ValueSquaredMatrix() {
        Matrix matrixTmp = Matrix();

        return matrixTmp;
    }

    Matrix createOneSquaredMatrix() {
        Matrix matrixTmp = Matrix(1,1);

        matrixTmp.set(std::vector<std::vector<double>> {
                {5}
        });

        return matrixTmp;
    }

    Matrix createTreeSquaredMatrix() {
        Matrix matrixTmp = Matrix(3, 3);

        matrixTmp.set(std::vector<std::vector<double>> {
                {5,-4,3.14},
                {-8.16,15,0},
                {23.33,-259, -26},
        });

        return matrixTmp;
    }

    //----create-rectangle-matrix-----------------

    Matrix createRowVectorMatrix() {
        Matrix matrixTmp = Matrix(1,5);

        matrixTmp.set(std::vector<std::vector<double>> {
                {5,-4,3.14, -386.2, 0.2}
        });

        return matrixTmp;
    }

    Matrix createColVectorMatrix() {
        Matrix matrixTmp = Matrix(5,1);

        matrixTmp.set(std::vector<std::vector<double>>{
                {50},
                {-4.12},
                {3.14},
                {0},
                {0.2},
        });

        return matrixTmp;
    }

    Matrix create3x2Matrix() {
        Matrix matrixTmp = Matrix(3,2);

        matrixTmp.set(std::vector<std::vector<double>>{
                {5, -0.33},
                {-4, 0},
                {3.14, 3.14}
        });

        return matrixTmp;
    }

    Matrix create2x3Matrix() {
        Matrix matrixTmp = Matrix(2,3);

        matrixTmp.set(std::vector<std::vector<double>>{
                {5, -0.33, 0},
                {-4, 600, -354,58}
        });

        return matrixTmp;
    }

    //----get-1x1-0-matrix-value----------

    double getOneW0SquaredMatrixValue(int row, int col) { ///not needed

        Matrix matrixTmp = createOneW0ValueSquaredMatrix();

        return matrixTmp.get(row,col);
    }
};

    ///TEST-MATRIX-CONSTRUCTOR-------------

TEST_F(WhiteBoxTest, MatrixCreate) {

    ASSERT_NO_THROW(Matrix());

    ASSERT_NO_THROW(Matrix(1,1));
    ASSERT_NO_THROW(Matrix(2,3));
    ASSERT_NO_THROW(Matrix(3,2));


    ASSERT_ANY_THROW(Matrix(0,1));
    ASSERT_ANY_THROW(Matrix(0,0));
    ASSERT_ANY_THROW(Matrix(1,0));

}

TEST_F(WhiteBoxTest, SetMatrix1x1Values) {

    Matrix matrix = createOneSquaredMatrix();

    ASSERT_FALSE(matrix.set(1,1,4.2));
    ASSERT_FALSE(matrix.set(0,1,4.2));
    ASSERT_FALSE(matrix.set(1,0,4.2));

    ASSERT_TRUE(matrix.set(0,0,0.0));
    ASSERT_TRUE(matrix.set(0,0,-123.123));
    ASSERT_TRUE(matrix.set(0,0,5));

}

TEST_F(WhiteBoxTest, SetMatrix3x3Values) {

    Matrix matrix = createTreeSquaredMatrix();

    ASSERT_FALSE(matrix.set(3,3,4.2));
    ASSERT_FALSE(matrix.set(0,3,4.2));
    ASSERT_FALSE(matrix.set(3,0,4.2));

    ASSERT_TRUE(matrix.set(0,0,0.0));
    ASSERT_TRUE(matrix.set(2,2,-123.123));
    ASSERT_TRUE(matrix.set(0,2,5));
    ASSERT_TRUE(matrix.set(2,1,-5));

}

TEST_F(WhiteBoxTest, SetMatrixRowVectorValues) {

    Matrix matrix = createRowVectorMatrix();

    ASSERT_FALSE(matrix.set(1,1,4.2));
    ASSERT_FALSE(matrix.set(0,5,4.2));
    ASSERT_FALSE(matrix.set(5,5,4.2));

    ASSERT_TRUE(matrix.set(0,0,0.0));
    ASSERT_TRUE(matrix.set(0,2,-123.123));
    ASSERT_TRUE(matrix.set(0,3,5));
    ASSERT_TRUE(matrix.set(0,4,-5));

}

TEST_F(WhiteBoxTest, SetMatrixColVectorValues) {

    Matrix matrix = createColVectorMatrix();

    ASSERT_FALSE(matrix.set(1,1,4.2));
    ASSERT_FALSE(matrix.set(0,5,4.2));
    ASSERT_FALSE(matrix.set(5,1,4.2));
    ASSERT_FALSE(matrix.set(5,5,4.2));

    ASSERT_TRUE(matrix.set(0,0,0.0));
    ASSERT_TRUE(matrix.set(2,0,-123.123));
    ASSERT_TRUE(matrix.set(4,0,5));
    ASSERT_TRUE(matrix.set(1,0,-5));

}

TEST_F(WhiteBoxTest, SetMatrix3x2Values) {

    Matrix matrix = create3x2Matrix();

    ASSERT_FALSE(matrix.set(3,2,4.2));
    ASSERT_FALSE(matrix.set(0,5,4.2));
    ASSERT_FALSE(matrix.set(5,1,4.2));
    ASSERT_FALSE(matrix.set(5,5,4.2));

    ASSERT_TRUE(matrix.set(0,0,0.0));
    ASSERT_TRUE(matrix.set(1,1,-123.123));
    ASSERT_TRUE(matrix.set(2,1,5));
    ASSERT_TRUE(matrix.set(0,1,-5));

}

TEST_F(WhiteBoxTest, SetMatrix2x3Values) {

    Matrix matrix = create2x3Matrix();

    ASSERT_FALSE(matrix.set(2,3,4.2));
    ASSERT_FALSE(matrix.set(0,5,4.2));
    ASSERT_FALSE(matrix.set(5,1,4.2));
    ASSERT_FALSE(matrix.set(5,5,4.2));

    ASSERT_TRUE(matrix.set(0,0,0.0));
    ASSERT_TRUE(matrix.set(1,1,-123.123));
    ASSERT_TRUE(matrix.set(1,2,5));
    ASSERT_TRUE(matrix.set(0,2,-5));

}

    ///TESTOVANIE-GET--------------------------

TEST_F(WhiteBoxTest, GetMatrix1x1W0Values) {

    Matrix matrix = createOneW0ValueSquaredMatrix();

    ASSERT_DOUBLE_EQ(matrix.get(0,0),0);

    ASSERT_ANY_THROW(matrix.get(1,1));

}

TEST_F(WhiteBoxTest, GetMatrix1x1Values) {

    Matrix matrix = createOneSquaredMatrix();

    ASSERT_DOUBLE_EQ(matrix.get(0,0),5);

    ASSERT_ANY_THROW(matrix.get(1,1));
    ASSERT_ANY_THROW(matrix.get(0,1));
    ASSERT_ANY_THROW(matrix.get(1,0));

}


TEST_F(WhiteBoxTest, GetMatrix3x3Values) {

    Matrix matrix = createTreeSquaredMatrix();

    ASSERT_DOUBLE_EQ(matrix.get(0,0),5);
    ASSERT_DOUBLE_EQ(matrix.get(2,2),-26);
    ASSERT_DOUBLE_EQ(matrix.get(1,2),0);
    ASSERT_DOUBLE_EQ(matrix.get(2,0),23.33);

    ASSERT_ANY_THROW(matrix.get(3,3));
    ASSERT_ANY_THROW(matrix.get(0,3));
    ASSERT_ANY_THROW(matrix.get(3,0));

}

TEST_F(WhiteBoxTest, MatrixEqual) {

    Matrix matrixRowVector = createRowVectorMatrix();
    Matrix matricColVector = createColVectorMatrix();

    Matrix matrix3x3 = createTreeSquaredMatrix();

}

/*** Konec souboru white_box_tests.cpp ***/
