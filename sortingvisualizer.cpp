#include "sortingvisualizer.h"

#include <QRandomGenerator>

SortingVisualizer::SortingVisualizer(QObject *parent)
    : QObject(parent)
{
    comparisons = 0;
    swaps = 0;
}

void SortingVisualizer::generateArray(int size)
{
    arr.clear();

    for(int i = 0; i < size; i++)
    {
        arr.push_back(
            QRandomGenerator::global()->bounded(50,350)
            );
    }

    emit arrayUpdated();
}

std::vector<int>& SortingVisualizer::getArray()
{
    return arr;
}