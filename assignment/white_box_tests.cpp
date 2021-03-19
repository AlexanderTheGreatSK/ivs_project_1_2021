//======== Copyright (c) 2021, FIT VUT Brno, All rights reserved. ============//
//
// Purpose:     White Box - Tests suite
//
// $NoKeywords: $ivs_project_1 $white_box_code.cpp
// $Author:     ALEXANDER OKRUCKÝ <xokruc00@stud.fit.vutbr.cz>
// $Date:       $2021-03-17
//============================================================================//
/**
 * @file white_box_tests.cpp
 * @author Alexander Okrucký
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
                {5,-4,3},
                {-8,15,0},
                {23,-259, -26},
        });

        return matrixTmp;
    }

    Matrix createFiveSquaredMatrix() {
        Matrix matrixTmp = Matrix(5, 5);

        matrixTmp.set(std::vector<std::vector<double>> {
                {1, -2, 3, -4, 5},
                {-1, 2, -3, 4, -5},
                {1, -2, 3, -4, 5},
                {-1, 2, -3, 4, -5},
                {1, -2, 3, -4, 5}
        });

        return matrixTmp;
    }

    //----create-rectangle-matrix-----------------

    Matrix createRowVectorMatrix() {
        Matrix matrixTmp = Matrix(1,5);

        matrixTmp.set(std::vector<std::vector<double>> {
                {5,-4,3, -386, 2}
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
                {5, -33},
                {-4, 0},
                {3, 14}
        });

        return matrixTmp;
    }

    Matrix create2x3Matrix() {
        Matrix matrixTmp = Matrix(2,3);

        matrixTmp.set(std::vector<std::vector<double>>{
                {5, -33, 0},
                {-4, 600, -354}
        });

        return matrixTmp;
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
    ASSERT_DOUBLE_EQ(matrix.get(2,0),23);

    ASSERT_ANY_THROW(matrix.get(3,3));
    ASSERT_ANY_THROW(matrix.get(0,3));
    ASSERT_ANY_THROW(matrix.get(3,0));

}

TEST_F(WhiteBoxTest, MatrixEqual) {

    Matrix matrixRowVector = createRowVectorMatrix();
    Matrix matrixColVector = createColVectorMatrix();

    Matrix matrix3x3V1 = createTreeSquaredMatrix();

    Matrix matrix3x3V2 = createTreeSquaredMatrix();

    matrix3x3V2.set(0,0,0);

    ASSERT_ANY_THROW(matrixColVector==matrixRowVector);

    ASSERT_TRUE(matrix3x3V1==matrix3x3V1);

    ASSERT_FALSE(matrix3x3V1==matrix3x3V2);

}

TEST_F(WhiteBoxTest, MatrixAdd) {

    Matrix matrixRowVector = createRowVectorMatrix();
    Matrix matrixColVector = createColVectorMatrix();

    Matrix matrix3x3 = createTreeSquaredMatrix();

    Matrix expectedMatrix = Matrix(3,3);

    expectedMatrix.set(std::vector<std::vector<double>> {
            {10,-8,6},
            {-16,30,0},
            {46,-518,-52}
    });

    ASSERT_ANY_THROW(matrixColVector+matrixRowVector);

    ASSERT_EQ(matrix3x3+matrix3x3,expectedMatrix);

}

TEST_F(WhiteBoxTest, MatrixMultiplication) {

    Matrix matrix3x2 = create3x2Matrix();
    Matrix matrix2x3 = create2x3Matrix();

    Matrix matrixColVector = createColVectorMatrix();

    Matrix expectedMatrix = Matrix(2,2);
    Matrix resultMatrix = Matrix(2,2);

    expectedMatrix.set(std::vector<std::vector<double>> {
            {157, -165},
            {-3482, -4824}
    });

    resultMatrix = matrix2x3*matrix3x2;

    ASSERT_ANY_THROW(matrixColVector*matrix2x3);

    ASSERT_TRUE(resultMatrix==expectedMatrix);

}

TEST_F(WhiteBoxTest, MatrixNumberMultiplication) {

    Matrix matrix3x2 = create3x2Matrix();
    Matrix matrixRowVector = createRowVectorMatrix();
    Matrix matrix1x1W0 = createOneW0ValueSquaredMatrix();

    Matrix resultMatrix3x2 = Matrix(3,2);
    Matrix resultMatrixRowVector = Matrix(1,5);
    Matrix resultMatrix1x1W0 = Matrix(1,1);

    Matrix expectedMatrix3x2 = Matrix(3,2);
    Matrix expectedMatrixRowVector = Matrix(1,5);
    Matrix expectedMatrix1x1W0 = Matrix(1,1);

    expectedMatrix3x2.set(std::vector<std::vector<double>> {    // * 3
            {15, -99},
            {-12, 0},
            {9, 42}
    });

    expectedMatrixRowVector.set(std::vector<std::vector<double>> {  // * 2
            {10, -8, 6, -772, 4}
    });

    expectedMatrix1x1W0.set(std::vector<std::vector<double>> {
            {0}
    });

    resultMatrix3x2 = matrix3x2*3;
    resultMatrixRowVector = matrixRowVector*2;
    resultMatrix1x1W0 = matrix1x1W0*3.14;

    ASSERT_TRUE(resultMatrix3x2==expectedMatrix3x2);
    ASSERT_TRUE(resultMatrix1x1W0==expectedMatrix1x1W0);
    ASSERT_TRUE(resultMatrixRowVector==expectedMatrixRowVector);

}

TEST_F(WhiteBoxTest, TransposeMatrix) {

    Matrix matrix3x3 = createTreeSquaredMatrix();
    Matrix matrix3x2 = create3x2Matrix();
    Matrix matrix2x3 = create2x3Matrix();

    Matrix matrix3x3Result = Matrix(3,3);
    Matrix matrix3x2Result = Matrix(3,2);
    Matrix matrix2x3Result = Matrix(2,3);

    matrix3x3Result.set(std::vector<std::vector<double>> {
            {5, -8, 23},
            {-4, 15, -259},
            {3, 0, -26},
    });

    matrix3x2Result.set(std::vector<std::vector<double>> {
            {5, -4},
            {-33, 600},
            {0, -354}
    });

    matrix2x3Result.set(std::vector<std::vector<double>> {
            {5, -4, 3},
            {-33, 0, 14}
    });

    ASSERT_TRUE(matrix3x3.transpose()==matrix3x3Result);
    ASSERT_TRUE(matrix3x2.transpose()==matrix2x3Result);
    ASSERT_TRUE(matrix2x3.transpose()==matrix3x2Result);


}

TEST_F(WhiteBoxTest, InverseMatrix) {

    Matrix matrix3x3 = createTreeSquaredMatrix();
    Matrix matrix2x3 = create2x3Matrix();
    Matrix matrix5x5 = createFiveSquaredMatrix();

    Matrix matrix3x3Result = Matrix(3,3);

    matrix3x3.set(std::vector<std::vector<double>> {
            {1, 1, 1},
            {6, 5, 4},
            {13, 10, 8},
    });

    matrix3x3Result.set(std::vector<std::vector<double>> {
            {0, -2, 1},
            {-4, 5, -2},
            {5, -3, 1},
    });


    ASSERT_TRUE(matrix3x3.inverse()==matrix3x3Result);
    ASSERT_ANY_THROW(matrix2x3.inverse());
    ASSERT_ANY_THROW(matrix5x5.inverse());

}

TEST_F(WhiteBoxTest, SolveEquation) {

    Matrix matrix3x3 = createTreeSquaredMatrix();

    Matrix rowVector = createRowVectorMatrix();
    Matrix colVector = createColVectorMatrix();

    ASSERT_ANY_THROW(matrix3x3.solveEquation(std::vector<double> {0}));
    ASSERT_ANY_THROW(matrix3x3.solveEquation(std::vector<double> {0,1}));
    ASSERT_ANY_THROW(matrix3x3.solveEquation(std::vector<double> {}));

    ASSERT_ANY_THROW(rowVector.solveEquation(std::vector<double> {1}));
    ASSERT_ANY_THROW(colVector.solveEquation(std::vector<double> {1, 2, 3, 4, 5}));

    Matrix matrix2x2 = Matrix(2,2);

    matrix2x2.set(std::vector<std::vector<double>> {
            {5, 2},
            {5, 2}
    });

    ASSERT_ANY_THROW(matrix2x2.solveEquation(std::vector<double> {5,2}));
    ASSERT_ANY_THROW(rowVector.solveEquation(std::vector<double> {5}));
    ASSERT_ANY_THROW(colVector.solveEquation(std::vector<double> {5,2,1,0,4}));

    ///calculations-------

    matrix2x2.set(std::vector<std::vector<double>> {
            {2,4},
            {4,2}
    });


    ASSERT_TRUE(matrix2x2.solveEquation(std::vector<double> {2, 4})==(std::vector<double> {1, 0}));

    matrix3x3.set(std::vector<std::vector<double>> {
            {2,3,1},
            {1,2,-1},
            {2,1,1},
    });

    std::vector<double> result = matrix3x3.solveEquation(std::vector<double> {0, 3, 12});

    ASSERT_TRUE(matrix3x3.solveEquation(std::vector<double> {0, 3, 12})==(std::vector<double> {11, -6, -4}));

}

/*** Konec souboru white_box_tests.cpp ***/
