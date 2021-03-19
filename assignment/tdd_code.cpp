//======== Copyright (c) 2021, FIT VUT Brno, All rights reserved. ============//
//
// Purpose:     Test Driven Development - priority queue code
//
// $NoKeywords: $ivs_project_1 $tdd_code.cpp
// $Author:     ALEXANDER OKRUCKÝ <xokruc00@stud.fit.vutbr.cz>
// $Date:       $2021-03-17
//============================================================================//
/**
 * @file tdd_code.cpp
 * @author Alexander Okrucký
 * 
 * @brief Implementace metod tridy prioritni fronty.
 */

#include <stdlib.h>
#include <stdio.h>
#include <iostream>

#include "tdd_code.h"

//============================================================================//
// ** ZDE DOPLNTE IMPLEMENTACI **
//
// Zde doplnte implementaci verejneho rozhrani prioritni fronty (Priority Queue)
// 1. Verejne rozhrani fronty specifikovane v: tdd_code.h (sekce "public:")
//    - Konstruktor (PriorityQueue()), Destruktor (~PriorityQueue())
//    - Metody Insert/Remove/Find a GetHead
//    - Pripadne vase metody definovane v tdd_code.h (sekce "protected:")
//
// Cilem je dosahnout plne funkcni implementace prioritni fronty implementovane
// pomoci tzv. "double-linked list", ktera bude splnovat dodane testy 
// (tdd_tests.cpp).
//============================================================================//

PriorityQueue::PriorityQueue()
{
    m_pHead = nullptr;
}

PriorityQueue::~PriorityQueue()
{
    Element_t *element = GetHead();

    while (element != nullptr) {
        Element_t *elementTmp = element;
        element = element->pNext;

        delete elementTmp;
    }

    delete element;
}

void PriorityQueue::Insert(int value)
{
    if (m_pHead == nullptr) { //ak je Head null

        m_pHead = new Element_t {
                .pNext = nullptr,
                .value = value
        };
        return;

    } if (m_pHead->pNext == nullptr) { // ak je Head jediný prvok
        if (m_pHead->value <= value) {

            Element_t *elementTmp = new Element_t {
                .pNext = nullptr,
                .value = m_pHead->value
            };

            m_pHead = new Element_t {
                .pNext = elementTmp,
                .value = value
            };
            return;
        }
    } else { //ostatné pripady

        Element_t *element = GetHead();

        while (element != nullptr) {
            if (m_pHead->value <= value) {
                Element_t *e = new Element_t {
                    .pNext = m_pHead->pNext,
                    .value = m_pHead->value
                };

                m_pHead = new Element_t {
                        .pNext = e,
                        .value = value
                };
                return;
            }

            if (element->pNext != nullptr) {
                if (element->pNext->value <= value) { //ak dalsia hodnota je mensia ako Value tak insertnem Element
                    Element_t *elementTmp = element->pNext;

                    element->pNext = new Element_t {
                        .pNext = elementTmp,
                        .value = value
                    };
                    return;
                }
            } else {
                element->pNext = new Element_t {
                    .pNext = nullptr,
                    .value = value
                };
                return;
            }

            element = element->pNext;
        }

    }

}

bool PriorityQueue::Remove(int value)
{
    Element_t *element = GetHead();

    if (element == nullptr) {
        return false;
    } else if(element->value == value) {
        m_pHead = element->pNext;

        delete element;

        return true;

    } else {

        while (element != nullptr) {

            if (element->pNext != nullptr) {

                if (element->pNext->value == value) {
                    Element_t *elementDelete = element->pNext;

                    element->pNext = element->pNext->pNext;

                    delete elementDelete;

                    return true;

                }

            }

            element = element->pNext;
        }

    }

    return false;
}

PriorityQueue::Element_t *PriorityQueue::Find(int value)
{

    Element_t *element = GetHead();

    while (element != nullptr) {

        if (element->value == value) {
            return element;
        }

        element = element->pNext;
    }

    return nullptr;
}

size_t PriorityQueue::Length()
{
    Element_t *element = GetHead();
    int counter = 0;

    while (element != nullptr) {
        counter++;
        element = element->pNext;
    }

	return counter;
}

PriorityQueue::Element_t *PriorityQueue::GetHead()
{
    return m_pHead;
}

/*** Konec souboru tdd_code.cpp ***/
