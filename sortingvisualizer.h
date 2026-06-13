#ifndef SORTINGVISUALIZER_H
#define SORTINGVISUALIZER_H

#include <QObject>
#include <vector>

class SortingVisualizer : public QObject
{
    Q_OBJECT

public:
    explicit SortingVisualizer(QObject *parent = nullptr);

    void generateArray(int size);

    std::vector<int>& getArray();

    int comparisons;
    int swaps;

signals:
    void arrayUpdated();
    void sortingFinished();

private:
    std::vector<int> arr;
};

#endif