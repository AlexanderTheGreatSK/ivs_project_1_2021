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
        Matrix matrixTmp = Matrix(3,3);

        matrixTmp.set(std::vector<std::vector<double>> {
                {5,-4,3.14},
                {-8.16,15,0},
                {23.33,-259,02,-26},
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

TEST_F(WhiteBoxTest, MatrixCreate) {

///test správnosti

//vytvorenie Matice(1,1)
EXPECT_NO_THROW(Matrix());

EXPECT_NO_THROW(Matrix(1,1));


EXPECT_ANY_THROW(Matrix(0,1));
EXPECT_ANY_THROW(Matrix(0,0));
EXPECT_ANY_THROW(Matrix(1,0));

}




/*** Konec souboru white_box_tests.cpp ***/
