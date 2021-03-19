//======== Copyright (c) 2017, FIT VUT Brno, All rights reserved. ============//
//
// Purpose:     Red-Black Tree - public interface tests
//
// $NoKeywords: $ivs_project_1 $black_box_tests.cpp
// $Author:     ALEXANDER OKRUCKÝ <xokruc00@stud.fit.vutbr.cz>
// $Date:       $2021-03-17
//============================================================================//
/**
 * @file black_box_tests.cpp
 * @author Alexander Okrucký
 * 
 * @brief Implementace testu binarniho stromu.
 */

#include <vector>

#include "gtest/gtest.h"

#include "red_black_tree.h"

//============================================================================//
// ** ZDE DOPLNTE TESTY **
//
// Zde doplnte testy Red-Black Tree, testujte nasledujici:
// 1. Verejne rozhrani stromu
//    - InsertNode/DeleteNode a FindNode
//    - Chovani techto metod testuje pro prazdny i neprazdny strom.
// 2. Axiomy (tedy vzdy platne vlastnosti) Red-Black Tree:
//    - Vsechny listove uzly stromu jsou *VZDY* cerne.
//    - Kazdy cerveny uzel muze mit *POUZE* cerne potomky.
//    - Vsechny cesty od kazdeho listoveho uzlu ke koreni stromu obsahuji
//      *STEJNY* pocet cernych uzlu.
//============================================================================//


    class NonEmptyTree : public ::testing::Test{

    protected:
        BinaryTree binaryTree;
        int numberNodes = 11;
        int nodes[11] = {6,2,9,5,6,1,10,18,11,21,13};

        int numberLeafNodes = 10;
        int leafNodeParents [5] = {2,6,10,13,18};


        void SetUp() {
            for (int i=0; i<11; i++ ) {
                binaryTree.InsertNode(nodes[i]);
            }
        }
    };

    class EmptyTree : public ::testing::Test {
    protected:
        BinaryTree binaryTree;
    };

    class TreeAxioms : public ::testing::Test {
    protected:
        BinaryTree binaryTree;
    };

    TEST_F(EmptyTree, Insert) {

        ///Insert first pair
        std::pair<bool, BinaryTree::Node_t *> firstPair = binaryTree.InsertNode(2);

        BinaryTree::Node_t *firstNode = firstPair.second;
        EXPECT_TRUE(firstPair.first);
        ASSERT_TRUE(firstNode != nullptr);

        EXPECT_EQ(firstNode->key, 2);
        EXPECT_EQ(firstNode->color, BinaryTree::BLACK);

        EXPECT_TRUE(firstNode->pParent == nullptr);

        /// first right Node Tests
        BinaryTree::Node_t *firstRightNode = firstNode->pRight;

        ASSERT_TRUE(firstRightNode != nullptr);
        EXPECT_TRUE(firstRightNode->color == BinaryTree::BLACK);

        EXPECT_TRUE(firstRightNode->pRight == nullptr);
        EXPECT_TRUE(firstRightNode->pLeft == nullptr);
        EXPECT_TRUE(firstRightNode->pParent != nullptr);

        ///first left Node Tests
        BinaryTree::Node_t *firstLeftNode = firstNode->pLeft;

        ASSERT_TRUE(firstLeftNode != nullptr);
        EXPECT_TRUE(firstLeftNode->color == BinaryTree::BLACK);

        EXPECT_TRUE(firstLeftNode->pRight == nullptr);
        EXPECT_TRUE(firstLeftNode->pLeft == nullptr);
        EXPECT_TRUE(firstLeftNode->pParent != nullptr);

        ///Insert next pair
        std::pair<bool, BinaryTree::Node_t *> secondPair = binaryTree.InsertNode(4);

        BinaryTree::Node_t *secondNode = secondPair.second;
        EXPECT_TRUE(firstPair.first);
        ASSERT_TRUE(secondNode != nullptr);

        EXPECT_EQ(secondNode->key, 4);
        EXPECT_EQ(secondNode->color, BinaryTree::RED);

        EXPECT_FALSE(secondNode->pParent == nullptr);
        EXPECT_EQ(secondNode->pParent->key, 2);
        EXPECT_EQ(secondNode->pParent->color, BinaryTree::BLACK);

        ///second right node tests
        BinaryTree::Node_t *secondRightNode = secondNode->pRight;

        ASSERT_TRUE(secondRightNode != nullptr);
        EXPECT_TRUE(secondRightNode->color == BinaryTree::BLACK);

        EXPECT_TRUE(secondRightNode->pRight == nullptr);
        EXPECT_TRUE(secondRightNode->pLeft == nullptr);
        EXPECT_TRUE(secondRightNode->pParent != nullptr);
        EXPECT_TRUE(secondRightNode->pParent->key == 4);
        EXPECT_TRUE(secondRightNode->pParent->color == BinaryTree::RED);

        ///second left Node Tests
        BinaryTree::Node_t *secondLeftNode = secondNode->pLeft;

        ASSERT_TRUE(secondLeftNode != nullptr);
        EXPECT_TRUE(secondLeftNode->color == BinaryTree::BLACK);

        EXPECT_TRUE(secondLeftNode->pRight == nullptr);
        EXPECT_TRUE(secondLeftNode->pLeft == nullptr);
        EXPECT_TRUE(secondLeftNode->pParent != nullptr);
        EXPECT_TRUE(secondRightNode->pParent->key == 4);
        EXPECT_TRUE(secondRightNode->pParent->color == BinaryTree::RED);

        ///insert existing node
        std::pair<bool, BinaryTree::Node_t *> existingPair = binaryTree.InsertNode(4);

        BinaryTree::Node_t *existingNode = existingPair.second;
        EXPECT_FALSE(existingPair.first);
        ASSERT_TRUE(existingNode != nullptr);

        EXPECT_EQ(existingNode->key, 4);
        EXPECT_EQ(existingNode->color, BinaryTree::RED);

        ///insert node with negative value
        std::pair<bool, BinaryTree::Node_t *> negativePair = binaryTree.InsertNode(-3);

        BinaryTree::Node_t *negativeNode = negativePair.second;
        EXPECT_TRUE(negativePair.first);
        ASSERT_TRUE(secondNode != nullptr);

        EXPECT_EQ(negativeNode->key, -3);
        EXPECT_EQ(negativeNode->color, BinaryTree::RED);

        EXPECT_FALSE(negativeNode->pParent == nullptr);
        EXPECT_EQ(negativeNode->pParent->key, 2);
        EXPECT_EQ(negativeNode->pParent->color, BinaryTree::BLACK);

        ///insert node with zero value
        std::pair<bool, BinaryTree::Node_t *> zeroPair = binaryTree.InsertNode(0);

        BinaryTree::Node_t *zeroNode = zeroPair.second;
        EXPECT_TRUE(zeroPair.first);
        ASSERT_TRUE(zeroNode != nullptr);

        EXPECT_EQ(zeroNode->key, 0);
        EXPECT_EQ(zeroNode->color, BinaryTree::RED);

        EXPECT_FALSE(zeroNode->pParent == nullptr);
        EXPECT_EQ(zeroNode->pParent->key, -3);
        EXPECT_EQ(zeroNode->pParent->color, BinaryTree::BLACK);

    }

    TEST_F(EmptyTree, Delete) {
        EXPECT_FALSE(binaryTree.DeleteNode(0));
    }

    TEST_F(EmptyTree, Find) {
        EXPECT_TRUE(binaryTree.FindNode(0) == nullptr);
    }

    TEST_F(NonEmptyTree, Insert) {

        ///existing pair test
        std::pair<bool, BinaryTree::Node_t *> existingPair = binaryTree.InsertNode(6);

        BinaryTree::Node_t *existingNode = existingPair.second;

        EXPECT_FALSE(existingPair.first);
        ASSERT_TRUE(existingNode != nullptr);

        EXPECT_FALSE(existingNode->pParent == nullptr);
        EXPECT_TRUE(existingNode->pParent->key == 10);
        EXPECT_TRUE(existingNode->pParent->color == BinaryTree::BLACK);

        EXPECT_TRUE(existingNode->key == 6);
        EXPECT_TRUE(existingNode->color == BinaryTree::RED);

        ///existing right node test
        ASSERT_TRUE(existingNode->pRight != nullptr);
        ASSERT_TRUE(existingNode->pRight->key == 9);

        ///existing left node test
        ASSERT_TRUE(existingNode->pLeft != nullptr);
        ASSERT_TRUE(existingNode->pLeft->key == 2);

        ///inserting new pair
        std::pair<bool, BinaryTree::Node_t *> newPair = binaryTree.InsertNode(12);

        BinaryTree::Node_t *newNode = newPair.second;

        EXPECT_TRUE(newPair.first);
        ASSERT_TRUE(newNode != nullptr);

        EXPECT_TRUE(newNode->key == 12);
        EXPECT_TRUE(newNode->color == BinaryTree::BLACK);

        ASSERT_TRUE(newNode->pParent != nullptr);
        EXPECT_TRUE(newNode->pParent->key == 18);
        EXPECT_TRUE(newNode->pParent->color == BinaryTree::RED);


        EXPECT_TRUE(newNode->pRight != nullptr);
        EXPECT_TRUE(newNode->pLeft != nullptr);
    }

    TEST_F(NonEmptyTree, Delete) {
        EXPECT_TRUE(binaryTree.DeleteNode(1));
        EXPECT_FALSE(binaryTree.DeleteNode(1));

        EXPECT_FALSE(binaryTree.DeleteNode(-20));
    }

    TEST_F(NonEmptyTree, Find) {
        EXPECT_TRUE(binaryTree.FindNode(1) != nullptr);

        EXPECT_TRUE(binaryTree.FindNode(-20) == nullptr);
    }

    TEST_F(TreeAxioms, Axiom1) {
        std::vector<BinaryTree::Node_t *> nodes;

        binaryTree.GetLeafNodes(nodes);

        for (auto node : nodes) {
            ASSERT_TRUE(node != nullptr);
            ASSERT_TRUE(node->color == BinaryTree::BLACK);
        }

    }

    TEST_F(TreeAxioms, Axiom2) {
        std::vector<BinaryTree::Node_t *> nodes;

        binaryTree.GetNonLeafNodes(nodes);

        for (auto node : nodes) {
            ASSERT_TRUE(node != nullptr);
            if (node->color == BinaryTree::RED) {
                EXPECT_TRUE(node->pRight->color == BinaryTree::BLACK);
                EXPECT_TRUE(node->pLeft->color == BinaryTree::BLACK);
            }
        }
    }

    TEST_F(TreeAxioms, Axiom3) {
        Node_t *root;
        std::vector<BinaryTree::Node_t *> nodes;
        std::vector<BinaryTree::Node_t *> nonLeafNodes;

        binaryTree.GetLeafNodes(nodes);
        binaryTree.GetNonLeafNodes(nonLeafNodes);
        root = binaryTree.GetRoot();
        int counter = 0;
        int counterMAX = 0;

        for (auto node : nonLeafNodes) {
            if (node->color == BinaryTree::BLACK) {
                counterMAX++;
            }
        }

        for (auto node : nodes) {
            counter = 0;
            while (node != root) {
                node = node->pParent;
                if (node->color == BinaryTree::BLACK) {
                    counter++;
                }
            }

            ASSERT_TRUE(counter == counterMAX);
        }
    }


/*** Konec souboru black_box_tests.cpp ***/
